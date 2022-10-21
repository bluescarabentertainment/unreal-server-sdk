// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "LootLockerServerHttpClient.h"
#include "LootLockerServerAssetInstanceRequest.generated.h"

USTRUCT(BlueprintType)
struct FLootLockerServerKeyValue
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString key;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString value;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 id = 0;

	FLootLockerServerKeyValue(const FString& Key = "", const FString & Value = "", int32 Id = 0) :
		key(Key), value(Value), id(Id)
	{
	}
};

USTRUCT(BlueprintType)
struct FServerGetAssetInstanceKeyValueArrayResponse : public FLootLockerServerResponse
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerServerKeyValue> storage;
};

USTRUCT()
struct FServerUpdateAssetInstanceKeyValueArrayRequest
{
	GENERATED_BODY()
	UPROPERTY()
	TArray<FLootLockerServerKeyValue> storage;
};


DECLARE_DYNAMIC_DELEGATE_OneParam(FServerAssetInstanceKeyValuesResponseDelegateBP, FServerGetAssetInstanceKeyValueArrayResponse, Response);

DECLARE_DELEGATE_OneParam(FServerAssetInstanceKeyValuesResponseDelegate, FServerGetAssetInstanceKeyValueArrayResponse);

/**
 * 
 */
UCLASS()
class LOOTLOCKERSERVERSDK_API ULootLockerServerAssetInstanceRequest : public UObject
{
	GENERATED_BODY()

	public:

	ULootLockerServerAssetInstanceRequest();

	static void GetAllKeyValuePairs(int PlayerId, int AssetInstanceId, const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP = FServerAssetInstanceKeyValuesResponseDelegateBP(), const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest = FServerAssetInstanceKeyValuesResponseDelegate());
	static void GetKeyValuePair(int PlayerId, int AssetInstanceId, int PairId, const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP = FServerAssetInstanceKeyValuesResponseDelegateBP(), const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest = FServerAssetInstanceKeyValuesResponseDelegate());
	static void UpdateKeyValuePairs(int PlayerId, int AssetInstanceId, const TArray<FLootLockerServerKeyValue>& Pairs, const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP = FServerAssetInstanceKeyValuesResponseDelegateBP(), const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest = FServerAssetInstanceKeyValuesResponseDelegate());
	static void UpdateKeyValuePair(int PlayerId, int AssetInstanceId, const FLootLockerServerKeyValue& Pair, const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP = FServerAssetInstanceKeyValuesResponseDelegateBP(), const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest = FServerAssetInstanceKeyValuesResponseDelegate());
	static void DeleteKeyValuePair(int PlayerId, int AssetInstanceId, int PairId, const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP = FServerAssetInstanceKeyValuesResponseDelegateBP(), const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest = FServerAssetInstanceKeyValuesResponseDelegate());
	static void CreateKeyValuePair(int PlayerId, int AssetInstanceId, const FLootLockerServerKeyValue& Pair, const FServerAssetInstanceKeyValuesResponseDelegateBP& OnCompletedRequestBP = FServerAssetInstanceKeyValuesResponseDelegateBP(), const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest = FServerAssetInstanceKeyValuesResponseDelegate());

	static ULootLockerServerHttpClient* HttpClient;
};
