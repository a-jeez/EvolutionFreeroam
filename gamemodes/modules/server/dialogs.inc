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
    if(response)
    {
        if(!strlen(inputtext) || strlen(inputtext) > 24)
        {
            static
                string[512];
                
            format(string, sizeof(string), ""WHITE"Hi "CYAN"%s"WHITE", it seems you're already registered, please type in your password: "GREEN"(input below)", Player_GetName(playerid));
            Dialog_Show(playerid, PlayerLogin, DIALOG_STYLE_PASSWORD, ""SERVER_NAME" Freeroam: Login", string, "Login", "Forgot Password");

            Error(playerid, "Invalid password inputted!");
            return 1;
        }
        static
            query[256];

        mysql_format(Database, query, sizeof(query), "SELECT `password` FROM `accounts` WHERE `name` = '%e' LIMIT 1", Player_GetName(playerid));
        mysql_query(Database, query);

        if(cache_num_rows() > 0)
        {
            static
                hash[BCRYPT_HASH_LENGTH];

            cache_get_value_name(0, "password", hash);
            bcrypt_verify(playerid, "OnAccountPasswordChecked", inputtext, hash);
        }
        cache_unset_active();
    }
    return 1;
}