#include "FriendSubsystem.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

void UFriendSubsystem::GetFriends()
{
	if (!RequestHelper)
	{
		RequestHelper = NewObject<UIndieOnlineServices_RequestClass>(this);
	}

	FOnHttpRequestCompleted FriendsCallback;
	FriendsCallback.BindUObject(this, &UFriendSubsystem::HandleFriendsResponse);

	RequestHelper->GETRequest(TEXT("/api/FriendsList/test"), FriendsCallback);
}

void UFriendSubsystem::HandleFriendsResponse(bool bSuccess, const FString& ResponseBody)
{
	TArray<FUserInfoStruct> ParsedFriends;

	if (!bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("GetFriends HTTP request failed."));
		OnFriendsListReceived.Broadcast(false, ParsedFriends);
		return;
	}

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
	TArray<TSharedPtr<FJsonValue>> JsonArray;

	if (!FJsonSerializer::Deserialize(Reader, JsonArray))
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to parse friends JSON array: %s"), *ResponseBody);
		OnFriendsListReceived.Broadcast(false, ParsedFriends);
		return;
	}

	for (const TSharedPtr<FJsonValue>& Entry : JsonArray)
	{
		if (!Entry.IsValid() || Entry->Type != EJson::Object)
		{
			continue;
		}

		TSharedPtr<FJsonObject> FriendObj = Entry->AsObject();
		if (!FriendObj.IsValid())
		{
			continue;
		}

		FUserInfoStruct FriendInfo;
		FriendObj->TryGetStringField(TEXT("userId"), FriendInfo.UserId);
		FriendObj->TryGetStringField(TEXT("displayName"), FriendInfo.DisplayName);
		FriendObj->TryGetBoolField(TEXT("isOnline"), FriendInfo.IsOnline);

		ParsedFriends.Add(FriendInfo);
	}

	OnFriendsListReceived.Broadcast(true, ParsedFriends);
}