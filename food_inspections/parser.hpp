#pragma once
#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

//Inspection ID,DBA Name,AKA Name,License #,Facility Type,Risk,Address,City,State,Zip,Inspection Date,Inspection Type,Results,Violations,Latitude,Longitude,Location

class row {
public:
	std::string InspectionID;
	std::string DBAName;
	std::string AKAName;
	std::string LicenseNo;
	std::string FacilityType;
	std::string Risk;
	std::string Address;
	std::string City;
	std::string State;
	std::string Zip;
	std::string InspectionDate;
	std::string InspectionType;
	std::string Results;
	std::string Violations;
	std::string Latitude;
	std::string Longitude;
	std::string Location;
	row(std::string _InspectionID, std::string _DBAName, std::string _AKAName, std::string _LicenseNo, std::string _FacilityType, std::string _Risk, std::string _Address, std::string _City, std::string _State, std::string _Zip, std::string _InspectionDate, std::string _InspectionType, std::string _Results, std::string _Violations, std::string _Latitude, std::string _Longitude, std::string _Location);
};

class DataFrame {
public:
	std::vector<row*> table;
	std::map<std::string,int> RiskValues;

	void from_csv(const std::string &path);
	//void print_all_data();
	//void to_csv(const std::string &path);
	void print_risk_values();
};