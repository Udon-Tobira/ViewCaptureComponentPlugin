// Fill out your copyright notice in the Description page of Project Settings.

#include "ExecuteSystemCommand.h"

void UExecuteSystemCommand::ExecuteSystemCommand(const FString& Command) {
	std::system(TCHAR_TO_ANSI(*Command));
}
