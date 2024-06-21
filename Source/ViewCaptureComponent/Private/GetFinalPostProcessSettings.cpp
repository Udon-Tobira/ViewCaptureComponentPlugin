// Fill out your copyright notice in the Description page of Project Settings.

#include "GetFinalPostProcessSettings.h"

void UGetFinalPostProcessSettings::GetFinalPostProcessSettings(
    const APlayerController*            PlayerController,
    EGetFinalPostProcessSettingsResult& Result,
    FPostProcessSettings&               PostProcessSettings) {
	if (nullptr == PlayerController) {
		Result = EGetFinalPostProcessSettingsResult::Failure;
		return;
	}

	// Get World
	const auto World = PlayerController->GetWorld();
	if (nullptr == World) {
		Result = EGetFinalPostProcessSettingsResult::Failure;
		return;
	}

	// Get Local Player
	const auto LocalPlayer = PlayerController->GetLocalPlayer();
	if (nullptr == LocalPlayer) {
		Result = EGetFinalPostProcessSettingsResult::Failure;
		return;
	}

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
	if (nullptr == SceneView) {
		Result = EGetFinalPostProcessSettingsResult::Failure;
		return;
	}

	// set result
	PostProcessSettings = SceneView->FinalPostProcessSettings;
	Result              = EGetFinalPostProcessSettingsResult::Success;
}
