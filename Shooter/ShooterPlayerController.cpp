// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "Blueprint//UserWidget.h"

AShooterPlayerController::AShooterPlayerController()
{

}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Check our HUDOverlayClass TSubclassOf variable
	if (HUDOverlayClass)
	{
		// CreateWidget 함수는 HUDOverlayClass에 지정된 블루프린트 클래스를 사용하여 새로운 위젯을 생성한다.
		// 그리고 생성된 위젯의 인스턴스(의 포인터)를 HUDOverlay에 할당한다.
		HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayClass);
		if (HUDOverlay)
		{
			HUDOverlay->AddToViewport();
			HUDOverlay->SetVisibility(ESlateVisibility::Visible);
		}
	}
}