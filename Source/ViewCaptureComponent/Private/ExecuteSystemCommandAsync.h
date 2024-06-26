// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "ExecuteSystemCommandAsync.generated.h"

/**
 * Execute system(shell) command class
 */
UCLASS()
class UExecuteSystemCommandAsync: public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	// Execute system(shell) command asynchronously.
	UFUNCTION(BlueprintCallable)
	static void ExecuteSystemCommandAsync(const FString& Command);
};
