#include "AssetTypeActions_BlueprintThumbnail.h"

#include "GameRoot.h"
#include "Basis/Level/Map.h"
#include "DefaultGameInstance.h"
#include "Engine/UserDefinedStruct.h"

const FSlateBrush* FAssetTypeActions_BlueprintThumbnail::CheckAssetData(const TSubclassOf<UObject>& ParentClass) const
{
	if (ParentClass->IsChildOf<UGameRoot>())
	{
		return FSlateIcon(TEXT("FoolishGameStyle"),TEXT("FoolishGameEditor.GameRoot")).GetIcon();
	}
	if (ParentClass->IsChildOf<UDefaultGameInstance>())
	{
		return FSlateIcon(TEXT("FoolishGameStyle"),TEXT("FoolishGameEditor.GameInstance")).GetIcon();
	}
	if (ParentClass->IsChildOf<UGameDefines>())
	{
		return FSlateIcon(TEXT("FoolishGameStyle"),TEXT("FoolishGameEditor.GameDefines")).GetIcon();
	}

	if (ParentClass->IsChildOf<UEventParam>())
	{
		return FSlateIcon(TEXT("FoolishGameStyle"),TEXT("FoolishGameEditor.GameEvent")).GetIcon();
	}
	if (ParentClass->IsChildOf<USystemBasis>())
	{
		return FSlateIcon(TEXT("FoolishGameStyle"),TEXT("FoolishGameEditor.GameSystem")).GetIcon();
	}
	if (ParentClass->IsChildOf<UMap>())
	{
		return FSlateIcon(TEXT("FoolishGameStyle"),TEXT("FoolishGameEditor.GameScene")).GetIcon();
	}
	if (ParentClass->IsChildOf<UDataTable>())
	{
		return FSlateIcon(TEXT("FoolishGameStyle"),TEXT("FoolishGameEditor.GameScene")).GetIcon();
	}
	if (ParentClass->IsChildOf<UUserDefinedStruct>())
	{
		return FSlateIcon(TEXT("FoolishGameStyle"),TEXT("FoolishGameEditor.GameScene")).GetIcon();
	}
	return nullptr;
}

const FSlateBrush* FAssetTypeActions_BlueprintThumbnail::GetThumbnailBrush(const FAssetData& InAssetData,
                                                                           const FName InClassName) const
{
	UBlueprint* Blueprint = Cast<UBlueprint>(InAssetData.GetAsset());
	if (!Blueprint)
	{
		return FAssetTypeActions_Blueprint::GetThumbnailBrush(InAssetData, InClassName);
	}
	if (!Blueprint->ParentClass)
	{
		return FSlateIcon(TEXT("FoolishGameStyle"),TEXT("FoolishGameEditor.BlueprintError")).GetIcon();
	}
	if (const FSlateBrush* Brush = CheckAssetData(Blueprint->ParentClass))
	{
		return Brush;
	}
	return FAssetTypeActions_Blueprint::GetThumbnailBrush(InAssetData, InClassName);
}

const FSlateBrush* FAssetTypeActions_BlueprintThumbnail::GetIconBrush(const FAssetData& InAssetData,
                                                                      const FName InClassName) const
{
	UBlueprint* Blueprint = Cast<UBlueprint>(InAssetData.GetAsset());
	if (!Blueprint)
	{
		return FAssetTypeActions_Blueprint::GetIconBrush(InAssetData, InClassName);
	}
	if (!Blueprint->ParentClass)
	{
		return FSlateIcon(TEXT("FoolishGameStyle"),TEXT("FoolishGameEditor.BlueprintError")).GetIcon();
	}
	if (const FSlateBrush* Brush = CheckAssetData(Blueprint->ParentClass))
	{
		return Brush;
	}
	return FAssetTypeActions_Blueprint::GetIconBrush(InAssetData, InClassName);
}
