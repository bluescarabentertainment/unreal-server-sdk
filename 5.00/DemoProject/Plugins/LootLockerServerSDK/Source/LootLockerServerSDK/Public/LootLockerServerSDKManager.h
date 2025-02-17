// Copyright (c) 2021 LootLocker

#pragma once

#include "CoreMinimal.h"
#include "ServerAPI/LootLockerServerAssetRequest.h"
#include "ServerAPI/LootLockerServerAssetInstanceRequest.h"
#include "ServerAPI/LootLockerServerAuthRequest.h"
#include "ServerAPI/LootLockerServerCharacterRequest.h"
#include "ServerAPI/LootLockerServerFilesRequest.h"
#include "ServerAPI/LootLockerServerHeroesRequest.h"
#include "ServerAPI/LootLockerServerPlayerRequest.h"
#include "ServerAPI/LootLockerServerStorageRequest.h"
#include "ServerAPI/LootLockerServerTriggerRequest.h"
#include "ServerAPI/LootLockerServerLeaderboardRequest.h"


#include "LootLockerServerSDKManager.generated.h"

UCLASS(Blueprintable)
class LOOTLOCKERSERVERSDK_API ULootLockerServerSDKManager : public UObject
{
	GENERATED_BODY()

public:
    
    //==================================================
    //Authentication
    //==================================================
    
    /**
     * Register a session.
     * @param OnCompletedRequest - callback to be invoked with the server response.
     * @see https://ref.lootlocker.com/server-api/#registering-a-server-session
     */
	static void StartSession(const FServerAuthResponse& OnCompletedRequest);

	/**
	 * Maintain the server session.
	 * @param OnCompletedRequest - callback to be invoked with the server response.
	 * @see https://ref.lootlocker.com/server-api/#maintaining-a-server-session
	 */
    static void MaintainSession(const FServerPingResponse& OnCompletedRequest);

	/**
	* Get all assets in a paginated form.
	*
	* @param OnCompletedRequest - callback to be invoked with the server response.
	* @param StartFromIndex - index of the item to start from.
	* @param ItemsCount - number of items to receive (50-200).
	* @param AssetFilter - optional filter.
	* @param IncludeUGC - whether to include UGC Assets.
	* @see https://ref.lootlocker.com/server-api/#get-assets-to-game
	*/
	static void GetAssetsToGame(const FServerAssetsResponseDelegate& OnCompletedRequest, int StartFromIndex = 0, int ItemsCount = 50, ELootLockerServerAssetFilter AssetFilter = ELootLockerServerAssetFilter::None, bool IncludeUGC = false);

	/**
	* Get all key/value pairs for an asset instance.
	*
	* @param PlayerId - Player identifier.
	* @param AssetInstanceId - AssetInstance identifier.
	* @param OnCompletedRequest - callback to be invoked with the server response.
	* @see https://ref.lootlocker.com/server-api/#getting-all-key-value-pairs-to-an-instance
	*/
	static void GetAllKeyValuePairsForAssetInstance(int PlayerId, int AssetInstanceId,
		const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());

	/**
	* Update one or more key/value pairs by id.
	*
	* @param PlayerId - Player identifier.
	* @param AssetInstanceId - AssetInstance identifier.
	* @param Pairs - The pairs to update.
	* @param OnCompletedRequest - callback to be invoked with the server response.
	* @see https://ref.lootlocker.com/server-api/#updating-one-or-more-key-value-pairs
	*/
	static void UpdateKeyValuePairsForAssetInstance(int PlayerId, int AssetInstanceId, const TArray<FLootLockerServerAssetInstanceStorageItem>& Pairs,
		const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());

	/**
	* Create key/value pairs for an asset instance.
	*
	* @param PlayerId - Player identifier.
	* @param AssetInstanceId - AssetInstance identifier.
	* @param Pair - The new key and value.
	* @param OnCompletedRequest - callback to be invoked with the server response.
	* @see https://ref.lootlocker.com/server-api/#creating-a-key-value-pair
	*/
	static void CreateKeyValuePairForAssetInstance(int PlayerId, int AssetInstanceId, const FLootLockerServerAssetInstanceStorageItem& Pair,
		const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());

