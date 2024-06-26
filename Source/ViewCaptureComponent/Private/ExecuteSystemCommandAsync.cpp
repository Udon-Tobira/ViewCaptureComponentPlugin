// Fill out your copyright notice in the Description page of Project Settings.

#include "ExecuteSystemCommandAsync.h"

#include "AsyncExecTask.h"

void UExecuteSystemCommandAsync::ExecuteSystemCommandAsync(
    const FString& Command) {
	auto AsyncExecTask = new FAutoDeleteAsyncTask<FAsyncExecTask>(
	    [Command]() { std::system(TCHAR_TO_ANSI(*Command)); });
	AsyncExecTask->StartBackgroundTask();
}
