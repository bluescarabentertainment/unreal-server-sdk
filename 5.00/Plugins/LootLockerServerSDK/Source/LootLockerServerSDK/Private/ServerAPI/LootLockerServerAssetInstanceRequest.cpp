// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerAPI/LootLockerServerAssetInstanceRequest.h"

#include "JsonObjectConverter.h"
#include "LootLockerServerGameEndpoints.h"
#include "LootLockerServerSDK/Private/Utils/LootLockerServerUtilities.h"

ULootLockerServerHttpClient* ULootLockerServerAssetInstanceRequest::HttpClient = nullptr;
// Sets default values for this component's properties
ULootLockerServerAssetInstanceRequest::ULootLockerServerAssetInstanceRequest()
{
    HttpClient = NewObject<ULootLockerServerHttpClient>();
}

void ULootLockerServerAssetInstanceRequest::GetAllKeyValuePairs(
    int PlayerId, int AssetInstanceId,
    const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP,
    const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest)
{
    const FServerResponseCallback SessionResponse = FServerResponseCallback::CreateLambda([OnCompletedRequestBP, OnCompletedRequest](FLootLockerServerResponse response)
        {
            FServerGetAssetInstanceKeyValueArrayResponse ResponseStruct;
            if (response.success)
            {
                FJsonObjectConverter::JsonObjectStringToUStruct<FServerGetAssetInstanceKeyValueArrayResponse>(response.FullTextFromServer, &ResponseStruct, 0, 0);
                ResponseStruct.success = true;
            }
            else {
                ResponseStruct.success = false;
                UE_LOG(LogLootLockerServer, Error, TEXT("GetAllKeyValuePairs failed for AssetInstance"));
            }
            ResponseStruct.FullTextFromServer = response.FullTextFromServer;
            (void) OnCompletedRequestBP.ExecuteIfBound(ResponseStruct);
            (void) OnCompletedRequest.ExecuteIfBound(ResponseStruct);
        });

    const FLootLockerServerEndPoints& Endpoint = ULootLockerServerGameEndpoints::GetAllKeyValuePairsForAssetInstanceEndpoint;
    const FString RequestMethod = ULootLockerServerConfig::GetEnum(TEXT("ELootLockerServerHTTPMethod"), static_cast<int32>(Endpoint.requestMethod));
    const FString Url = FString::Format(*(Endpoint.endpoint), { PlayerId, AssetInstanceId });
    HttpClient->SendApi(Url, RequestMethod, FString(), SessionResponse, true);
}

void ULootLockerServerAssetInstanceRequest::GetKeyValuePair(int PlayerId, int AssetInstanceId, int PairId,
    const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP,
    const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest)
{
    const FServerResponseCallback SessionResponse = FServerResponseCallback::CreateLambda([OnCompletedRequestBP, OnCompletedRequest](FLootLockerServerResponse response)
        {
            FServerGetAssetInstanceKeyValueArrayResponse ResponseStruct;
            if (response.success)
            {
                FJsonObjectConverter::JsonObjectStringToUStruct<FServerGetAssetInstanceKeyValueArrayResponse>(response.FullTextFromServer, &ResponseStruct, 0, 0);
                ResponseStruct.success = true;
            }
            else {
                ResponseStruct.success = false;
                UE_LOG(LogLootLockerServer, Error, TEXT("GetKeyValuePair failed for AssetInstance"));
            }
            ResponseStruct.FullTextFromServer = response.FullTextFromServer;
            (void) OnCompletedRequestBP.ExecuteIfBound(ResponseStruct);
            (void) OnCompletedRequest.ExecuteIfBound(ResponseStruct);
        });

    const FLootLockerServerEndPoints& Endpoint = ULootLockerServerGameEndpoints::GetKeyValuePairForAssetInstanceEndpoint;
    const FString RequestMethod = ULootLockerServerConfig::GetEnum(TEXT("ELootLockerServerHTTPMethod"), static_cast<int32>(Endpoint.requestMethod));
    const FString Url = FString::Format(*(Endpoint.endpoint), { PlayerId, AssetInstanceId, PairId });
    HttpClient->SendApi(Url, RequestMethod, FString(), SessionResponse, true);
}

