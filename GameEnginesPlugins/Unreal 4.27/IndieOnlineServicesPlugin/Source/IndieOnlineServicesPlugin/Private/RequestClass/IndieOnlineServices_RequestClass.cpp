#include "RequestClass/IndieOnlineServices_RequestClass.h"
#include "Http.h"
#include "IndieOnlineServicesSettings.h"

// Get Request
void UIndieOnlineServices_RequestClass::GETRequest(const FString& RequestEndPoint, const FOnHttpRequestCompleted& OnComplete)
{
	const FString BaseUrl = GetDefault<UIndieOnlineServicesSettings>()->BackendBaseUrl; // get's base url from settings using settings class 
	const FString FullUrl = BaseUrl + RequestEndPoint;
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest(); // sets up variable used to make request
	HttpRequest->SetURL(FullUrl);
	HttpRequest->SetVerb(TEXT("GET")); // declares request type

	TWeakObjectPtr<UIndieOnlineServices_RequestClass> WeakThis(this);
	HttpRequest->OnProcessRequestComplete().BindLambda( //binds event on request finish and handles data
		[WeakThis, OnComplete](FHttpRequestPtr Req, FHttpResponsePtr Resp, bool bSuccess)
		{
			if (!WeakThis.IsValid())
			{
				return;
			}

			WeakThis->OnGetRequestComplete(Req, Resp, bSuccess, OnComplete); // Calls completion handler and passes caller's callback so it can return the result
		}
	);
	HttpRequest->ProcessRequest(); // starts request
}

void UIndieOnlineServices_RequestClass::POSTRequest(const FString& RequestEndPoint, const FString& JSONData, const FOnHttpRequestCompleted& OnComplete)
{
	const FString BaseUrl = GetDefault<UIndieOnlineServicesSettings>()->BackendBaseUrl;
	const FString FullUrl = BaseUrl + RequestEndPoint;
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest(); // sets up variable used to make request
	HttpRequest->SetURL(FullUrl);
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetContentAsString(JSONData);

	TWeakObjectPtr<UIndieOnlineServices_RequestClass> WeakThis(this);
	HttpRequest->OnProcessRequestComplete().BindLambda(
		[WeakThis, OnComplete](FHttpRequestPtr Req, FHttpResponsePtr Resp, bool bSuccess)
		{
			if (!WeakThis.IsValid())
			{
				return;
			}

			WeakThis->OnGetRequestComplete(Req, Resp, bSuccess, OnComplete);
		}
	);
	HttpRequest->ProcessRequest();
}

void UIndieOnlineServices_RequestClass::OnGetRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FOnHttpRequestCompleted OnComplete)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("HTTP request failed before receiving a valid response."));
		if (OnComplete.IsBound())
		{
			OnComplete.Execute(false, FString());
		}
		return;
	}

	const int32 StatusCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();
	const bool bIsHttpSuccess = (StatusCode >= 200 && StatusCode < 300);

	UE_LOG(LogTemp, Log, TEXT("HTTP %d: %s"), StatusCode, *ResponseBody);

	if (OnComplete.IsBound())
	{
		OnComplete.Execute(bIsHttpSuccess, ResponseBody);
	}
}