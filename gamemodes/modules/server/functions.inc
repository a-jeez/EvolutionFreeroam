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

PlayLoginMusicForPlayer(playerid)
{
	new randid = random(sizeof(LoginMusicID));
	PlayerPlaySound(playerid, LoginMusicID[randid], 0.0, 0.0, 0.0);
	return 1;
}

StopSoundForPlayer(playerid)
{
	PlayerPlaySound(playerid, 1069, 0.0, 0.0, 0.0);
	return 1;
}
