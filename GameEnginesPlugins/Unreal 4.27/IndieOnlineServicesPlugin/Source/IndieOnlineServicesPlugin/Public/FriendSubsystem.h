#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structures/UserInfoStruct.h"
#include "RequestClass/IndieOnlineServices_RequestClass.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FriendSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFriendsListReceived, bool, bSuccess, const TArray<FUserInfoStruct>&, UserInfo);

UCLASS(Blueprintable)
class UFriendSubsystem : public UGameInstanceSubsystem {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "IndieOnlineServices|Friends")
	void GetFriends();

	// Blueprints bind to this event pin to receive FUserInfoStruct asynchronously
	UPROPERTY(BlueprintAssignable, Category = "IndieOnlineServices|Friends")
	FOnFriendsListReceived OnFriendsListReceived;
private:
	void HandleFriendsResponse(bool bSuccess, const FString& ResponseBody);

	UPROPERTY()
	UIndieOnlineServices_RequestClass* RequestHelper;
};