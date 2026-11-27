#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "RequestClass/IndieOnlineServices_RequestClass.h"
#include "IndieOnlineCoreSubsystem.generated.h"

UCLASS(Blueprintable)
class UIndieOnlineCoreSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "IndieOnlineServices|Core")
	void SetCurrentUserId(const FString& InUserId);

	UFUNCTION(BlueprintCallable, Category = "IndieOnlineServices|Core")
	FString GetCurrentUserId() const;

	UIndieOnlineServices_RequestClass* GetRequestHelper();

private:
	UPROPERTY()
	UIndieOnlineServices_RequestClass* RequestHelper = nullptr;

	// Temporary placeholder until login/registration sets this
	FString CurrentUserId = TEXT("32fbf73e-c56c-4bf5-aec1-21283e55f8ec");
};