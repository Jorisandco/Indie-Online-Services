#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "IndieOnlineServicesSettings.generated.h"

UCLASS(Config = IndieOnlineServices, defaultconfig, meta = (DisplayName = "Indie Online Services"))
class INDIEONLINESERVICESPLUGIN_API UIndieOnlineServicesSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UIndieOnlineServicesSettings();

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Connection")
	FString GameId;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Connection")
	FString BackendBaseUrl;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "FriendsList")
	bool GameIncludesFriendListFunctionality;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Sessions")
	bool GameHasAPartySystemFunction;
};