void ULootLockerServerAssetInstanceRequest::UpdateKeyValuePairs(int PlayerId, int AssetInstanceId, const TArray<FLootLockerServerKeyValue>& Pairs, const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP, const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest)
{
    const FServerResponseCallback SessionResponse = FServerResponseCallback::CreateLambda([OnCompletedRequestBP, OnCompletedRequest](FLootLockerServerResponse response)
        {
            FServerGetAssetInstanceKeyValueArrayResponse ResponseStruct;
            if (response.success)
            {
                FJsonObjectConverter::JsonObjectStringToUStruct<FServerGetAssetInstanceKeyValueArrayResponse>(response.FullTextFromServer, &ResponseStruct, 0, 0);
                ResponseStruct.success = true;
            }
            else {
                ResponseStruct.success = false;
                UE_LOG(LogLootLockerServer, Error, TEXT("UpdateKeyValuePairs failed for AssetInstance"));
            }
            ResponseStruct.FullTextFromServer = response.FullTextFromServer;
            (void)OnCompletedRequestBP.ExecuteIfBound(ResponseStruct);
            (void)OnCompletedRequest.ExecuteIfBound(ResponseStruct);
        });

    FString ContentString;
    FServerUpdateAssetInstanceKeyValueArrayRequest Request;
    Request.storage = Pairs;
    FJsonObjectConverter::UStructToJsonObjectString(FServerUpdateAssetInstanceKeyValueArrayRequest::StaticStruct(), &Request, ContentString, 0, 0);
    const FLootLockerServerEndPoints& Endpoint = ULootLockerServerGameEndpoints::UpdateKeyValuePairsForAssetInstanceEndpoint;
    const FString RequestMethod = ULootLockerServerConfig::GetEnum(TEXT("ELootLockerServerHTTPMethod"), static_cast<int32>(Endpoint.requestMethod));
    const FString Url = FString::Format(*(Endpoint.endpoint), { PlayerId, AssetInstanceId });
    HttpClient->SendApi(Url, RequestMethod, ContentString, SessionResponse, true);
}

void ULootLockerServerAssetInstanceRequest::UpdateKeyValuePair(int PlayerId, int AssetInstanceId, const FLootLockerServerKeyValue& Pair, const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP, const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest)
{
    const FServerResponseCallback SessionResponse = FServerResponseCallback::CreateLambda([OnCompletedRequestBP, OnCompletedRequest](FLootLockerServerResponse response)
        {
            FServerGetAssetInstanceKeyValueArrayResponse ResponseStruct;
            if (response.success)
            {
                FJsonObjectConverter::JsonObjectStringToUStruct<FServerGetAssetInstanceKeyValueArrayResponse>(response.FullTextFromServer, &ResponseStruct, 0, 0);
                ResponseStruct.success = true;
            }
            else {
                ResponseStruct.success = false;
                UE_LOG(LogLootLockerServer, Error, TEXT("UpdateKeyValuePair failed for AssetInstance"));
            }
            ResponseStruct.FullTextFromServer = response.FullTextFromServer;
            (void)OnCompletedRequestBP.ExecuteIfBound(ResponseStruct);
            (void)OnCompletedRequest.ExecuteIfBound(ResponseStruct);
        });

    FString ContentString;
    FJsonObjectConverter::UStructToJsonObjectString(FLootLockerServerKeyValue::StaticStruct(), &Pair, ContentString, 0, 0);
    const FLootLockerServerEndPoints& Endpoint = ULootLockerServerGameEndpoints::UpdateKeyValuePairForAssetInstanceEndpoint;
    const FString RequestMethod = ULootLockerServerConfig::GetEnum(TEXT("ELootLockerServerHTTPMethod"), static_cast<int32>(Endpoint.requestMethod));
    const FString Url = FString::Format(*(Endpoint.endpoint), { PlayerId, AssetInstanceId });
    HttpClient->SendApi(Url, RequestMethod, ContentString, SessionResponse, true);
}


