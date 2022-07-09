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

stock SendClientMessageEx(playerid, color, const str[], {Float,_}:...)
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