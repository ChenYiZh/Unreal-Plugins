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


#include "Log/FConsole.h"

#include "Timer/TimeLord.h"

bool UFConsole::GetLogStackTracker()
{
	return bLogStackTracker;
}

void UFConsole::SetLogStackTracker(bool bLogTracker)
{
	FScopeLock SetLock(&Mutex);
	bLogStackTracker = bLogTracker;
}

// float UFConsole::GetDefaultDisplaySeconds()
// {
// 	return DefaultDisplaySeconds;
// }
//
// void UFConsole::SetDefaultDisplaySeconds(const float& TimeToDisplay)
// {
// 	DefaultDisplaySeconds = TimeToDisplay;
// }

FName UFConsole::GetDefaultCategory()
{
	FScopeLock SetLock(&Mutex);
	return CATEGORY;
}

void UFConsole::SetDefaultCategory(FName Category)
{
	FScopeLock SetLock(&Mutex);
	CATEGORY = Category;
}

void UFConsole::PushTrackLevel(FName Level)
{
	FScopeLock SetLock(&Mutex);
	LogStackLevels.Add(Level);
}

void UFConsole::RemoveTrackLevel(FName Level)
{
	FScopeLock SetLock(&Mutex);
	LogStackLevels.Remove(Level);
}

bool UFConsole::RegistLogger(UObject* Logger)
{
	if (Logger == nullptr)
	{
		return false;
	}
	if (!Logger->Implements<UILogger>())
	{
		return false;
	}
	FScopeLock SetLock(&Mutex);
	return Loggers.Add(Logger).AsInteger() > 0;
}

bool UFConsole::RemoveLogger(UObject* Logger)
{
	if (Logger == nullptr)
	{
		return false;
	}
	if (!Logger->Implements<UILogger>())
	{
		return false;
	}
	FScopeLock SetLock(&Mutex);
	return Loggers.Remove(Logger) > 0;
}

void UFConsole::Write(FString Message, const bool AddToScreen, float TimeToDisplay)
{
	SendMessage(ULogLevel::GET_DEBUG(), CATEGORY, Message, true, AddToScreen, TimeToDisplay);
}

void UFConsole::WriteWithCategory(const FName Category, FString Message, const bool AddToScreen, float TimeToDisplay)
{
	SendMessage(ULogLevel::GET_DEBUG(), Category, Message, true, AddToScreen, TimeToDisplay);
}

void UFConsole::WriteInfo(FString Message, const bool AddToScreen, float TimeToDisplay)
{
	SendMessage(ULogLevel::GET_INFO(), CATEGORY, Message, true, AddToScreen, TimeToDisplay);
}

void UFConsole::WriteInfoWithCategory(const FName Category, FString Message, const bool AddToScreen,
                                      float TimeToDisplay)
{
	SendMessage(ULogLevel::GET_INFO(), Category, Message, true, AddToScreen, TimeToDisplay);
}

void UFConsole::WriteWarn(FString Message, const bool AddToScreen, float TimeToDisplay)
{
	SendMessage(ULogLevel::GET_WARN(), CATEGORY, Message, true, AddToScreen, TimeToDisplay);
}

void UFConsole::WriteWarnWithCategory(const FName Category, FString Message, const bool AddToScreen,
                                      float TimeToDisplay)
{
	SendMessage(ULogLevel::GET_WARN(), Category, Message, true, AddToScreen, TimeToDisplay);
}

void UFConsole::WriteError(FString Message, const bool AddToScreen, float TimeToDisplay)
{
	SendMessage(ULogLevel::GET_ERROR(), CATEGORY, Message, true, AddToScreen, TimeToDisplay);
}

void UFConsole::WriteErrorWithCategory(const FName Category, FString Message, const bool AddToScreen,
                                       float TimeToDisplay)
{
	SendMessage(ULogLevel::GET_ERROR(), Category, Message, true, AddToScreen, TimeToDisplay);
}

void UFConsole::WriteTo(const FName Level, const FName Category, FString Message, const bool AddToScreen,
                        float TimeToDisplay)
{
	SendMessage(Level, Category, Message, true, AddToScreen, TimeToDisplay);
}

FString UFConsole::FormatCustomMessage(const FName& Level, const FName& Category, FString Message)
{
	FString NowTime = UTimeLord::Now().ToString(TEXT("%Y/%m/%d %H:%M:%S"));
	//FString NowTime = UTimeLord::Now().ToString();
	FString Result = FString::Printf(TEXT("%s [%s] - %s"), ToCStr(NowTime),
	                                 ToCStr(Category.ToString()), ToCStr(Message));
	return Result;
}

void UFConsole::Release()
{
	bLogStackTracker = false;
	CATEGORY = FName(TEXT("Log"));
	LogStackLevels = TSet<FName>{ULogLevel::GET_ERROR()};
	Loggers.Empty();
}

void UFConsole::SendMessage(const FName& Level, const FName& Category, FString& Message, const bool& bTrack,
                            const bool& AddToScreen, float TimeToDisplay)
{
	Message = FormatCustomMessage(Level, Category, Message);
	// if (TimeToDisplay < 0)
	// {
	// 	TimeToDisplay = DefaultDisplaySeconds;
	// }
	if (bLogStackTracker && bTrack && LogStackLevels.Contains(Level))
	{
		const FString StackIndent = "  ";
		TArray<FProgramCounterSymbolInfo> StackTrace = FPlatformStackWalk::GetStack(2);
		int Count = StackTrace.Num();
		for (int i = 0; i < Count; i++)
		{
			FProgramCounterSymbolInfo StackFrame = StackTrace[i];
			FString ModuleName = StackFrame.ModuleName;
			FString MethodName = StackFrame.FunctionName;
			FString FileName = StackFrame.Filename;
			Message += FString::Printf(TEXT("\r\n %s at %s.%s"), ToCStr(StackIndent), ToCStr(ModuleName),
			                           ToCStr(MethodName));
			if (!FileName.IsEmpty())
			{
				Message += FString::Printf(TEXT(" file %s:line %d"), ToCStr(FileName), StackFrame.LineNumber);
			}
		}
	}
	SendMessage(Level, Message, AddToScreen, TimeToDisplay);
}

void UFConsole::SendMessage(const FName& Level, const FString& Message, const bool& AddToScreen,
                            const float& TimeToDisplay)
{
	//Message += "\r\n";
	for (UObject* Logger : Loggers)
	{
		IILogger::Execute_SaveLog(Logger, Level, Message, AddToScreen, TimeToDisplay);
	}
}