void ULootLockerServerAssetInstanceRequest::DeleteKeyValuePair(int PlayerId, int AssetInstanceId, int PairId,
    const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP,
    const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest)
{
    const FServerResponseCallback SessionResponse = FServerResponseCallback::CreateLambda([OnCompletedRequestBP, OnCompletedRequest](FLootLockerServerResponse response)
        {
            FServerGetAssetInstanceKeyValueArrayResponse ResponseStruct;
            if (response.success)
            {
                FJsonObjectConverter::JsonObjectStringToUStruct<FServerGetAssetInstanceKeyValueArrayResponse>(response.FullTextFromServer, &ResponseStruct, 0, 0);
                ResponseStruct.success = true;
            }
            else {
                ResponseStruct.success = false;
                UE_LOG(LogLootLockerServer, Error, TEXT("DeleteKeyValuePair failed for AssetInstance"));
            }
            ResponseStruct.FullTextFromServer = response.FullTextFromServer;
            (void) OnCompletedRequestBP.ExecuteIfBound(ResponseStruct);
            (void) OnCompletedRequest.ExecuteIfBound(ResponseStruct);
        });

    const FLootLockerServerEndPoints& Endpoint = ULootLockerServerGameEndpoints::DeleteKeyValuePairForAssetInstanceEndpoint;
    const FString RequestMethod = ULootLockerServerConfig::GetEnum(TEXT("ELootLockerServerHTTPMethod"), static_cast<int32>(Endpoint.requestMethod));
    const FString Url = FString::Format(*(Endpoint.endpoint), { PlayerId, AssetInstanceId, PairId });
    HttpClient->SendApi(Url, RequestMethod, FString(), SessionResponse, true);
}

void ULootLockerServerAssetInstanceRequest::CreateKeyValuePair(
    int PlayerId, int AssetInstanceId, const FLootLockerServerKeyValue& Pair,
    const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP,
    const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest)
{
    const FServerResponseCallback SessionResponse = FServerResponseCallback::CreateLambda([OnCompletedRequestBP, OnCompletedRequest](FLootLockerServerResponse response)
        {
            FServerGetAssetInstanceKeyValueArrayResponse ResponseStruct;
            if (response.success)
            {
                FJsonObjectConverter::JsonObjectStringToUStruct<FServerGetAssetInstanceKeyValueArrayResponse>(response.FullTextFromServer, &ResponseStruct, 0, 0);
                ResponseStruct.success = true;
            }
            else {
                ResponseStruct.success = false;
                UE_LOG(LogLootLockerServer, Error, TEXT("CreateKeyValuePair failed for AssetInstance"));
            }
            ResponseStruct.FullTextFromServer = response.FullTextFromServer;
            (void) OnCompletedRequestBP.ExecuteIfBound(ResponseStruct);
            (void) OnCompletedRequest.ExecuteIfBound(ResponseStruct);
        });

    FString ContentString;
    FJsonObjectConverter::UStructToJsonObjectString(FLootLockerServerKeyValue::StaticStruct(), &Pair, ContentString, 0, 0);
    const FLootLockerServerEndPoints& Endpoint = ULootLockerServerGameEndpoints::CreateKeyValuePairForAssetInstanceEndpoint;
    const FString RequestMethod = ULootLockerServerConfig::GetEnum(TEXT("ELootLockerServerHTTPMethod"), static_cast<int32>(Endpoint.requestMethod));
    const FString Url = FString::Format(*(Endpoint.endpoint), { PlayerId, AssetInstanceId });
    HttpClient->SendApi(Url, RequestMethod, ContentString, SessionResponse, true);
}

