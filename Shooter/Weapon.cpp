// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

AWeapon::AWeapon() :
	ThrowWeaponTime(0.7f),
	bFalling(false),
	Ammo(30),
	MagazineCapacity(30),
	WeaponType(EWeaponType::EWT_SubmachineGun),
	AmmoType(EAmmoType::EAT_9mm),
	ReloadMontageSection(FName(TEXT("Reload SMG"))),
	ClipBoneName(TEXT("smg_clip"))
{
	PrimaryActorTick.bCanEverTick = true;
}


void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Keep the Weapon upright. 무기를 수직으로 유지.
	if (GetItemState() == EItemState::EIS_Falling && bFalling)
	{
		const FRotator MeshRotation{ 0.f, GetItemMesh()->GetComponentRotation().Yaw, 0.f }; // Yaw 는 수평 회전값이며, Pitch와 Roll 회전값을 0으로 설정.
		GetItemMesh()->SetWorldRotation(MeshRotation, false, nullptr, ETeleportType::TeleportPhysics); 
		//무기를 던질 때 메시의 회전이 즉시 변경되도록 하고, 물리 시뮬레이션을 재설정하지 않고 메시를 이동시킵니다. 
		// 이를 통해 무기가 부드럽게 회전하면서도 다른 객체와의 충돌을 일으키지 않게 됩니다.
	}
}

void AWeapon::ThrowWeapon()
{
	FRotator MeshRotation{ 0.f, GetItemMesh()->GetComponentRotation().Yaw, 0.f }; // Yaw 회전값을 유지하여 메시를 수직으로 유지
	GetItemMesh()->SetWorldRotation(MeshRotation, false, nullptr, ETeleportType::TeleportPhysics);

	const FVector MeshForward{ GetItemMesh()->GetForwardVector() }; // 메시의 전방 벡터
	const FVector MeshRight{ GetItemMesh()->GetRightVector() }; // 메시의 오른쪽 벡터
	// Direction in which we throw the Weapon
	FVector ImpulseDirection = MeshRight.RotateAngleAxis(-20.f, MeshForward); // 메시의 전방 벡터를 기준으로 오른쪽으로 20도 회전한 방향벡터.

	float RandomRotation{ 30.f };
	ImpulseDirection = ImpulseDirection.RotateAngleAxis(RandomRotation, FVector(0.f, 0.f, 1.f)); // 랜덤 값을 이용하여 회전
	ImpulseDirection *= 20'000.f; // 던질 힘을 설정
	GetItemMesh()->AddImpulse(ImpulseDirection); // 메시에 힘을 가한다.

	bFalling = true;
	GetWorldTimerManager().SetTimer(ThrowWeaponTimer, this, &AWeapon::StopFalling, ThrowWeaponTime);
	//일정 시간(ThrowWeaponTime)이 지난 후 StopFalling 함수를 호출하도록 타이머를 설정
}

void AWeapon::StopFalling()
{
	bFalling = false;
	SetItemState(EItemState::EIS_Pickup); // 무기의 상태를 "픽업 가능" 상태로 설정
}

void AWeapon::DecrementAmmo()
{
	if (Ammo - 1 <= 0)
	{
		Ammo = 0; // We never fo negative.
	}
	else
	{
		--Ammo;
	}
}

void AWeapon::ReloadAmmo(int32 Amount)
{
	checkf(Ammo + Amount <= MagazineCapacity, TEXT("Attempted to reload with more than magazine capacity!"));
	Ammo += Amount;
}