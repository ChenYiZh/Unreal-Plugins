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
#include "SizeUtil.generated.h"

/**
 * 长度管理类
 */
UCLASS(DisplayName="Foolish Games|Size")
class FOOLISHGAMES_API USizeUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * bool 长度
	 */
	inline constexpr static int32 BoolSize = sizeof(bool);
	/**
	 * char 长度
	 */
	//inline constexpr static int32 CharSize = sizeof(TCHAR);

	/**
	 * float 长度
	 */
	inline constexpr static int32 FloatSize = sizeof(float);
	/**
	 * double 长度
	 */
	inline constexpr static int32 DoubleSize = sizeof(double);

	/**
	 * int8 长度
	 */
	inline constexpr static int32 SByteSize = sizeof(int8);
	/**
	 * int16 长度
	 */
	inline constexpr static int32 ShortSize = sizeof(int16);
	/**
	 * int32 长度
	 */
	inline constexpr static int32 IntSize = sizeof(int32);
	/**
	 * int64 长度
	 */
	inline constexpr static int32 LongSize = sizeof(int64);

	/**
	 * uint8 长度
	 */
	inline constexpr static int32 ByteSize = sizeof(uint8);
	/**
	 * uint16 长度
	 */
	inline constexpr static int32 UShortSize = sizeof(uint16);
	/**
	 * uint32 长度
	 */
	inline constexpr static int32 UIntSize = sizeof(uint32);
	/**
	 * uint64 长度
	 */
	inline constexpr static int32 ULongSize = sizeof(uint64);

	/**
	 * ANSICHAR 长度
	 */
	inline constexpr static int32 ANSICHARSize = sizeof(ANSICHAR);
	/**
	 * CHAR 长度
	 */
	//inline constexpr static int32 CHARSize = sizeof(CHAR);
	/**
	 * TCHAR 长度
	 */
	inline constexpr static int32 TCHARSize = sizeof(TCHAR);

public:
	/**
	 * bool 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="Bool Size")
	static int32 GetBoolSize();
	/**
	 * char 长度
	 */
	// UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="Char Size")
	// static int32 GetCharSize();

	/**
	 * float 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="Float Size")
	static int32 GetFloatSize();
	/**
	 * double 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="Double Size")
	static int32 GetDoubleSize();

	/**
	 * int8 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="SByte Size")
	static int32 GetSByteSize();
	/**
	 * int16 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="Short Size")
	static int32 GetShortSize();
	/**
	 * int32 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="Int Size")
	static int32 GetIntSize();
	/**
	 * int64 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="Long Size")
	static int32 GetLongSize();

	/**
	 * uint8 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="Byte Size")
	static int32 GetByteSize();
	/**
	 * uint16 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="UShort Size")
	static int32 GetUShortSize();
	/**
	 * uint32 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="UInt Size")
	static int32 GetUIntSize();
	/**
	 * uint64 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="ULong Size")
	static int32 GetULongSize();

	/**
	 * ANSICHAR 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="ANSICHAR Size")
	static int32 GetANSICHARSize();
	/**
	 * TCHAR 长度
	 */
	UFUNCTION(BlueprintPure, Category="Foolish Games|Size", DisplayName="TCHAR Size")
	static int32 GetTCHARSize();
};
