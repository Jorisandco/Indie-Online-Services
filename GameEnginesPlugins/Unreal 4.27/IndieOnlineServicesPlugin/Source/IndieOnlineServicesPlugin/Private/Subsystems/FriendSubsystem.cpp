#include "Subsystems/FriendSubsystem.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Structures/UserInfoStruct.h"

void UFriendSubsystem::GetFriends()
{
	if (!RequestHelper)
	{
		RequestHelper = NewObject<UIndieOnlineServices_RequestClass>(this);
	}

	// remove when actual user registration is a thing ofcourse
	FString tempuserID = "32fbf73e-c56c-4bf5-aec1-21283e55f8ec";

	FOnHttpRequestCompleted FriendsCallback;
	FString Endpoint = "/api/FriendsList/get-friends-list/" + tempuserID;

	FriendsCallback.BindUObject(this, &UFriendSubsystem::HandleFriendsResponse);

	RequestHelper->GETRequest(Endpoint, FriendsCallback);
}

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