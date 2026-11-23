#include "IndieOnlineServicesSettings.h"

UIndieOnlineServicesSettings::UIndieOnlineServicesSettings()
{
	CategoryName = TEXT("Plugins");
	GameId = TEXT("default-game");
	BackendBaseUrl = TEXT("https://localhost:5001");
	GameIncludesFriendListFunctionality = false;
	GameHasAPartySystemFunction = false;
}