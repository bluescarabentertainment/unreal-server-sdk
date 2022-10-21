// Copyright (c) 2021 LootLocker


#include "LootLockerServerSDKManager.h"

//Authentication
void ULootLockerServerSDKManager::StartSession(const FServerAuthResponse& OnCompleteRequest)
{
	ULootLockerServerAuthRequest::StartSession( FServerAuthResponseBP(), OnCompleteRequest);
}

void ULootLockerServerSDKManager::MaintainSession(const FServerPingResponse& OnCompleteRequest)
{
	ULootLockerServerAuthRequest::MaintainSession(FServerPingResponseBP(), OnCompleteRequest);
}

void ULootLockerServerSDKManager::GetAssetsToGame(const FServerAssetsResponseDelegate& OnCompletedRequest, int StartFromIndex,
	int ItemsCount, ELootLockerServerAssetFilter AssetFilter, bool IncludeUGC)
{
	ULootLockerServerAssetRequest::GetAssetsToGame(StartFromIndex, ItemsCount, AssetFilter, IncludeUGC, FServerAssetsResponseDelegateBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::GetAllKeyValuePairsForAssetInstance(
	const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest,
	int PlayerId, int AssetInstanceId)
{
	ULootLockerServerAssetInstanceRequest::GetAllKeyValuePairs(PlayerId, AssetInstanceId, FServerAssetInstanceKeyValuesResponseDelegateBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::GetKeyValuePairForAssetInstance(
	const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest, int PlayerId, int AssetInstanceId,
	int PairId)
{
	ULootLockerServerAssetInstanceRequest::GetKeyValuePair(PlayerId, AssetInstanceId, PairId, FServerAssetInstanceKeyValuesResponseDelegateBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::UpdateKeyValuePairsForAssetInstance(const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest, int PlayerId, int AssetInstanceId, const TArray<FLootLockerServerKeyValue>& Pairs)
{
	ULootLockerServerAssetInstanceRequest::UpdateKeyValuePairs(PlayerId, AssetInstanceId, Pairs, FServerAssetInstanceKeyValuesResponseDelegateBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::UpdateKeyValuePairForAssetInstance(const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest, int PlayerId, int AssetInstanceId, const FLootLockerServerKeyValue& Pair)
{
	ULootLockerServerAssetInstanceRequest::UpdateKeyValuePair(PlayerId, AssetInstanceId, Pair, FServerAssetInstanceKeyValuesResponseDelegateBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::DeleteKeyValuePairForAssetInstance(
	const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest, int PlayerId, int AssetInstanceId,
	int PairId)
{
	ULootLockerServerAssetInstanceRequest::DeleteKeyValuePair(PlayerId, AssetInstanceId, PairId, FServerAssetInstanceKeyValuesResponseDelegateBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::CreateKeyValuePairForAssetInstance(
	const FServerAssetInstanceKeyValuesResponseDelegate& OnCompletedRequest,
	int PlayerId, int AssetInstanceId, const FLootLockerServerKeyValue& Item)
{
	ULootLockerServerAssetInstanceRequest::CreateKeyValuePair(PlayerId, AssetInstanceId, Item, FServerAssetInstanceKeyValuesResponseDelegateBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::GetInventory(const FServerInventoryResponse& OnGetInventoryRequestCompleted,
	int PlayerId, int StartFromIndex, int ItemsCount)
{
	ULootLockerServerPlayerRequest::GetInventory(PlayerId, StartFromIndex, ItemsCount, FInventoryResponseBP(), OnGetInventoryRequestCompleted);
}

void ULootLockerServerSDKManager::AddAssetToPlayerInventory(const FAddAssetResponse& OnAddAssetRequestCompleted,
	int PlayerId, FLootLockerServerAddAssetData AddAssetData)
{
	ULootLockerServerPlayerRequest::AddAssetToPlayerInventory(PlayerId, AddAssetData, FAddAssetResponseBP(), OnAddAssetRequestCompleted);
}

void ULootLockerServerSDKManager::AlterPlayerInventory(const FAlterInventoryResponse& OnAlterInventoryRequestCompleted,
	int PlayerId, FLootLockerServerAlterInventoryRequestData AlterInventoryData)
{
	ULootLockerServerPlayerRequest::AlterPlayerInventory(PlayerId, AlterInventoryData, FAlterInventoryResponseBP(), OnAlterInventoryRequestCompleted);
}

void ULootLockerServerSDKManager::GetPlayerLoadout(const FGetPlayerLoadoutResponse& OnGetPlayerLoadoutRequestCompleted,
	int PlayerId)
{
	ULootLockerServerPlayerRequest::GetPlayerLoadout(PlayerId, FGetPlayerLoadoutResponseBP(), OnGetPlayerLoadoutRequestCompleted);
}

void ULootLockerServerSDKManager::EquipAssetForPlayerLoadout(const FEquipAssetResponse& OnRequestCompleted,
	int PlayerId, int InstanceId)
{
	ULootLockerServerPlayerRequest::EquipAssetForPlayerLoadout(PlayerId, InstanceId, FEquipAssetResponseBP(), OnRequestCompleted);
}

void ULootLockerServerSDKManager::UnequipAssetForPlayerLoadout(const FUnequipAssetResponse& OnRequestCompleted,
	int PlayerId, int LoadoutId)
{
	ULootLockerServerPlayerRequest::UnequipAssetForPlayerLoadout(PlayerId, LoadoutId, FUnequipAssetResponseBP(), OnRequestCompleted);
}

void ULootLockerServerSDKManager::GetPersistentStorage(const FGetPersistentStorageResponse& OnRequestCompleted,
	TArray<int> PlayerIds)
{
	ULootLockerServerStorageRequest::GetPersistentStorage(PlayerIds, FGetPersistentStorageResponseBP(), OnRequestCompleted);
}

void ULootLockerServerSDKManager::UpdatePersistentStorage(const FUpdatePersistentStorageResponse& OnCompletedRequest,
	FLootLockerServerPersistentStorageRequestData RequestData)
{
	ULootLockerServerStorageRequest::UpdatePersistentStorage(RequestData, FUpdatePersistentStorageResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::GetPlayerCharacters(const FCharactersResponse& OnCompletedRequest, int PlayerId)
{
	ULootLockerServerCharacterRequest::GetPlayerCharacters(PlayerId, FCharactersResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::GetInventoryToCharacter(const FServerCharacterInventoryResponse& OnCompletedRequest,
	int PlayerId, int CharacterId)
{
	ULootLockerServerCharacterRequest::GetInventoryToCharacter(PlayerId, CharacterId, FCharacterInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::GetCharacterLoadout(const FServerCharacterLoadoutResponse& OnCompletedRequest, int PlayerId,
	int CharacterId)
{
	ULootLockerServerCharacterRequest::GetCharacterLoadout(PlayerId, CharacterId, FCharacterLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::EquipAssetForCharacterLoadout(const FEquipResponse& OnCompletedRequest,
	int PlayerId, int CharacterId, int InstanceId)
{
	ULootLockerServerCharacterRequest::EquipAssetForCharacterLoadout(PlayerId, CharacterId, InstanceId, FEquipResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::UnequipAssetForCharacterLoadout(const FUnequipResponse& OnCompletedRequest,
	int PlayerId, int CharacterId, int InstanceId)
{
	ULootLockerServerCharacterRequest::UnequipAssetForCharacterLoadout(PlayerId, CharacterId, InstanceId, FUnequipResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::GetPlayerHeroes(const FServerHeroesResponse& OnCompletedRequest, int PlayerId)
{
	ULootLockerServerHeroesRequest::GetPlayerHeroes(PlayerId, FHeroesResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::GetInventoryToHero(const FServerHeroInventoryResponse& OnCompletedRequest,
    int PlayerId, int HeroId)
{
	ULootLockerServerHeroesRequest::GetInventoryToHero(PlayerId, HeroId, FHeroInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::GetHeroLoadout(const FServerHeroLoadoutResponse& OnCompletedRequest, int PlayerId,
    int HeroId)
{
	ULootLockerServerHeroesRequest::GetHeroLoadout(PlayerId, HeroId, FHeroLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::EquipAssetForHeroLoadout(const FEquipHeroResponse& OnCompletedRequest,
    int PlayerId, int HeroId, int InstanceId)
{
	ULootLockerServerHeroesRequest::EquipAssetForHeroLoadout(PlayerId, HeroId, InstanceId, FEquipHeroResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::UnequipAssetForHeroLoadout(const FUnequipHeroResponse& OnCompletedRequest,
    int PlayerId, int HeroId, int InstanceId)
{
	ULootLockerServerHeroesRequest::UnequipAssetForHeroLoadout(PlayerId, HeroId, InstanceId, FUnequipHeroResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::InvokeTriggerOnBehalfOfPlayer(const FInvokeTriggerResponse& OnCompletedRequest,
	FString Name, int PlayerId)
{
	ULootLockerServerTriggerRequest::InvokeTriggerOnBehalfOfPlayer(Name, PlayerId, FInvokeTriggerResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::LookupPlayerNames(const FLookupPlayerNamesDelegate& OnCompletedRequest, struct FLookupPlayerNamesQuery Query)
{
	ULootLockerServerPlayerRequest::LookupPlayerNames(Query, FLookupPlayerNamesResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::CreateLeaderboard(const FLootLockerServerCreateLeaderboardRequest& CreateLeaderboardRequest, const FLootLockerServerCreateLeaderboardResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerLeaderboardRequest::CreateLeaderboard(CreateLeaderboardRequest, FLootLockerServerCreateLeaderboardResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::UpdateLeaderboard(const FLootLockerServerUpdateLeaderboardRequest& UpdateLeaderboardRequests, int LeaderboardId, const FLootLockerServerUpdateLeaderboardResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerLeaderboardRequest::UpdateLeaderboard(UpdateLeaderboardRequests, LeaderboardId, FLootLockerServerUpdateLeaderboardResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::DeleteLeaderboard(int LeaderboardId, const FLootLockerServerDeleteLeaderboardResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerLeaderboardRequest::DeleteLeaderboard(LeaderboardId, FLootLockerServerDeleteLeaderboardResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::SubmitScore(FString MemberId, int LeaderboardId, int Score, const FLootLockerServerSubmitScoreResponseDelegate& OnCompletedRequest)
{
	const FLootLockerServerSubmitScoreRequest ScoreRequest(MemberId, Score);

	ULootLockerServerLeaderboardRequest::SubmitScore(ScoreRequest, LeaderboardId, FLootLockerServerSubmitScoreResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::ListFilesForPlayer(int PlayerId,
	const FServerListFilesForPlayerResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerFilesRequest::ListFilesForPlayer(PlayerId, FListFilesForPlayerResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::GetFileByIdForPlayer(int PlayerId, int FileId,
	const FServerGetFileByIdForPlayerResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerFilesRequest::GetFileByIdForPlayer(PlayerId, FileId, FGetFileByIdForPlayerResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::DeleteFileForPlayer(int PlayerId, int FileId,
	const FServerDeleteFileForPlayerResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerFilesRequest::DeleteFileForPlayer(PlayerId, FileId, FDeleteFileForPlayerResponseBP(), OnCompletedRequest);
}

void ULootLockerServerSDKManager::UploadFileForPlayer(int PlayerId, const FString& FileName, const FString& Purpose,
	const FServerUploadFileForPlayerResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerFilesRequest::UploadFileForPlayer(PlayerId, FileName, Purpose, FUploadFileForPlayerResponseBP(), OnCompletedRequest);
}
