// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "LootLockerServerAssetRequest.h"
#include "LootLockerServerConfig.h"
#include "LootLockerServerHttpClient.h"
#include "UObject/NoExportTypes.h"
#include "LootLockerServerPlayerRequest.generated.h"

USTRUCT(BlueprintType)
struct FPlatformIds {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString Platform;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FString> Ids;
};

USTRUCT(BlueprintType)
struct FLookupPlayerNamesQuery {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<int32> PlayerIds;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FString> PublicUids;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FString> GuestIds;
};

USTRUCT(BlueprintType)
struct FLootLockerServerRental {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	bool is_rental = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString time_left;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString duration;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString is_active;
};

USTRUCT(BlueprintType)
struct FLootLockerServerInventory {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 instance_id = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 variation_id = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString rental_option_id;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString acquisition_source;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FLootLockerServerAsset asset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FLootLockerServerRental rental;
};

USTRUCT(BlueprintType)
struct FLootLockerServerPlayerNames {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 player_id = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString player_public_uid;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString last_active_platform;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	FString platform_player_id;

};

USTRUCT(BlueprintType)
struct FLootLockerServerInventoryResponse : public FLootLockerServerResponse {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 total = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerServerInventory> items;
};

USTRUCT(BlueprintType)
struct FLootLockerServerAddAssetData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 asset_id = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 asset_variation_id = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 asset_rental_option_id = 0;
};

USTRUCT(BlueprintType)
struct FLootLockerServerAddAssetResponse : public FLootLockerServerResponse
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 total = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerServerInventory> items;
};

USTRUCT(BlueprintType)
struct FLootLockerServerAlterInventoryRequestData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerServerAddAssetData> add;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<int> remove;
};

USTRUCT(BlueprintType)
struct FLootLockerServerAlterInventoryResponse : public FLootLockerServerResponse
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerServerInventory> added;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<int> removed;
};

USTRUCT(BlueprintType)
struct FLootLockerServerGetPlayerLoadoutResponse : public FLootLockerServerResponse
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 total = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerServerInventory> items;
};

USTRUCT(BlueprintType)
struct FLootLockerServerEquipAssetForPlayerLoadoutResponse : public FLootLockerServerResponse
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 total = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerServerInventory> items;
};

USTRUCT(BlueprintType)
struct FLootLockerServerUnequipAssetForPlayerLoadoutResponse : public FLootLockerServerResponse
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	int32 total = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
	TArray<FLootLockerServerInventory> items;
};

USTRUCT(BlueprintType)
struct FLookupPlayerNamesResponse : public FLootLockerServerResponse {
	GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
		TArray<FLootLockerServerPlayerNames> players;
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryResponseBP, FLootLockerServerInventoryResponse, InventoryResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAddAssetResponseBP, FLootLockerServerAddAssetResponse, AddAssetResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAlterInventoryResponseBP, FLootLockerServerAlterInventoryResponse, AlterInventoryResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGetPlayerLoadoutResponseBP, FLootLockerServerGetPlayerLoadoutResponse, GetPlayerLoadoutResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FEquipAssetResponseBP, FLootLockerServerEquipAssetForPlayerLoadoutResponse, EquipAssetResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUnequipAssetResponseBP, FLootLockerServerUnequipAssetForPlayerLoadoutResponse, UnequipAssetResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLookupPlayerNamesResponseBP, FLookupPlayerNamesResponse, LookupPlayerNamesResponse);
DECLARE_DELEGATE_OneParam(FServerInventoryResponse, FLootLockerServerInventoryResponse);
DECLARE_DELEGATE_OneParam(FAddAssetResponse, FLootLockerServerAddAssetResponse);
DECLARE_DELEGATE_OneParam(FAlterInventoryResponse, FLootLockerServerAlterInventoryResponse);
DECLARE_DELEGATE_OneParam(FGetPlayerLoadoutResponse, FLootLockerServerGetPlayerLoadoutResponse);
DECLARE_DELEGATE_OneParam(FEquipAssetResponse, FLootLockerServerEquipAssetForPlayerLoadoutResponse);
DECLARE_DELEGATE_OneParam(FUnequipAssetResponse, FLootLockerServerUnequipAssetForPlayerLoadoutResponse);
DECLARE_DELEGATE_OneParam(FLookupPlayerNamesDelegate, FLookupPlayerNamesResponse);

/**
 * 
 */
UCLASS()
class LOOTLOCKERSERVERSDK_API ULootLockerServerPlayerRequest : public UObject
{
	GENERATED_BODY()

public:	
	ULootLockerServerPlayerRequest();

	static void GetInventory(int PlayerId, int StartFromIndex, int ItemsCount, const FInventoryResponseBP& OnCompletedRequestBP = FInventoryResponseBP(), const FServerInventoryResponse& OnCompletedRequest = FServerInventoryResponse());

	static void AddAssetToPlayerInventory(int PlayerId, FLootLockerServerAddAssetData AddAssetData, const FAddAssetResponseBP& OnCompletedRequestBP = FAddAssetResponseBP(), const FAddAssetResponse& OnCompletedRequest = FAddAssetResponse());

	static void AlterPlayerInventory(int PlayerId, const FLootLockerServerAlterInventoryRequestData& RequestData, const FAlterInventoryResponseBP& OnCompletedRequestBP = FAlterInventoryResponseBP(), const FAlterInventoryResponse& OnCompletedRequest = FAlterInventoryResponse());
	
	static void GetPlayerLoadout(int PlayerId, const FGetPlayerLoadoutResponseBP& OnCompletedRequestBP = FGetPlayerLoadoutResponseBP(), const FGetPlayerLoadoutResponse& OnCompletedRequest = FGetPlayerLoadoutResponse());

	static void EquipAssetForPlayerLoadout(int PlayerId, int InstanceId, const FEquipAssetResponseBP& OnCompletedRequestBP = FEquipAssetResponseBP(), const FEquipAssetResponse& OnCompletedRequest = FEquipAssetResponse());

	static void UnequipAssetForPlayerLoadout(int PlayerId, int LoadoutId, const FUnequipAssetResponseBP& OnCompletedRequestBP = FUnequipAssetResponseBP(), const FUnequipAssetResponse& OnCompletedRequest = FUnequipAssetResponse());

	static void LookupPlayerNames(FLookupPlayerNamesQuery const& Query, const FLookupPlayerNamesResponseBP& OnCompletedRequestBP = FLookupPlayerNamesResponseBP(), const FLookupPlayerNamesDelegate& OnCompletedRequest = FLookupPlayerNamesDelegate());

protected:
	static ULootLockerServerHttpClient* HttpClient;

private:
	static void AppendQueryParameters(const FString& Key, const TArray<FString>& Values, TArray<FString> &OutParams);
};
