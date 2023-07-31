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

	// Keep the Weapon upright. ���⸦ �������� ����.
	if (GetItemState() == EItemState::EIS_Falling && bFalling)
	{
		const FRotator MeshRotation{ 0.f, GetItemMesh()->GetComponentRotation().Yaw, 0.f }; // Yaw �� ���� ȸ�����̸�, Pitch�� Roll ȸ������ 0���� ����.
		GetItemMesh()->SetWorldRotation(MeshRotation, false, nullptr, ETeleportType::TeleportPhysics); 
		//���⸦ ���� �� �޽��� ȸ���� ��� ����ǵ��� �ϰ�, ���� �ùķ��̼��� �缳������ �ʰ� �޽ø� �̵���ŵ�ϴ�. 
		// �̸� ���� ���Ⱑ �ε巴�� ȸ���ϸ鼭�� �ٸ� ��ü���� �浹�� ����Ű�� �ʰ� �˴ϴ�.
	}
}

void AWeapon::ThrowWeapon()
{
	FRotator MeshRotation{ 0.f, GetItemMesh()->GetComponentRotation().Yaw, 0.f }; // Yaw ȸ������ �����Ͽ� �޽ø� �������� ����
	GetItemMesh()->SetWorldRotation(MeshRotation, false, nullptr, ETeleportType::TeleportPhysics);

	const FVector MeshForward{ GetItemMesh()->GetForwardVector() }; // �޽��� ���� ����
	const FVector MeshRight{ GetItemMesh()->GetRightVector() }; // �޽��� ������ ����
	// Direction in which we throw the Weapon
	FVector ImpulseDirection = MeshRight.RotateAngleAxis(-20.f, MeshForward); // �޽��� ���� ���͸� �������� ���������� 20�� ȸ���� ���⺤��.

	float RandomRotation{ 30.f };
	ImpulseDirection = ImpulseDirection.RotateAngleAxis(RandomRotation, FVector(0.f, 0.f, 1.f)); // ���� ���� �̿��Ͽ� ȸ��
	ImpulseDirection *= 20'000.f; // ���� ���� ����
	GetItemMesh()->AddImpulse(ImpulseDirection); // �޽ÿ� ���� ���Ѵ�.

	bFalling = true;
	GetWorldTimerManager().SetTimer(ThrowWeaponTimer, this, &AWeapon::StopFalling, ThrowWeaponTime);
	//���� �ð�(ThrowWeaponTime)�� ���� �� StopFalling �Լ��� ȣ���ϵ��� Ÿ�̸Ӹ� ����
}

void AWeapon::StopFalling()
{
	bFalling = false;
	SetItemState(EItemState::EIS_Pickup); // ������ ���¸� "�Ⱦ� ����" ���·� ����
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