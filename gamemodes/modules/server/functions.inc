Player_GetName(playerid)
{
	new 
		returnNames[MAX_PLAYER_NAME + 1];

	GetPlayerName(playerid, returnNames, sizeof(returnNames));
	return returnNames;
}

Player_Kick(playerid)
{
	SetTimerEx("FixKick", 350, false, "i", playerid);
	return 1;
}