// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	/** Constructor */
	AShooterPlayerController(); 
	
protected:
	
	virtual void BeginPlay() override;

private:
	/** 
	* We already have BPAmmoCount, But we created ShooterHUDOverlay to have a canvas panel
	* that we can add other Widgets to fore the game.
	* Reference to the Overall HUD Overlay Bluprint Class. 
	* It's a C++ Variable that will hold a blueprint. 
	* HUDOverlayClass holds the Blueprint. 
	* HUDOverlay holds the actual instance we create using CreateWidget.
	* CreateWidget used HUDOverlayClass when creating a new Widget.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UUserWidget> HUDOverlayClass; 

	/**Variable to holds the HUD Overlay Widget after creating it */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Widgets, meta = (AllowPrivateAccess = "true"))
	UUserWidget* HUDOverlay;
};
