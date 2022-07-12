enum playerData
{
    P_SQLID,
    P_NAME[MAX_PLAYER_NAME],
    P_TMPACCOUNT,
};
new PlayerData[MAX_PLAYERS][playerData];
new bool:GodMode[MAX_PLAYERS] = { false , ... };
new bool:JumpMode[MAX_PLAYERS] = { false , ... };