	/**
	* Get a key/value pair for an asset instance.
	*
	* @param PlayerId - Player identifier.
	* @param AssetInstanceId - AssetInstance identifier.
	* @param PairId - The identifier of the pair to read.
	* @param OnCompletedRequest - callback to be invoked with the server response.
	* @see https://ref.lootlocker.com/server-api/#getting-a-key-value-pair-by-id
	*/
	static void GetKeyValuePairForAssetInstance(int PlayerId, int AssetInstanceId, int PairId,
		const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());

	/**
	* Update a key/value pair by id.
	*
	* @param PlayerId - Player identifier.
	* @param AssetInstanceId - AssetInstance identifier.
	* @param PairId - The identifier of the pair to update.
	* @param Pair - The new key and value.
	* @param OnCompletedRequest - callback to be invoked with the server response.
	* @see https://ref.lootlocker.com/server-api/#updating-a-key-value-pair-by-id
	*/
	static void UpdateKeyValuePairForAssetInstance(int PlayerId, int AssetInstanceId, int PairId, const FLootLockerServerAssetInstanceStorageItem& Pair,
		const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());

	/**
	* Delete a key/value pair for an asset instance.
	*
	* @param PlayerId - Player identifier.
	* @param AssetInstanceId - AssetInstance identifier.
	* @param PairId - The identifier of the pair to delete.
	* @see https://ref.lootlocker.com/server-api/#delete-a-key-value-pair
	* @param OnCompletedRequest - callback to be invoked with the server response.
	*/
	static void DeleteKeyValuePairForAssetInstance(int PlayerId, int AssetInstanceId, int PairId,
		const FLootLockerServerAssetInstanceStorageItemsResponseDelegate& OnCompletedRequest = FLootLockerServerAssetInstanceStorageItemsResponseDelegate());

	/**
	* Get a paginated list of the players inventory.
	* @param OnGetInventoryRequestCompleted - callback to be invoked with the server response
	* @param StartFromIndex - index of the item to start from
	* @param ItemsCount - number of items to receive (50-200)
	* https://docs.lootlocker.io/server-api/#get-player-inventory
	*/
    static void GetInventory(const FServerInventoryResponse& OnGetInventoryRequestCompleted, int PlayerId, int StartFromIndex = 0, int ItemsCount = 50);

	/**
	 * Grant an asset to a player as you see fit
	 * @param OnAddAssetRequestCompleted - callback to be invoked with the server response
	 * @param PlayerId - Player identifier
	 * @param AddAssetData - Data about the asset to be added
	 * https://docs.lootlocker.io/server-api/#add-asset-to-player-inventory
	 */
	static void AddAssetToPlayerInventory(const FAddAssetResponse& OnAddAssetRequestCompleted, int PlayerId, FLootLockerServerAddAssetData AddAssetData);

	/**
	 * Add or remove assets from a player's inventory
	 * @param OnAlterInventoryRequestCompleted - callback to be invoked with the server response
	 * @param PlayerId - Player identifier
	 * @param AlterInventoryData - Data about the assets added or removed
	 * https://ref.lootlocker.io/server-api/#alter-player-inventory
	 */
	static void AlterPlayerInventory(const FAlterInventoryResponse& OnAlterInventoryRequestCompleted, int PlayerId, FLootLockerServerAlterInventoryRequestData AlterInventoryData);

	/**
	 * Return the players default characters loadout
	 * @param OnGetPlayerLoadoutRequestCompleted - callback to be invoked with the server response
	 * @param PlayerId - Player identifier
	 * https://docs.lootlocker.io/server-api/#get-player-loadout
	 */ 
	static void GetPlayerLoadout(const FGetPlayerLoadoutResponse& OnGetPlayerLoadoutRequestCompleted, int PlayerId);

	/**
     * Equip an asset instance to the players default character
     * @param OnRequestCompleted - callback to be invoked with the server response
     * @param PlayerId - Player identifier
     * @param InstanceId - Asset id
	 * https://docs.lootlocker.io/server-api/#equip-asset-for-player-loadout
	 */ 
	static void EquipAssetForPlayerLoadout(const FEquipAssetResponse& OnRequestCompleted, int PlayerId, int InstanceId);

