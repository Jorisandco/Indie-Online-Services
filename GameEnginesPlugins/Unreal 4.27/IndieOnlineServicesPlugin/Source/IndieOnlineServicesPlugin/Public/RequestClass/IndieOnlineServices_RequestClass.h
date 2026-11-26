#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "IndieOnlineServices_RequestClass.generated.h"

DECLARE_DELEGATE_TwoParams(FOnHttpRequestCompleted, bool /*bSuccess*/, const FString& /*ResponseBody*/);

UCLASS()
class UIndieOnlineServices_RequestClass : public UObject
{
    GENERATED_BODY()

public:
    void GETRequest(const FString& RequestEndPoint, const FOnHttpRequestCompleted& OnComplete);
    void POSTRequest(const FString& RequestEndPoint, const FString& JSONData, const FOnHttpRequestCompleted& OnComplete);

private:
        void OnGetRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FOnHttpRequestCompleted OnComplete);
};