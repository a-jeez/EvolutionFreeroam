CMD:goto(playerid, params[])
{
	if(!IsPLayerLoggedIn[playerid])
		return Error(playerid, "You must be spawned to use this");

	new toPlayer;
	if(sscanf(params, "u", toPlayer)) 
		return Usage(playerid, "/goto [PlayerID/Part of Name]");

	if(!Iter_Contains(Player, toPlayer))
		return Error(playerid, "Player is not connected");

	if(!IsPLayerLoggedIn[toPlayer])
		return Error(playerid, "Player is not Logged in");

	new Float:toPlayerPos[3], Float:toPlayerAngle;
	GetPlayerPos(toPlayer, toPlayerPos[0], toPlayerPos[1], toPlayerPos[2]);
	GetPlayerFacingAngle(toPlayer, toPlayerAngle);

	SetPlayerPos(playerid, toPlayerPos[0], toPlayerPos[1], toPlayerPos[2]);
	SetPlayerFacingAngle(playerid, toPlayerAngle);
	SendClientMessageEx(playerid, -1, "You has teleported to "INDIANRED1"%s"WHITE" position", Player_GetName(toPlayer));
	SendClientMessageEx(toPlayer, -1, INDIANRED1"%s"WHITE" has teleported to your position", Player_GetName(playerid));
	return 1;
}

CMD:gethere(playerid, params[])
{
	if(!IsPLayerLoggedIn[playerid])
		return Error(playerid, "You must be spawned to use this");

	new toPlayer;
	if(sscanf(params, "u", toPlayer)) 
		return Usage(playerid, "/gethere [PlayerID/Part of Name]");

	if(!Iter_Contains(Player, toPlayer))
		return Error(playerid, "Player is not connected");

	if(!IsPLayerLoggedIn[toPlayer])
		return Error(playerid, "Player is not Logged in");

	new Float:PlayerPos[3], Float:PlayerAngle;
	GetPlayerPos(playerid, PlayerPos[0], PlayerPos[1], PlayerPos[2]);
	GetPlayerFacingAngle(playerid, PlayerAngle);

	SetPlayerPos(toPlayer, PlayerPos[0], PlayerPos[1], PlayerPos[2]);
	SetPlayerFacingAngle(toPlayer, PlayerAngle);
	SendClientMessageEx(toPlayer, -1, "You has teleported to "INDIANRED1"%s"WHITE" position", Player_GetName(playerid));
	SendClientMessageEx(playerid, -1, INDIANRED1"%s"WHITE" has teleported to your position", Player_GetName(toPlayer));
	return 1;
}

CMD:setskin(playerid, params[])
{
	if(!IsPLayerLoggedIn[playerid])
		return Error(playerid, "You must be spawned to use this");

	new toPlayer, skinid;
	if(sscanf(params, "ud", toPlayer, skinid)) 
		return Usage(playerid, "/setskin [PlayerID/Part of Name] [SkinID]");

	if(!IsValidModel(skinid) && skinid == 0)
		return Error(playerid, "Skin ID must be valid (1 - 311)");

	if(!Iter_Contains(Player, toPlayer))
		return Error(playerid, "Player is not connected");

	if(!IsPLayerLoggedIn[toPlayer])
		return Error(playerid, "Player is not Logged in");

	SetPlayerSkin(toPlayer, skinid);
	SendClientMessageEx(toPlayer, -1, "Your skin has been set to "INDIANRED1"%d"WHITE" by "INDIANRED1"%s", skinid, Player_GetName(playerid));
	return 1;
}
CMD:weap(playerid,params[])
{
    new weapon;
    if(sscanf(params,"k<weapon>",weapon)) return SendClientMessage(playerid, -1, INDIANRED1"USAGE: "WHITE"/weap [weapon name/id]");
    if(weapon == -1 || weapon == 44 || weapon == 45) return Error(playerid,"Invalid weapon!");
    GivePlayerWeapon(playerid,weapon,20000);
	return 1;
}
CMD:jetpack(playerid,params[])
{
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USEJETPACK);
	return 1;
}
CMD:godmode(playerid,params[])
{
	GodMode[playerid] = !(GodMode[playerid]);
	if(GodMode[playerid]) SendClientMessage(playerid,X11_LIGHTBLUE,"GODMODE: "WHITE"Godmode "GREEN"enabled");
	else
	{
		SetPlayerHealth(playerid,100.0);
		SendClientMessage(playerid,X11_LIGHTBLUE,"GODMODE: "WHITE"Godmode "RED"disabled");
	}
	return 1;
}
CMD:jumpmode(playerid,params[])
{
	JumpMode[playerid] = !(JumpMode[playerid]);
	if(JumpMode[playerid])
	{
		SendClientMessage(playerid,X11_LIGHTBLUE,"SERVER: "WHITE"Jump mode "GREEN"enabled!");
		SendClientMessage(playerid,X11_LIGHTBLUE,"HINT: "WHITE"Press "YELLOW"~k~~PED_JUMPING~ "WHITE"while on foot to jump higher!");
		SendClientMessage(playerid,X11_LIGHTBLUE,"HINT: "WHITE"Press "YELLOW"~k~~VEHICLE_HORN~  "WHITE"while driving to jump vehicle!");
	}
	else SendClientMessage(playerid,X11_LIGHTBLUE,"SERVER: "WHITE"Jump mode "RED"disabled!");
	return 1;
}
CMD:help(playerid)
{
	// Gaada si andy mau nambahin katanya :v
	return true;
}