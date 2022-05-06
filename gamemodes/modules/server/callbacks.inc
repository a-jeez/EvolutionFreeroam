public OnGameModeInit()
{
    MySQL_Connect();
    return 1;
}

public OnPlayerConnect(playerid)
{
    TogglePlayerSpectating(playerid, true);
    Login_Timer[playerid] = SetTimerEx("Account_Check", 800, false, "i", playerid);
    return 1;
}

