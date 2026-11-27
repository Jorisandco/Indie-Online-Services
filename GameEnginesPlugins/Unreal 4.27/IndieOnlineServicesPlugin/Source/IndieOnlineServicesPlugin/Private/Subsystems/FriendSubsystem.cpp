#include "Subsystems/FriendSubsystem.h"
#include "Subsystems/IndieOnlineCoreSubsystem.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Structures/UserInfoStruct.h"

// requests 
void UFriendSubsystem::GetFriends()
{
	FString UserId;
	UIndieOnlineServices_RequestClass* Helper = GetRequestHelper();

	if (!Helper || !TryGetActiveUserId(UserId))
	{
		OnFriendsListReceived.Broadcast(false, TArray<FUserInfoStruct>());
		return;
	}

	FOnHttpRequestCompleted FriendsCallback;
	const FString Endpoint = FString::Printf(TEXT("/api/FriendsList/get-friends-list/%s"), *UserId);

	FriendsCallback.BindUObject(this, &UFriendSubsystem::HandleFriendsResponse);

	Helper->GETRequest(Endpoint, FriendsCallback);
}


// handlers 
void UFriendSubsystem::HandleFriendsResponse(bool bSuccess, const FString& ResponseBody)
{
	TArray<FUserInfoStruct> FriendsList;

	if (!bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("GetFriends HTTP request failed."));
		OnFriendsListReceived.Broadcast(false, FriendsList);
		return;
	}

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
	TArray<TSharedPtr<FJsonValue>> JsonArray;

	if (!FJsonSerializer::Deserialize(Reader, JsonArray))
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to parse friends JSON array: %s"), *ResponseBody);
		OnFriendsListReceived.Broadcast(false, FriendsList);
		return;
	}

	FriendsList = ParseToUserDataArray(JsonArray);

	OnFriendsListReceived.Broadcast(true, FriendsList);
}


// Related Data Parser Functions: 
FUserInfoStruct UFriendSubsystem::ParseToUserData(const TSharedPtr<FJsonObject>& FriendObj) {
	FUserInfoStruct FriendInfo;

	if (!FriendObj.IsValid())
	{
		return FriendInfo;
	}

	FriendObj->TryGetStringField(TEXT("userId"), FriendInfo.UserId); // adds id to entry 
	FriendObj->TryGetStringField(TEXT("displayName"), FriendInfo.DisplayName); // adds name to entry
	FriendObj->TryGetBoolField(TEXT("isOnline"), FriendInfo.IsOnline); // adds online status to entry

	return FriendInfo;
}

TArray<FUserInfoStruct> UFriendSubsystem::ParseToUserDataArray(const TArray<TSharedPtr<FJsonValue>>& JsonArray) {
	TArray<FUserInfoStruct> ParsedFriends;

	for (const TSharedPtr<FJsonValue>& Entry : JsonArray)
	{
		if (!Entry.IsValid() || Entry->Type != EJson::Object) // check if it is a json object
		{
			continue;
		}

		TSharedPtr<FJsonObject> FriendObj = Entry->AsObject(); // keeps a reference to recieved data
		if (!FriendObj.IsValid()) // checks to see if pointer still points to valid memory adress 
		{
			continue;
		}


		ParsedFriends.Add(ParseToUserData(FriendObj)); // adds entry into array 
	}

	return ParsedFriends;
}

// private functions to get data from core subsystem 

bool UFriendSubsystem::TryGetActiveUserId(FString& OutUserId) const
{
	OutUserId.Reset();

	const UGameInstance* GameInstance = GetGameInstance();
	const UIndieOnlineCoreSubsystem* CoreSubsystem = GameInstance
		? GameInstance->GetSubsystem<UIndieOnlineCoreSubsystem>()
		: nullptr;

	if (!CoreSubsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("FriendSubsystem: CoreSubsystem is null."));
		return false;
	}

	OutUserId = CoreSubsystem->GetCurrentUserId();
	if (OutUserId.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("FriendSubsystem: CurrentUserId is empty."));
		return false;
	}

	return true;
}

UIndieOnlineServices_RequestClass* UFriendSubsystem::GetRequestHelper() const
{
	UGameInstance* GameInstance = GetGameInstance();
	UIndieOnlineCoreSubsystem* CoreSubsystem = GameInstance
		? GameInstance->GetSubsystem<UIndieOnlineCoreSubsystem>()
		: nullptr;

	if (!CoreSubsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("FriendSubsystem: CoreSubsystem is null."));
		return nullptr;
	}

	UIndieOnlineServices_RequestClass* Helper = CoreSubsystem->GetRequestHelper();
	if (!Helper)
	{
		UE_LOG(LogTemp, Warning, TEXT("FriendSubsystem: RequestHelper is null."));
	}

	return Helper;
}