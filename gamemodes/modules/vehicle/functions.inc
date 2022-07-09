stock FindVehicleModelIDFromName(params[])
{
	new modelid = 0;
	while(modelid <= 212)
	{
		if(strcmp(VehicleModelNames[modelid], params[0], false) == 0)
			return 400 + modelid;

		modelid++;
	}
	return -1;
}

stock GetVehicleNameFromModelID(modelid)
{
	if(modelid >= 400 && modelid <= 612) {
		return VehicleModelNames[modelid - 400];
	}
	return VehicleModelNames[212];
}