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

SendClientMessageEx(playerid, color, const str[], {Float,_}:...)
{
    static args, start, end,string[200];
    #emit LOAD.S.pri 8
    #emit STOR.pri args

    if (args > 12)
    {
        #emit ADDR.pri str
        #emit STOR.pri start

        for (end = start + (args - 12); end > start; end -= 4)
        {
            #emit LREF.pri end
            #emit PUSH.pri
        }
        #emit PUSH.S str
        #emit PUSH.C 156
        #emit PUSH.C string
        #emit PUSH.C args
        #emit SYSREQ.C format

        SendClientMessage(playerid, color, string);

        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    return SendClientMessage(playerid, color, str);
}

IsValidModel(modelid)
{
    if(modelid >= 0 && modelid <= 311) { // skin
        return 1;
    }
    else if(modelid >= 400 && modelid <= 612) { // vehicle
        return 1;
    }
    return 0;
}

IsValidWeapon(weaponid)
{
    if(weaponid >= 0 && weaponid <= 46) { 
        return 1;
    }
    return 0;
}

GivePlayerWeaponEx(playerid, setid)
{
    ResetPlayerWeapons(playerid); // clear player weapon

    switch(setid)
    {
        case 1:
        {
            GivePlayerWeapon(playerid, 1, 1);
            GivePlayerWeapon(playerid, 5, 99999);
            GivePlayerWeapon(playerid, 18, 99999);
            GivePlayerWeapon(playerid, 22, 99999);
            GivePlayerWeapon(playerid, 25, 99999);
            GivePlayerWeapon(playerid, 28, 99999);
            GivePlayerWeapon(playerid, 30, 99999);
            GivePlayerWeapon(playerid, 35, 99999);
            GivePlayerWeapon(playerid, 41, 99999);
            SetPlayerArmedWeapon(playerid, 28);
        }
        case 2:
        {
            GivePlayerWeapon(playerid, 4, 1);
            GivePlayerWeapon(playerid, 24, 99999);
            GivePlayerWeapon(playerid, 26, 99999);
            GivePlayerWeapon(playerid, 32, 99999);
            GivePlayerWeapon(playerid, 34, 99999);
            GivePlayerWeapon(playerid, 37, 99999);
            GivePlayerWeapon(playerid, 16, 99999);
            GivePlayerWeapon(playerid, 42, 99999);
            SetPlayerArmedWeapon(playerid, 24);
        }
        case 3:
        {
            GivePlayerWeapon(playerid, 9, 1);
            GivePlayerWeapon(playerid, 23, 99999);
            GivePlayerWeapon(playerid, 27, 99999);
            GivePlayerWeapon(playerid, 31, 99999);
            GivePlayerWeapon(playerid, 29, 99999);
            GivePlayerWeapon(playerid, 33, 99999);
            GivePlayerWeapon(playerid, 35, 99999);
            GivePlayerWeapon(playerid, 36, 99999);
            SetPlayerArmedWeapon(playerid, 31);
        }
    }
}