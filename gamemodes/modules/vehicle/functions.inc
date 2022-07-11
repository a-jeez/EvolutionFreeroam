function SetPlayerVehicleDeathState(playerid, vehicleid, dstate)
{
    if(Iter_Contains(pVehicle[playerid], vehicleid) &&
    	SpawnedPlayerVehicle[playerid][P_ID] == vehicleid)
    {
        if(SpawnedPlayerVehicle[playerid][P_MODELID] != -1)
        {
            SpawnedPlayerVehicle[playerid][P_ISDEAD] = dstate;
        }
    }
}

function GetPlayerVehicleDeathState(playerid, vehicleid)
{
    if(Iter_Contains(pVehicle[playerid], vehicleid) &&
    	SpawnedPlayerVehicle[playerid][P_ID] == vehicleid)
    {
        if(SpawnedPlayerVehicle[playerid][P_MODELID] != -1)
	        return SpawnedPlayerVehicle[playerid][P_ISDEAD];
    }
    return false;
}

function GetPlayerVehicleData(playerid, vehicleData:data)
{
	return SpawnedPlayerVehicle[playerid][data];
}

stock2 GetVehicleNameFromModelID(modelid)
{
	if(modelid >= 400 && modelid <= 612) {
		return VehicleModelNames[modelid - 400];
	}
	return VehicleModelNames[212];
}

function RemovePlayerVehicle(playerid, vehicleid)
{
    if(Iter_Contains(pVehicle[playerid], vehicleid) &&
    	SpawnedPlayerVehicle[playerid][P_ID] == vehicleid)
    {
        if(SpawnedPlayerVehicle[playerid][P_MODELID] != -1)
        {
            Iter_Free(pVehicle[playerid]);
            
            DestroyVehicle(vehicleid);
            SpawnedPlayerVehicle[playerid][P_ID] = INVALID_VEHICLE_ID;
            SpawnedPlayerVehicle[playerid][P_MODELID] = -1;
            SpawnedPlayerVehicle[playerid][P_ISDEAD] = false;
        }
    }
}