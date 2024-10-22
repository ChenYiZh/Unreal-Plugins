﻿/****************************************************************************
THIS FILE IS PART OF Foolish Server PROJECT
THIS PROGRAM IS FREE SOFTWARE, IS LICENSED UNDER MIT

Copyright (c) 2022-2030 ChenYiZh
https://space.bilibili.com/9308172

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
****************************************************************************/


#include "Net/SocketSender.h"

#include "Sockets.h"
#include "Common/ByteUtil.h"
#include "Common/FPackageFactory.h"
#include "Log/FConsole.h"
#include "Log/FoolishClientCategories.h"
#include "Net/UserToken.h"

UFSocket* USocketSender::GetSocket() const
{
	return Socket.Get();
}

void USocketSender::Push(UFSocket* InSocket, const TArray<uint8>& Msg, bool bImmediate)
{
	InSocket->GetUserToken()->Push(Msg, bImmediate);
}

void USocketSender::ProcessSend(UFSocket* InSocket)
{
	if (InSocket == nullptr)
	{
		Socket->OperationCompleted();
		return;
	}
	UUserToken* UserToken = Socket->GetUserToken();
	if (UserToken->SendingBuffer.IsEmpty())
	{
		SendCompleted(InSocket);
		return;
	}

	int32 Size = UserToken->SendingBuffer.Num();

	FSocket* FSocket = InSocket->GetSocket();
	//int32 BytesSent;
	//FScopeLock Lock(&Socket->Mutex);
	int32 ArgsCount;
	FSocket->SetSendBufferSize(Size, ArgsCount);
	TArray<uint8> ArgsBuffer;
	if (ArgsCount >= Size - UserToken->SentCount)
	{
		int32 Length = Size - UserToken->SentCount;
		ArgsBuffer.SetNumUninitialized(Length);
		UByteUtil::BlockCopy(UserToken->SendingBuffer.GetData(), UserToken->SentCount, ArgsBuffer, 0, Length);
		UserToken->Reset();
	}
	else
	{
		ArgsBuffer.SetNumUninitialized(ArgsCount);
		UByteUtil::BlockCopy(UserToken->SendingBuffer.GetData(), UserToken->SentCount, ArgsBuffer, 0, ArgsCount);
		UserToken->SentCount += ArgsCount;
	}

	if (Socket == nullptr || Socket->GetSocket() == nullptr)
	{
		Socket->OperationCompleted();
		return;
	}

	TrySendAsync(InSocket, ArgsBuffer);
}

void USocketSender::PostSend(UFSocket* InSocket)
{
	UUserToken* UserToken = InSocket->GetUserToken();
	if (UserToken == nullptr)
	{
		InSocket->OperationCompleted();
		return;
	}

	//没有消息就退出
	if (InSocket->TrySend())
	{
		TArray<uint8> Msg;
		if (UserToken->TryDequeueMsg(Msg))
		{
			UserToken->SendingBuffer = Msg;
			UserToken->SentCount = 0;
			ProcessSend(InSocket);
		}
		else
		{
			InSocket->NextStep(InSocket);
		}
	}
}

void USocketSender::SendCompleted(UFSocket* InSocket)
{
	int32 NewLength;
	InSocket->GetSocket()->SetSendBufferSize(InSocket->GetUserToken()->GetOriginalLength(), NewLength);
	InSocket->NextStep(InSocket);
}

void USocketSender::Initialize(UFSocket* FSocket)
{
	if (FSocket == nullptr)
	{
		UFConsole::WriteErrorWithCategory(UFoolishClientCategories::SOCKET,
		                                  TEXT("Fail to create socket sender, because the FSocket is null."));
		return;
	}
	Socket = FSocket;
}

void USocketSender::Release()
{
	ClearGarbage();
	MarkAsGarbage();
}
