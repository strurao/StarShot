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
		// CreateWidget �Լ��� HUDOverlayClass�� ������ �������Ʈ Ŭ������ ����Ͽ� ���ο� ������ �����Ѵ�.
		// �׸��� ������ ������ �ν��Ͻ�(�� ������)�� HUDOverlay�� �Ҵ��Ѵ�.
		HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayClass);
		if (HUDOverlay)
		{
			HUDOverlay->AddToViewport();
			HUDOverlay->SetVisibility(ESlateVisibility::Visible);
		}
	}
}