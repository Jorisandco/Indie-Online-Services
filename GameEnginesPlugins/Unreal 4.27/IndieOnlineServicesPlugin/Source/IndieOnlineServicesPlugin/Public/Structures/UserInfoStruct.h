#pragma once

#include "CoreMinimal.h"
#include "UserInfoStruct.generated.h"


USTRUCT(BlueprintType)
struct FUserInfoStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "User profile")
	FString UserId;
	UPROPERTY(BlueprintReadOnly, Category = "User profile")
	FString DisplayName;

	UPROPERTY(BlueprintReadOnly, Category = "User profile")
	bool IsOnline = false;
};
