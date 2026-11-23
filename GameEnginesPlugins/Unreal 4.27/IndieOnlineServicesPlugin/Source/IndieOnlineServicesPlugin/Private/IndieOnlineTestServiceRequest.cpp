#include "IndieOnlineTestServiceRequest.h"
#include "IndieOnlineServicesPluginModule.h"
#define LOCTEXT_NAMESPACE "UIndieOnlineTestServiceRequest"

FString UIndieOnlineTestServiceRequest::FormatPlayerGreeting(const FString& PlayerName)
{
	UE_LOG(LogIndieOnlineServices, Log, TEXT("FormatPlayerGreeting called for: %s"), *PlayerName);
	return FString::Printf(TEXT("Welcome to Indie Online Services, %s!"), *PlayerName);
};

FText UIndieOnlineTestServiceRequest::TokenGeneration() {
	FText Token = LOCTEXT("token", "Token not found");
	return Token;
};

#undef LOCTEXT_NAMESPACE