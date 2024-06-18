// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "ExecuteSystemCommand.generated.h"

/**
 * Execute system(shell) command class
 */
UCLASS()
class UExecuteSystemCommand: public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	// Execute system(shell) command
	UFUNCTION(BlueprintCallable)
	static void ExecuteSystemCommand(const FString& Command);
};
