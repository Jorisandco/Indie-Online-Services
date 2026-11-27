#include "Subsystems/IndieOnlineCoreSubsystem.h"

void UIndieOnlineCoreSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (!RequestHelper)
	{
		RequestHelper = NewObject<UIndieOnlineServices_RequestClass>(this);
	}
}

void UIndieOnlineCoreSubsystem::Deinitialize()
{
	RequestHelper = nullptr;
	Super::Deinitialize();
}

void UIndieOnlineCoreSubsystem::SetCurrentUserId(const FString& InUserId)
{
	CurrentUserId = InUserId;
}

FString UIndieOnlineCoreSubsystem::GetCurrentUserId() const
{
	return CurrentUserId;
}

UIndieOnlineServices_RequestClass* UIndieOnlineCoreSubsystem::GetRequestHelper()
{
	if (!RequestHelper)
	{
		RequestHelper = NewObject<UIndieOnlineServices_RequestClass>(this);
	}
	return RequestHelper;
}