	/**
	 * Unequip an asset instance for the players default character
	 * @param OnRequestCompleted - callback to be invoked with the server response
	 * @param PlayerId - Player identifier
	 * @param LoadoutId - Asset id
	 * https://docs.lootlocker.io/server-api/#equip-asset-for-player-loadout
	*/ 
	static void UnequipAssetForPlayerLoadout(const FUnequipAssetResponse& OnRequestCompleted, int PlayerId, int LoadoutId);

	/**
	 * Read player storage one or more players
	 * @param OnRequestCompleted - callback to be invoked with the server response
	 * @param PlayerIds - array of player ids
	 * https://docs.lootlocker.io/server-api/#player-persistent-storage
	 */
	static void GetPersistentStorage(const FGetPersistentStorageResponse& OnRequestCompleted, TArray<int> PlayerIds);

	/**
	 * Update Persistent Storage
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param RequestData - payload
	 * https://docs.lootlocker.io/server-api/#update-persistent-storage
	 */ 
    static void UpdatePersistentStorage(const FUpdatePersistentStorageResponse& OnCompletedRequest, FLootLockerServerPersistentStorageRequestData RequestData);

	/**
	 * List characters to a player
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param PlayerId - player identifier
	 * https://docs.lootlocker.io/server-api/#get-player-characters
	 */
    static void GetPlayerCharacters(const FCharactersResponse& OnCompletedRequest, int PlayerId);

	/**
	 * Get the inventory for a specific character belonging to a player
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param PlayerId - player identifier
	 * @param CharacterId - character identifier
	 * https://docs.lootlocker.io/server-api/#get-inventory-to-character
	 */
    static void GetInventoryToCharacter(const FServerCharacterInventoryResponse& OnCompletedRequest, int PlayerId, int CharacterId);

	/**
	 * Get a characters full loadout.
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param PlayerId - player identifier
	 * @param CharacterId - character identifier 
	 * https://docs.lootlocker.io/server-api/#get-character-loadout
	 */
    static void GetCharacterLoadout(const FServerCharacterLoadoutResponse& OnCompletedRequest, int PlayerId, int CharacterId);

	/**
	 * Equip an asset instance to a specific character
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param PlayerId - player identifier
	 * @param CharacterId - character identifier 
	 * @param InstanceId - instance identifier 
	 * https://docs.lootlocker.io/server-api/#equip-asset-for-character-loadout
	 */
    static void EquipAssetForCharacterLoadout(const FEquipResponse& OnCompletedRequest, int PlayerId, int CharacterId, int InstanceId);

	/**
	 * Unequip an asset instance for a character
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param PlayerId - player identifier
	 * @param CharacterId - character identifier 
	 * @param InstanceId - instance identifier
	 * https://docs.lootlocker.io/server-api/#unequip-asset-for-character-loadout
	 */
    static void UnequipAssetForCharacterLoadout(const FUnequipResponse& OnCompletedRequest, int PlayerId, int CharacterId, int InstanceId);

	/**
	 * List heroes to a player
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param PlayerId - player identifier
	 * https://docs.lootlocker.io/server-api/#get-player-heroes
	 */
    static void GetPlayerHeroes(const FServerHeroesResponse& OnCompletedRequest, int PlayerId);

	/**
	 * Get the inventory for a specific hero belonging to a player
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param PlayerId - player identifier
	 * @param HeroId - hero identifier
	 * https://docs.lootlocker.io/server-api/#get-inventory-to-hero
	 */
    static void GetInventoryToHero(const FServerHeroInventoryResponse& OnCompletedRequest, int PlayerId, int HeroId);

	/**
	 * Get a heroes full loadout.
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param PlayerId - player identifier
	 * @param HeroId - hero identifier 
	 * https://docs.lootlocker.io/server-api/#get-hero-loadout
	 */
    static void GetHeroLoadout(const FServerHeroLoadoutResponse& OnCompletedRequest, int PlayerId, int HeroId);

	/**
	 * Equip an asset instance to a specific hero
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param PlayerId - player identifier
	 * @param HeroId - hero identifier 
	 * @param InstanceId - instance identifier 
	 * https://docs.lootlocker.io/server-api/#equip-asset-for-hero-loadout
	 */
    static void EquipAssetForHeroLoadout(const FEquipHeroResponse& OnCompletedRequest, int PlayerId, int HeroId, int InstanceId);

