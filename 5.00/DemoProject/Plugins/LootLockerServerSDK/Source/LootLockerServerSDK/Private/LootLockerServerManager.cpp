// Copyright (c) 2021 LootLocker

#include "LootLockerServerManager.h"

void ULootLockerServerManager::SetConfig(FString LootLockerServerKey, bool OnDevelopmentMode, FString GameVersion, FString LootLockerVersion)
{
    ULootLockerServerConfig* config = GetMutableDefault<ULootLockerServerConfig>();
    config->LootLockerServerKey = LootLockerServerKey;
    config->OnDevelopmentMode = OnDevelopmentMode;
    config->GameVersion = GameVersion;
    config->LootLockerVersion = LootLockerVersion;
    config->SaveConfig();
}

void ULootLockerServerManager::StartSession(const FServerAuthResponseBP& OnCompletedRequest)
{
    ULootLockerServerAuthRequest::StartSession(OnCompletedRequest);
}
void ULootLockerServerManager::MaintainSession(const FServerPingResponseBP& OnCompletedRequest)
{
    ULootLockerServerAuthRequest::MaintainSession(OnCompletedRequest);
}

void ULootLockerServerManager::GetAllKeyValuePairsForAssetInstance(const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequest, int PlayerId, int AssetInstanceId)
{
    ULootLockerServerAssetInstanceRequest::GetAllKeyValuePairs(PlayerId, AssetInstanceId, OnCompletedRequest);
}

void ULootLockerServerManager::UpdateKeyValuePairsForAssetInstance(
    const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequest, int PlayerId, int AssetInstanceId,
    const TArray<FLootLockerServerAssetInstanceStorageItem>& Pairs)
{
    ULootLockerServerAssetInstanceRequest::UpdateKeyValuePairs(PlayerId, AssetInstanceId, Pairs, OnCompletedRequest);
}

void ULootLockerServerManager::CreateKeyValuePairForAssetInstance(const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequest, int PlayerId, int AssetInstanceId, const FString& Key, const FString& Value)
{
    const FLootLockerServerAssetInstanceStorageItem Item(Key, Value);
    ULootLockerServerAssetInstanceRequest::CreateKeyValuePair(PlayerId, AssetInstanceId, Item, OnCompletedRequest);
}

void ULootLockerServerManager::GetKeyValuePairForAssetInstance(
    const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequest, int PlayerId, int AssetInstanceId,
    int PairId)
{
    ULootLockerServerAssetInstanceRequest::GetKeyValuePair(PlayerId, AssetInstanceId, PairId, OnCompletedRequest);
}

void ULootLockerServerManager::UpdateKeyValuePairForAssetInstance(
    const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequest, int PlayerId, int AssetInstanceId, int PairId,
    const FLootLockerServerAssetInstanceStorageItem& Pair)
{
    ULootLockerServerAssetInstanceRequest::UpdateKeyValuePair(PlayerId, AssetInstanceId, PairId, Pair, OnCompletedRequest);
}

void ULootLockerServerManager::DeleteKeyValuePairForAssetInstance(
    const FLootLockerServerAssetInstanceStorageItemsResponseDelegateBP& OnCompletedRequest, int PlayerId, int AssetInstanceId,
    int PairId)
{
    ULootLockerServerAssetInstanceRequest::DeleteKeyValuePair(PlayerId, AssetInstanceId, PairId, OnCompletedRequest);
}

void ULootLockerServerManager::GetAssetsToGame(const FServerAssetsResponseDelegateBP& OnGetAssetsRequestCompleted,
    int StartFromIndex, int ItemsCount, ELootLockerServerAssetFilter AssetFilter, bool IncludeUGC)
{
    ULootLockerServerAssetRequest::GetAssetsToGame(StartFromIndex, ItemsCount, AssetFilter, IncludeUGC, OnGetAssetsRequestCompleted, FServerAssetsResponseDelegate());
}

void ULootLockerServerManager::GetInventory(const FInventoryResponseBP& OnGetInventoryRequestCompleted, int PlayerId, int StartFromIndex, int ItemsCount)
{
    ULootLockerServerPlayerRequest::GetInventory(PlayerId, StartFromIndex, ItemsCount, OnGetInventoryRequestCompleted, FServerInventoryResponse());
}

void ULootLockerServerManager::AddAssetToPlayerInventory(const FAddAssetResponseBP& OnAddAssetRequestCompleted,
    int32 PlayerId, FLootLockerServerAddAssetData AddAssetData)
{
    ULootLockerServerPlayerRequest::AddAssetToPlayerInventory(PlayerId, AddAssetData, OnAddAssetRequestCompleted, FAddAssetResponse());
}

