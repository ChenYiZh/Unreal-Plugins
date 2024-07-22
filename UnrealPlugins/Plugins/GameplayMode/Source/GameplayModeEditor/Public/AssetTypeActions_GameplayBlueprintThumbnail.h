#pragma once
#include "AssetTypeActions_BlueprintThumbnail.h"

class GAMEPLAYMODEEDITOR_API FAssetTypeActions_GameplayBlueprintThumbnail : public FAssetTypeActions_BlueprintThumbnail
{
public:
	virtual const FSlateBrush* CheckAssetData(const TSubclassOf<UObject>& ParentClass) const override;
};
