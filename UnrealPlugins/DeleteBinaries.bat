rd /s /q Binaries\Win64
rd /s /q Plugins\VirtualInputCore\Binaries
rd /s /q Plugins\Framework\Binaries
@rd /s /q Plugins\FoolishClient\Binaries
rd /s /q Plugins\FoolishGames\Binaries
rd /s /q Plugins\GameplayMode\Binaries
@rd /s /q Plugins\WorldCreator\Binaries

@echo off
set /p bool=�Ƿ�ɾ�������������dll��y/n��
@echo on
if "%bool%"=="y" (
rd /s /q Plugins\UnrealJS\Binaries
rd /s /q Plugins\UnLua\Binaries
rd /s /q Plugins\UnLuaExtensions\LuaProtobuf\Binaries
rd /s /q Plugins\UnLuaExtensions\LuaRapidjson\Binaries
rd /s /q Plugins\UnLuaExtensions\LuaSocket\Binaries
rd /s /q Plugins\Puerts\Binaries
rd /s /q Plugins\ReactUMG\Binaries
rd /s /q Plugins\DarkerNodes\Binaries
rd /s /q Plugins\HLSLMaterialExpression\Binaries
rd /s /q Plugins\DLSS\Binaries
rd /s /q Plugins\DLSSMoviePipelineSupport\Binaries
rd /s /q Plugins\FSR2\Binaries
rd /s /q Plugins\FSR2MovieRenderPipeline\Binaries
rd /s /q Plugins\NIS\Binaries
rd /s /q Plugins\Streamline\Binaries
)