void ULootLockerServerManager::AlterPlayerInventory(const FAlterInventoryResponseBP& OnAlterInventoryRequestCompleted,
	int32 PlayerId, const FLootLockerServerAlterInventoryRequestData& AlterInventoryData)
{
	ULootLockerServerPlayerRequest::AlterPlayerInventory(PlayerId, AlterInventoryData, OnAlterInventoryRequestCompleted, FAlterInventoryResponse());
}

void ULootLockerServerManager::GetPlayerLoadout(const FGetPlayerLoadoutResponseBP& OnGetPlayerLoadoutRequestCompleted,
    int PlayerId)
{
    ULootLockerServerPlayerRequest::GetPlayerLoadout(PlayerId, OnGetPlayerLoadoutRequestCompleted, FGetPlayerLoadoutResponse());
}

void ULootLockerServerManager::EquipAssetForPlayerLoadout(const FEquipAssetResponseBP& OnRequestCompleted, int PlayerId,
    int InstanceId)
{
    ULootLockerServerPlayerRequest::EquipAssetForPlayerLoadout(PlayerId, InstanceId, OnRequestCompleted, FEquipAssetResponse());
}

void ULootLockerServerManager::UnequipAssetForPlayerLoadout(const FUnequipAssetResponseBP& OnRequestCompleted,
    int PlayerId, int LoadoutId)
{
    ULootLockerServerPlayerRequest::UnequipAssetForPlayerLoadout(PlayerId, LoadoutId, OnRequestCompleted, FUnequipAssetResponse());
}

void ULootLockerServerManager::LookupPlayerNames(FLookupPlayerNamesResponseBP const& OnRequestCompleted, FLookupPlayerNamesQuery const& Query)
{
    ULootLockerServerPlayerRequest::LookupPlayerNames(Query, OnRequestCompleted);
}

void ULootLockerServerManager::GetPersistentStorage(const FGetPersistentStorageResponseBP& OnRequestCompleted,
    TArray<int> const &PlayerIds)
{
    ULootLockerServerStorageRequest::GetPersistentStorage(PlayerIds, OnRequestCompleted, FGetPersistentStorageResponse());
}

void ULootLockerServerManager::UpdatePersistentStorage(const FUpdatePersistentStorageResponseBP& OnCompletedRequest,
    FLootLockerServerPersistentStorageRequestData RequestData)
{
    ULootLockerServerStorageRequest::UpdatePersistentStorage(RequestData, OnCompletedRequest, FUpdatePersistentStorageResponse());
}

void ULootLockerServerManager::GetPlayerCharacters(const FCharactersResponseBP& OnCompletedRequestBP, int PlayerId)
{
    ULootLockerServerCharacterRequest::GetPlayerCharacters(PlayerId, OnCompletedRequestBP, FCharactersResponse());
}

void ULootLockerServerManager::GetInventoryToCharacter(const FCharacterInventoryResponseBP& OnCompletedRequestBP, int PlayerId,
    int CharacterId)
{
    ULootLockerServerCharacterRequest::GetInventoryToCharacter(PlayerId, CharacterId, OnCompletedRequestBP, FServerCharacterInventoryResponse());
}

void ULootLockerServerManager::GetCharacterLoadout(const FCharacterLoadoutResponseBP& OnCompletedRequestBP,
    int PlayerId, int CharacterId)
{
    ULootLockerServerCharacterRequest::GetCharacterLoadout(PlayerId, CharacterId, OnCompletedRequestBP, FServerCharacterLoadoutResponse());
}

void ULootLockerServerManager::EquipAssetForCharacterLoadout(const FEquipResponseBP& OnCompletedRequestBP, int PlayerId,
    int CharacterId, int InstanceId)
{
    ULootLockerServerCharacterRequest::EquipAssetForCharacterLoadout(PlayerId, CharacterId, InstanceId, OnCompletedRequestBP, FEquipResponse());
}

void ULootLockerServerManager::UnequipAssetForCharacterLoadout(const FUnequipResponseBP& OnCompletedRequestBP,
    int PlayerId, int CharacterId, int InstanceId)
{
    ULootLockerServerCharacterRequest::UnequipAssetForCharacterLoadout(PlayerId, CharacterId, InstanceId, OnCompletedRequestBP, FUnequipResponse());
}

void ULootLockerServerManager::GetPlayerHeroes(const FHeroesResponseBP& OnCompletedRequestBP, int PlayerId)
{
    ULootLockerServerHeroesRequest::GetPlayerHeroes(PlayerId, OnCompletedRequestBP, FServerHeroesResponse());
}

void ULootLockerServerManager::GetInventoryToHero(const FHeroInventoryResponseBP& OnCompletedRequestBP, int PlayerId,
    int HeroId)
{
    ULootLockerServerHeroesRequest::GetInventoryToHero(PlayerId, HeroId, OnCompletedRequestBP, FServerHeroInventoryResponse());
}

