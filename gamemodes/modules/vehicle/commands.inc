CMD:veh(playerid, params[])
{
	if(!IsPLayerLoggedIn[playerid])
		return Error(playerid, "You must be spawned to use this");

	new modelid, col[2];
	if(sscanf(params, "k<vehicle>D()D()", modelid, col[0], col[1]))
		return Error(playerid, "Please input the valid argument\nExample: /veh [modelid/name of vehicle] [color1] [color2] or just use /veh [modelid/name of vehicle]");

	if(modelid <= 400 && modelid >= 612) 
		return Error(playerid, "Invalid vehicle model, Please input the valid model id (400 - 612)");

	new Float:PlayerPos[3], Float:PlayerAngle;
	GetPlayerPos(playerid, PlayerPos[0], PlayerPos[1], PlayerPos[2]);
	GetPlayerFacingAngle(playerid, PlayerAngle);

	if(SpawnedPlayerVehicle[playerid][P_ID] != INVALID_VEHICLE_ID) {
		DestroyVehicle(SpawnedPlayerVehicle[playerid][P_ID]);
		
		SpawnedPlayerVehicle[playerid][P_MODELID] = -1;
		SpawnedPlayerVehicle[playerid][P_ID] = INVALID_VEHICLE_ID;
	}

	new vehicleid = CreateVehicle(modelid, PlayerPos[0], PlayerPos[1], PlayerPos[2], PlayerAngle, col[0], col[1], 50000);

	SpawnedPlayerVehicle[playerid][P_ID] = vehicleid;
	SpawnedPlayerVehicle[playerid][P_MODELID] = modelid;
	PutPlayerInVehicle(playerid, vehicleid, 0);

	return SendClientMessageEx(playerid, -1, ORANGERED1"[SERVER]: "WHITE"You has spawned vehicle "ORANGERED1"%s", GetVehicleNameFromModelID(modelid));
}

CMD:delveh(playerid)
{
	if(!IsPLayerLoggedIn[playerid])
		return Error(playerid, "You must be spawned to use this");

	if(SpawnedPlayerVehicle[playerid][P_ID] == INVALID_VEHICLE_ID)
		return Error(playerid, "You're not have a spawned vehicles");

	RemovePlayerFromVehicle(playerid);
	DestroyVehicle(SpawnedPlayerVehicle[playerid][P_ID]);
	SendClientMessageEx(playerid, -1, ORANGERED1"[SERVER]: "WHITE"Your %s has been destroyed", GetVehicleNameFromModelID(SpawnedPlayerVehicle[playerid][P_MODELID]));

	SpawnedPlayerVehicle[playerid][P_MODELID] = -1;
	SpawnedPlayerVehicle[playerid][P_ID] = INVALID_VEHICLE_ID;
	return 1;
}

CMD:respawnall(playerid)
{

}