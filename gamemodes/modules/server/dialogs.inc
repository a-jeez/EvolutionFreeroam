Dialog:PlayerRegister(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(strlen(inputtext) < 5 || strlen(inputtext) > 24)
        {
            static
                string[512];
    
            format(string, sizeof(string), ""WHITE"Hi "CYAN"%s"WHITE", it appears to be your first time around, welcome!\nPlease type in a password for your account below: "GREEN"(input below)\n\n"YELLOW"NOTE: You can play with guest account!", Player_GetName(playerid));
            Dialog_Show(playerid, PlayerRegister, DIALOG_STYLE_INPUT, ""SERVER_NAME" Freeroam: Register", string, "Register", "Guest");

            Error(playerid, "Invalid password, password can't be below than 5 or more than 24 word!");
            return 1;
        }
        bcrypt_hash(playerid, "OnAccountPasswordHashed", inputtext, BCRYPT_COST, "i", playerid);
    }
    else
    {
        static
            player_name[24];

        format(player_name, sizeof(player_name), "%s_tmp%d", Player_GetName(playerid), Random(1, 999));
        SetPlayerName(playerid, player_name);
        SendClientMessage(playerid, X11_LIGHTBLUE, "SERVER: "WHITE"You have chosen to use a guest account.");
    }
    return 1;
}

Dialog:PlayerLogin(playerid, response, listitem, inputtext[])
{
    return 1;
}