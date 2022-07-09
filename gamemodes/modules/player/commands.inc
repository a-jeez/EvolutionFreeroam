CMD:goto(playerid, params[])
{
	if(!IsPLayerLoggedIn[playerid])
		return Error(playerid, "You must be spawned to use this");

	new toPlayer;
	if(sscanf(params, "u", toPlayer)) 
		return Usage(playerid, "/goto [PlayerID/Part of Name]");

	if(!IsPLayerLoggedIn[toPlayer])
		return Error(playerid, "Player is not connected");

	new Float:toPlayerPos[3], Float:toPlayerAngle;
	GetPlayerPos(toPlayer, toPlayerPos[0], toPlayerPos[1], toPlayerPos[2]);
	GetPlayerFacingAngle(toPlayer, toPlayerAngle);

	SetPlayerPos(playerid, toPlayerPos[0], toPlayerPos[1], toPlayerPos[2]);
	SetPlayerFacingAngle(playerid, toPlayerAngle);
	SendClientMessageEx(playerid, -1, "You has teleported to "ORANGERED1"%s"WHITE" position", Player_GetName(toPlayer));
	SendClientMessageEx(toPlayer, -1, ORANGERED1"%s"WHITE" has teleported to your position", Player_GetName(playerid));
	return 1;
}

CMD:gethere(playerid, params[])
{
	if(!IsPLayerLoggedIn[playerid])
		return Error(playerid, "You must be spawned to use this");

	new toPlayer;
	if(sscanf(params, "u", toPlayer)) 
		return Usage(playerid, "/gethere [PlayerID/Part of Name]");

	if(!IsPLayerLoggedIn[toPlayer])
		return Error(playerid, "Player is not connected");

	new Float:PlayerPos[3], Float:PlayerAngle;
	GetPlayerPos(playerid, PlayerPos[0], PlayerPos[1], PlayerPos[2]);
	GetPlayerFacingAngle(playerid, PlayerAngle);

	SetPlayerPos(toPlayer, PlayerPos[0], PlayerPos[1], PlayerPos[2]);
	SetPlayerFacingAngle(toPlayer, PlayerAngle);
	SendClientMessageEx(toPlayer, -1, "You has teleported to "ORANGERED1"%s"WHITE" position", Player_GetName(playerid));
	SendClientMessageEx(playerid, -1, ORANGERED1"%s"WHITE" has teleported to your position", Player_GetName(toPlayer));
	return 1;
}

CMD:setskin(playerid, params[])
{
	if(!IsPLayerLoggedIn[playerid])
		return Error(playerid, "You must be spawned to use this");

	new toPlayer, skinid;
	if(sscanf(params, "ud", toPlayer, skinid)) 
		return Usage(playerid, "/gethere [PlayerID/Part of Name] [SkinID]");

	if(skinid < 1 && skinid > 311)
		return Error(playerid, "Skin ID must be invalid (1 - 311)");

	if(!IsPLayerLoggedIn[toPlayer])
		return Error(playerid, "Player is not connected");

	SetPlayerSkin(toPlayer, skinid);
	SendClientMessageEx(toPlayer, -1, "Your skin has been set to "ORANGERED1"%d"WHITE" by "ORANGERED1"%s", skinid, Player_GetName(playerid));
	return 1;
}