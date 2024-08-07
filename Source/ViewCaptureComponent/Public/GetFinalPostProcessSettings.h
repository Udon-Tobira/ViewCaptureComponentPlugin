// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "GetFinalPostProcessSettings.generated.h"

/**
 *
 */
UENUM()
enum class EGetFinalPostProcessSettingsResult : uint8 { Success, Failure };

/**
 * Class for getting viewport's Final Post Process Settings.
 */
UCLASS()
class UGetFinalPostProcessSettings: public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	/**
	 * Get viewport's Final Post Process Settings.
	 */
	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "Result"))
	static void
	    GetFinalPostProcessSettings(const APlayerController* PlayerController,
	                                EGetFinalPostProcessSettingsResult& Result,
	                                FPostProcessSettings& PostProcessSettings);
};
