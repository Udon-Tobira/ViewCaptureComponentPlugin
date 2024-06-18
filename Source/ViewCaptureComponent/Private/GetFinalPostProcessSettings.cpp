// Fill out your copyright notice in the Description page of Project Settings.

#include "GetFinalPostProcessSettings.h"

FPostProcessSettings UGetFinalPostProcessSettings::GetFinalPostProcessSettings(
    const APlayerController* PlayerController) {
	check(PlayerController != nullptr);

	// Get World
	const auto World = PlayerController->GetWorld();
	check(World != nullptr);

	// Get Local Player
	const auto LocalPlayer = PlayerController->GetLocalPlayer();
	check(LocalPlayer != nullptr);

	// Create ViewFamily
	FSceneViewFamilyContext ViewFamily(
	    FSceneViewFamily::ConstructionValues(
	        LocalPlayer->ViewportClient->Viewport, World->Scene,
	        LocalPlayer->ViewportClient->EngineShowFlags)
	        .SetRealtimeUpdate(true));

	// Create SceneView
	FVector    ViewLocation;
	FRotator   ViewRotation;
	const auto SceneView = LocalPlayer->CalcSceneView(
	    &ViewFamily, /*out*/ ViewLocation, /*out*/ ViewRotation,
	    LocalPlayer->ViewportClient->Viewport);
	check(SceneView != nullptr);

	// return FinalPostProcessSettings
	return SceneView->FinalPostProcessSettings;
}
