public OnGameModeInit()
{
    MySQL_Connect();
    return 1;
}

public OnPlayerConnect(playerid)
{
    PlayLoginMusicForPlayer(playerid);
    TogglePlayerSpectating(playerid, true);
    Login_Timer[playerid] = SetTimerEx("Account_Check", 800, false, "i", playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    StopSoundForPlayer(playerid);
    return 1;
}

public OnPlayerSpawn(playerid)
{
    StopSoundForPlayer(playerid);
    return 1;
}