void ULootLockerServerManager::GetHeroLoadout(const FHeroLoadoutResponseBP& OnCompletedRequestBP,
    int PlayerId, int HeroId)
{
    ULootLockerServerHeroesRequest::GetHeroLoadout(PlayerId, HeroId, OnCompletedRequestBP, FServerHeroLoadoutResponse());
}

void ULootLockerServerManager::EquipAssetForHeroLoadout(const FEquipHeroResponseBP& OnCompletedRequestBP, int PlayerId,
    int HeroId, int InstanceId)
{
    ULootLockerServerHeroesRequest::EquipAssetForHeroLoadout(PlayerId, HeroId, InstanceId, OnCompletedRequestBP, FEquipHeroResponse());
}

void ULootLockerServerManager::UnequipAssetForHeroLoadout(const FUnequipHeroResponseBP& OnCompletedRequestBP,
    int PlayerId, int HeroId, int InstanceId)
{
    ULootLockerServerHeroesRequest::UnequipAssetForHeroLoadout(PlayerId, HeroId, InstanceId, OnCompletedRequestBP, FUnequipHeroResponse());
}

void ULootLockerServerManager::InvokeTriggerOnBehalfOfPlayer(const FInvokeTriggerResponseBP& OnCompletedRequestBP,
    FString Name, int PlayerId)
{
    ULootLockerServerTriggerRequest::InvokeTriggerOnBehalfOfPlayer(Name, PlayerId, OnCompletedRequestBP, FInvokeTriggerResponse());
}

void ULootLockerServerManager::ListFilesForPlayer(const FListFilesForPlayerResponseBP& OnCompletedRequestBP, int PlayerId)
{
    ULootLockerServerFilesRequest::ListFilesForPlayer(PlayerId, OnCompletedRequestBP);
}

void ULootLockerServerManager::GetFileByIdForPlayer(const FGetFileByIdForPlayerResponseBP& OnCompletedRequestBP, int PlayerId, int FileId)
{
    ULootLockerServerFilesRequest::GetFileByIdForPlayer(PlayerId, FileId, OnCompletedRequestBP);
}

void ULootLockerServerManager::UploadFileForPlayer(const FUploadFileForPlayerResponseBP& OnCompletedRequestBP, int PlayerId, const FString& FilePath, const FString& Purpose)
{
    ULootLockerServerFilesRequest::UploadFileForPlayer(PlayerId, FilePath, Purpose, OnCompletedRequestBP);
}

void ULootLockerServerManager::DeleteFileForPlayer(const FDeleteFileForPlayerResponseBP& OnCompletedRequestBP, int PlayerId, int FileId)
{
    ULootLockerServerFilesRequest::DeleteFileForPlayer(PlayerId, FileId, OnCompletedRequestBP);
}

 void ULootLockerServerManager::CreateLeaderboard(const FLootLockerServerCreateLeaderboardRequest& CreateLeaderboardRequest, const FLootLockerServerCreateLeaderboardResponseBP& OnCompletedRequestBP )
 {
     ULootLockerServerLeaderboardRequest::CreateLeaderboard(CreateLeaderboardRequest, OnCompletedRequestBP, FLootLockerServerCreateLeaderboardResponseDelegate());
 }

 void ULootLockerServerManager::UpdateLeaderboard(const FLootLockerServerUpdateLeaderboardRequest& UpdateLeaderboardRequests, int LeaderboardId, const FLootLockerServerUpdateLeaderboardResponseBP& OnCompletedRequestBP)
 {
     ULootLockerServerLeaderboardRequest::UpdateLeaderboard(UpdateLeaderboardRequests, LeaderboardId, OnCompletedRequestBP, FLootLockerServerUpdateLeaderboardResponseDelegate());
 }

 void ULootLockerServerManager::DeleteLeaderboard(int LeaderboardId, const FLootLockerServerDeleteLeaderboardResponseBP& OnCompletedRequestBP )
 {
     ULootLockerServerLeaderboardRequest::DeleteLeaderboard(LeaderboardId, OnCompletedRequestBP, FLootLockerServerDeleteLeaderboardResponseDelegate());
 }

 void ULootLockerServerManager::SubmitScore(FString MemberId, int LeaderboardId, int Score, const FLootLockerServerSubmitScoreResponseBP& OnCompletedRequestBP)
 {
     FLootLockerServerSubmitScoreRequest score = FLootLockerServerSubmitScoreRequest();
     score.member_id = MemberId;
     score.score = Score;

     ULootLockerServerLeaderboardRequest::SubmitScore(score, LeaderboardId, OnCompletedRequestBP, FLootLockerServerSubmitScoreResponseDelegate());
 }

 //void ComputeAndLockDropTable(int TableId, const FLootLockerComputeAndLockDropTableResponseBP& OnCompletedRequestBP)
 //{
 //}

 //void PickDropsFromDropTable(TArray<int> picks, int TableId, const FFLootLockerPickDropsFromDropTableResponseBP& OnCompletedRequestBP)
 //{
 //}