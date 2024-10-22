// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Net/SocketSender.h"
#include "UdpClientSender.generated.h"

/**
 * 
 */
UCLASS()
class FOOLISHCLIENT_API UUdpClientSender final : public USocketSender
{
	GENERATED_BODY()

protected:
	/** 数据发送的实现 */
	virtual void TrySendAsync(UFSocket* InSocket, const TArray<uint8>& Buffer) override;
};
