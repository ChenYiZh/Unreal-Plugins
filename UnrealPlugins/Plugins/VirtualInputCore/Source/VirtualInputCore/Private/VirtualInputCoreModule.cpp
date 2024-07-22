#include "VirtualInputCoreModule.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_GAME_MODULE(FVirtualInputCoreModule, VirtualInputCore);

void FVirtualInputCoreModule::StartupModule()
{
	IModuleInterface::StartupModule();
}

void FVirtualInputCoreModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}
