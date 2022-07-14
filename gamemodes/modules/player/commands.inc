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

	new otherid, skinid;
	if(sscanf(params, "ud", otherid, skinid)) 
		return Usage(playerid, "/setskin [playerid/part of name][SkinID]");

	if(!IsValidModel(skinid) && skinid == 0)
		return Error(playerid, "Skin ID must be valid (1 - 311)");

	SetPlayerSkin(otherid, skinid);
	SendClientMessageEx(playerid, -1, "Your skin has been set to "INDIANRED1"%d", skinid);
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
	SendClientMessage(playerid, X11_LIGHTBLUE, "SERVER: "WHITE"/godmode /jumpmode /delveh /veh");
	SendClientMessage(playerid, X11_LIGHTBLUE, "SERVER: "WHITE"/stats /help /fixveh /goto /givewep");
	SendClientMessage(playerid, X11_LIGHTBLUE, "SERVER: "WHITE"/gethere /setskin /jetpack");
	SendClientMessage(playerid, X11_LIGHTBLUE, "SERVER: "WHITE"/setcarhp /respawnall");
	return true;
}
CMD:stats(playerid, params[])
{
	SendClientMessageEx(playerid, X11_LIGHTBLUE, "SERVER: "WHITE"Name: "YELLOW"%s", ReturnPlayerName(playerid));
	SendClientMessageEx(playerid, X11_LIGHTBLUE, "SERVER: "WHITE"Your SQL ID: "YELLOW"%d", PlayerData[playerid][P_SQLID]);
	return true;
}
CMD:id(playerid, params[])
{
	static
	userid;
	if (isnull(params))
	    return SendClientMessage(playerid, -1, "/id [playerid/name]");

	if (strlen(params) < 3)
		return Error(playerid, "You must specify at least 3 characters.");

	new count;

	foreach (new i : Player)
	{
	    if (strfind(ReturnPlayerName(i), params, true) != -1)
	    {
	       // SendClientMessageEx(playerid, COLOR_WHITE, "** %s - ID: %d", ReturnName(i), i);
			SendClientMessageEx(playerid, X11_LIGHTBLUE, "SERVER: "WHITE"Name: %s, ID: %d, Client: %s", ReturnPlayerName(userid), userid, GetPlayerVersion(i));
	        count++;
		}
	}
	if (!count)
	    return SendClientMessageEx(playerid, -1, RED"No users matched the search criteria: \"%s\".", params);

	return true;
}
CMD:restart(playerid, params[])
{
	#pragma unused params
	if(!IsPlayerAdmin(playerid))
		return Error(playerid, "You not admin! (Not logged in to rcon)");
	else
	{
		SendClientMessageToAllEx(-1, INDIANRED1"SERVER: Admin %s has initiate server restart", GetPlayerName(playerid));
		SetTimer("gmx", 15000, false);
		SendRconCommand("hostname E:FR | Restarting");
		SendRconCommand("password abclimadasar");
		return 1;
	}
	return 1;
}