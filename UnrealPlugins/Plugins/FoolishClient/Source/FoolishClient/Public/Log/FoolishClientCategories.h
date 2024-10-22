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

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FoolishClientCategories.generated.h"

/**
 * 类别类
 */
UCLASS(NotBlueprintable, NotBlueprintType, DisplayName="Foolish Games|Categories")
class FOOLISHCLIENT_API UFoolishClientCategories : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * @brief ACTION
	 */
	inline const static FName ACTION = FName(TEXT("Action"));
	/**
	 * @brief SOCKET
	 */
	inline const static FName SOCKET = FName(TEXT("Socket"));
	/**
	 * @brief FNETWORK
	 */
	inline const static FName FNETWORK = FName(TEXT("FNetwork"));

public:
	/**
	 * @brief ACTION
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Categories", DisplayName="ACTION")
	static FName GET_ACTION();

	/**
	 * @brief SOCKET
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Categories", DisplayName="SOCKET")
	static FName GET_SOCKET();

	/**
	 * @brief FNETWORK
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Categories", DisplayName="NETWORK")
	static FName GET_FNETWORK();
};
