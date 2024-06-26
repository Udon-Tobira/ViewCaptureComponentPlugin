// Fill out your copyright notice in the Description page of Project Settings.

#include "ExecuteSystemCommand.h"

#include "AsyncExecTask.h"

void UExecuteSystemCommand::ExecuteSystemCommand(const FString& Command) {
	auto AsyncExecTask = new FAutoDeleteAsyncTask<FAsyncExecTask>(
	    [Command]() { std::system(TCHAR_TO_ANSI(*Command)); });
	AsyncExecTask->StartBackgroundTask();
}
