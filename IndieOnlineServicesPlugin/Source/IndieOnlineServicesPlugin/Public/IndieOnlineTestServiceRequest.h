#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IndieOnlineTestServiceRequest.generated.h"

UCLASS()
class INDIEONLINESERVICESPLUGIN_API UIndieOnlineTestServiceRequest : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "IndieOnlineServices")
	static FString FormatPlayerGreeting(const FString& PlayerName);

	UFUNCTION(BlueprintCallable, Category = "IndieOnlineServices")
	static FText TokenGeneration();
};