	/**
	 * Unequip an asset instance for a hero
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param PlayerId - player identifier
	 * @param HeroId - hero identifier 
	 * @param InstanceId - instance identifier
	 * https://docs.lootlocker.io/server-api/#unequip-asset-for-hero-loadout
	 */
    static void UnequipAssetForHeroLoadout(const FUnequipHeroResponse& OnCompletedRequest, int PlayerId, int HeroId, int InstanceId);

	/**
	 * Invoke a trigger on behalf of a player
	 * @param OnCompletedRequest - callback to be invoked with the server response
	 * @param Name - trigger name 
	 * @param PlayerId - player identifier 
	 * https://docs.lootlocker.io/server-api/#invoke-trigger-on-behalf-of-player
	 */ 
    static void InvokeTriggerOnBehalfOfPlayer(const FInvokeTriggerResponse& OnCompletedRequest, FString Name, int PlayerId);

	/**
	* Lookup multiple player names using IDs
	*/
	static void LookupPlayerNames(const FLookupPlayerNamesDelegate& OnCompletedRequest, struct FLookupPlayerNamesQuery Query);

	//==================================================
    //Leaderboard
    //==================================================

     /**
    * Get rank for single member for a leaderboard. If leaderboard is of type player a player will also be in the response.
    *
    * @param LeaderboardId - the id of the leaderboard you need to connect to.
    * @param MemberId - the id of player in the leaderboard
    *
    * https://ref.lootlocker.io/game-api/#get-member-rank
    */
    static void CreateLeaderboard(const FLootLockerServerCreateLeaderboardRequest& CreateLeaderboardRequest, const FLootLockerServerCreateLeaderboardResponseDelegate& OnCompletedRequest);


    /**
   * Get ranks for list of members for a leaderboard. This can be helpful when getting a players friends on leaderboard.
   * If leaderboard is of type player a player will also be in the response.
   * @param Members - the ids of all leaderboard members you need to get info on.
   *
   * https://ref.lootlocker.io/game-api/#get-by-list-of-members
   */
    static void UpdateLeaderboard(const FLootLockerServerUpdateLeaderboardRequest& UpdateLeaderboardRequests, int LeaderboardId, const FLootLockerServerUpdateLeaderboardResponseDelegate& OnCompletedRequest);

    /**
   * Get list of members in rank range. Result is sorted by rank ascending.
   * Maximum allowed members to query for at a time is currently 2000. If leaderboard is of type player a player will also be in the response.
   * @param LeaderboardId - the id of the leaderboard you need to connect to.
   * @param Count - Number of members returned per page
   * @param After - Curser for pagination, a cursor will be returned in the response
   *
   * https://ref.lootlocker.io/game-api/#get-score-list
   */
    static void DeleteLeaderboard(int LeaderboardId, const FLootLockerServerDeleteLeaderboardResponseDelegate& OnCompletedRequest);

    /**
   * Submit scores for member on leaderboard.
   * @param LeaderboardId - the id of the leaderboard you need to connect to.
   * @param MemberId - the id of player in the leaderboard.
   * @param Score - the score to be submitted.
   *
   * https://ref.lootlocker.io/game-api/#submit-scorem
   */
    static void SubmitScore(FString MemberId, int LeaderboardId, int Score, const FLootLockerServerSubmitScoreResponseDelegate& OnCompletedRequest);

	//==================================================
	//Player Files
	//==================================================

	static void ListFilesForPlayer(int PlayerId, const FServerListFilesForPlayerResponseDelegate& OnCompletedRequest);
	static void GetFileByIdForPlayer(int PlayerId, int FileId, const FServerGetFileByIdForPlayerResponseDelegate& OnCompletedRequest);
	static void DeleteFileForPlayer(int PlayerId, int FileId, const FServerDeleteFileForPlayerResponseDelegate& OnCompletedRequest);
	static void UploadFileForPlayer(int PlayerId, const FString& FileName, const FString& Purpose, const FServerUploadFileForPlayerResponseDelegate& OnCompletedRequest);
};
