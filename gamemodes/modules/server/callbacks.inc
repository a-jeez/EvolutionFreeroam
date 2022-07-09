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
    IsPLayerLoggedIn[playerid] = false;
    StopSoundForPlayer(playerid);
    return 1;
}

public OnPlayerSpawn(playerid)
{
    IsPLayerLoggedIn[playerid] = true;
    StopSoundForPlayer(playerid);
    return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    new Float:PlayerAngle;
    GetPlayerFacingAngle(playerid, PlayerAngle);

    SetPlayerPos(playerid, fX, fY, fZ);
    SetPlayerFacingAngle(playerid, PlayerAngle);
    SendClientMessageEx(playerid, -1, ORANGERED1"[SERVER]:"WHITE" You teleported to "ORANGERED1"X: %.2f, Y: %.2f, Z: %.2f", fX, fY, fZ);
    return 1;
}