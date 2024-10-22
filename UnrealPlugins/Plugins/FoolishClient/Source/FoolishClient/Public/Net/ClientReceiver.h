// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Net/SocketReceiver.h"
#include "ClientReceiver.generated.h"

/**
 * 
 */
UCLASS()
class FOOLISHCLIENT_API UClientReceiver : public USocketReceiver
{
	GENERATED_BODY()
protected:
	/** 关闭操作 */
	virtual void Close(UFSocket* InSocket, EOpCode OpCode) override;
};
