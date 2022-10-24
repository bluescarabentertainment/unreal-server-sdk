// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "LootLockerServerHttpClient.h"
#include "LootLockerServerAssetInstanceRequest.generated.h"

USTRUCT(BlueprintType)
struct FLootLockerServerAssetInstanceStorageItem
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString key;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString value;

	FLootLockerServerAssetInstanceStorageItem(const FString& Key = "", const FString & Value = "") :
		key(Key), value(Value)
	{
	}
};

USTRUCT(BlueprintType)
struct FLootLockerServerAssetInstanceStorageResponseItem : public FLootLockerServerAssetInstanceStorageItem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 id = 0;

	FLootLockerServerAssetInstanceStorageResponseItem(const FString& Key = "", const FString & Value = "", int32 Id = 0) :
		FLootLockerServerAssetInstanceStorageItem(Key, Value), id(Id)
	{
	}
};

USTRUCT(BlueprintType)
struct FLootLockerServerAssetInstanceStorageItems
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerServerAssetInstanceStorageItem> storage;
};


USTRUCT(BlueprintType)
struct FLootLockerServerAssetInstanceStorageItemsResponse : public FLootLockerServerResponse
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerServerAssetInstanceStorageResponseItem> storage;
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP, FLootLockerServerAssetInstanceStorageItemsResponse, Response);

DECLARE_DELEGATE_OneParam(FLootLockerServerAssetInstanceStorageItemsResponseDelegate, FLootLockerServerAssetInstanceStorageItemsResponse);

/**
 * 
 */
UCLASS()
class LOOTLOCKERSERVERSDK_API ULootLockerServerAssetInstanceRequest : public UObject
{
	GENERATED_BODY()

	public:

	ULootLockerServerAssetInstanceRequest();

	static void GetAllKeyValuePairs(int PlayerId, int AssetInstanceId, const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequestBP = FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP(), const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());
	static void UpdateKeyValuePairs(int PlayerId, int AssetInstanceId, const TArray<FLootLockerServerAssetInstanceStorageItem>& Pairs, const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequestBP = FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP(), const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());
	static void CreateKeyValuePair(int PlayerId, int AssetInstanceId, const FLootLockerServerAssetInstanceStorageItem& Pair, const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequestBP = FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP(), const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());
	static void GetKeyValuePair(int PlayerId, int AssetInstanceId, int PairId, const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequestBP = FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP(), const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());
	static void UpdateKeyValuePair(int PlayerId, int AssetInstanceId, int PairId, const FLootLockerServerAssetInstanceStorageItem& Pair, const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequestBP = FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP(), const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());
	static void DeleteKeyValuePair(int PlayerId, int AssetInstanceId, int PairId, const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequestBP = FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP(), const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());

	static ULootLockerServerHttpClient* HttpClient;
};
