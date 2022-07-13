function OnAccountLoaded(playerid)
{
    cache_get_value_name_int(0, "id", PlayerData[playerid][P_SQLID]);
    SetSpawnInfo(playerid, 0, 1, DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_POS_Z, DEFAULT_POS_A, 0, 0, 0, 0, 0, 0);
    TogglePlayerSpectating(playerid, false);
    return 1;
}

function GetPlayerData(playerid, playerData:data)
{
    return PlayerData[playerid][data];
}