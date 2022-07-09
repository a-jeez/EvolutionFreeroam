static 
    p_MysqlRaceCheck[MAX_PLAYERS];

function Account_Check(playerid)
{
    static
        query[256];

    p_MysqlRaceCheck[playerid]++;
    mysql_format(Database, query, sizeof(query), "SELECT * FROM `accounts` WHERE `name` = '%e' LIMIT 1", Player_GetName(playerid));
    mysql_tquery(Database, query, "OnAccountRespond", "ii", playerid, p_MysqlRaceCheck[playerid]);
}

function OnAccountRespond(playerid, race_check)
{
    static
        string[512];

    if(race_check != p_MysqlRaceCheck[playerid]) return Error(playerid, "An unexpected error has been occured, please relogin!"), Player_Kick(playerid);
    if(cache_num_rows() > 0)
    {
        format(string, sizeof(string), ""WHITE"Hi "CYAN"%s"WHITE", it seems you're already registered, please type in your password: "GREEN"(input below)", Player_GetName(playerid));
        Dialog_Show(playerid, PlayerLogin, DIALOG_STYLE_PASSWORD, ""SERVER_NAME" Freeroam: Login", string, "Login", "Forgot Password");
    }
    else
    {
        format(string, sizeof(string), ""WHITE"Hi "CYAN"%s"WHITE", it appears to be your first time around, welcome!\nPlease type in a password for your account below: "GREEN"(input below)\n\n"YELLOW"NOTE: You can play with guest account!", Player_GetName(playerid));
        Dialog_Show(playerid, PlayerRegister, DIALOG_STYLE_INPUT, ""SERVER_NAME" Freeroam: Register", string, "Register", "Guest");
    }
    return 1;
}

function OnAccountPasswordHashed(playerid)
{
    static
        query[256],
        string[512],
        hash[BCRYPT_HASH_LENGTH];

    bcrypt_get_hash(hash, sizeof(hash));

    mysql_format(Database, query, sizeof(query), "INSERT INTO `accounts` (`name`, `password`) VALUES ('%e', '%e')", Player_GetName(playerid), hash);
    mysql_query(Database, query, false);

    SendClientMessage(playerid, X11_LIGHTBLUE, "SERVER: "WHITE"Your account has been registered!");
    
    format(string, sizeof(string), ""WHITE"Hi "ORANGERED1"%s"WHITE", it seems you're already registered, please type in your password: "ORANGERED1"(input below)", Player_GetName(playerid));
    Dialog_Show(playerid, PlayerLogin, DIALOG_STYLE_PASSWORD, ""SERVER_NAME" Freeroam: Login", string, "Login", "Forgot Password");
    return 1;
}

function OnAccountPasswordChecked(playerid, bool:success)
{
    if(!success)
    {
        static
            string[256];
            
        format(string, sizeof(string), ""WHITE"Hi "ORANGERED1"%s"WHITE", it seems you're already registered, please type in your password: "ORANGERED1"(input below)", Player_GetName(playerid));
        Dialog_Show(playerid, PlayerLogin, DIALOG_STYLE_PASSWORD, ""SERVER_NAME" Freeroam: Login", string, "Login", "Forgot Password");

        Error(playerid, "Invalid password!, please try again.");
        return 1;
    }

    static
        query[256];

    mysql_format(Database, query, sizeof(query), "SELECT * FROM `accounts` WHERE `name` = '%e' LIMIT 1", Player_GetName(playerid));
    mysql_tquery(Database, query, "OnAccountLoaded", "i", playerid);
    return 1;
}