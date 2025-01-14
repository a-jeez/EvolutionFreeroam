public OnGameModeInit()
{
    SetGameModeText("EVO:FR v1.4.3 Revolution!");
    SendRconCommand("hostname "SERVER_NAME"");
    SendRconCommand("password 0");
    MySQL_Connect();
    return 1;
}

public OnPlayerConnect(playerid)
{
    Iter_Add(Player, playerid);

    PlayLoginMusicForPlayer(playerid);
    TogglePlayerSpectating(playerid, true);
    Login_Timer[playerid] = SetTimerEx("Account_Check", 800, false, "i", playerid);
    SendClientMessage(playerid, X11_LIGHTBLUE, "SERVER: "WHITE"Welcome to"CYAN" "SERVER_NAME);
	SendClientMessage(playerid, X11_LIGHTBLUE, "SERVER: "WHITE" use "YELLOW"/help "WHITE"to view all server commands!");
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    if(Iter_Contains(Player, playerid))
        Iter_Remove(Player, playerid);
    
    SetPlayerVehicleDeathState(playerid, GetPlayerVehicleData(playerid, vehicleData:P_ID), false);
    RemovePlayerVehicle(playerid, GetPlayerVehicleData(playerid, vehicleData:P_ID));

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
    SendClientMessageEx(playerid, -1, INDIANRED1"[SERVER]:"WHITE" You teleported to "INDIANRED1"X: %.2f, Y: %.2f, Z: %.2f", fX, fY, fZ);
    return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
    foreach(new i : Player)
    {
        SetPlayerVehicleDeathState(i, vehicleid, true);
        RemovePlayerVehicle(i, vehicleid);
    }
    return 1;
}

public OnVehicleSpawn(vehicleid)
{
    foreach(new i : Player)
    {
        if(GetPlayerVehicleDeathState(i, vehicleid))
        {
            SetPlayerVehicleDeathState(i, vehicleid, true);
            RemovePlayerVehicle(i, vehicleid);
        }
    }
    return 1;
}
GiveWeaponToPlayer(playerid, weaponid, ammo)
{
	if (weaponid < 0 || weaponid > 46)
	    return 0;
	return GivePlayerWeapon(playerid, weaponid, ammo);
}
forward gmx();
public gmx()
{
    SendRconCommand("gmx");
    return 1;
}
stock SendClientMessageToAllEx(color, const text[], {Float, _}:...)
{
	static
	    args,
	    str[144];

	/*
     *  Custom function that uses #emit to format variables into a string.
     *  This code is very fragile; touching any code here will cause crashing!
	*/
	if ((args = numargs()) == 2)
	{
	    SendClientMessageToAll(color, text);
	}
	else
	{
		while (--args >= 2)
		{
			#emit LCTRL 5
			#emit LOAD.alt args
			#emit SHL.C.alt 2
			#emit ADD.C 12
			#emit ADD
			#emit LOAD.I
			#emit PUSH.pri
		}
		#emit PUSH.S text
		#emit PUSH.C 144
		#emit PUSH.C str
		#emit LOAD.S.pri 8
		#emit ADD.C 4
		#emit PUSH.pri
		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

		SendClientMessageToAll(color, str);

		#emit RETN
	}
	return 1;
}