new Login_Timer[MAX_PLAYERS] = 0;

/* login music */
new LoginMusicID[8] =
{
	1062, 1068, 1076, 1097, 1183, 1185, 1187
};

new bool:IsPLayerLoggedIn[MAX_PLAYERS];

new
    Iterator:pVehicle[MAX_PLAYERS]<MAX_VEHICLES>;

enum vehicleData
{
    P_ID,
    P_MODELID,
    P_ISDEAD
};
new SpawnedPlayerVehicle[MAX_PLAYERS][vehicleData];