#include "parser.hpp"

row::row(std::string _InspectionID, std::string _DBAName, std::string _AKAName, std::string _LicenseNo, std::string _FacilityType, std::string _Risk, std::string _Address, std::string _City, std::string _State, std::string _Zip, std::string _InspectionDate, std::string _InspectionType, std::string _Results, std::string _Violations, std::string _Latitude, std::string _Longitude, std::string _Location) {
	InspectionID = _InspectionID;
	DBAName = _DBAName;
	AKAName = _AKAName;
	LicenseNo = _LicenseNo;
	FacilityType = _FacilityType;
	Risk = _Risk;
	Address = _Address;
	City = _City;
	State = _State;
	Zip = _Zip;
	InspectionDate = _InspectionDate;
	InspectionType = _InspectionType;
	Results = _Results;
	Violations = _Violations;
	Latitude = _Latitude;
	Longitude = _Longitude;
	Location = _Location;
}

void DataFrame::from_csv(const std::string &path) {
	//create vector that will be pushed into a row
	std::vector<std::string> new_row = std::vector<std::string>();
	std::string line, cell, ignore;
	std::fstream fs;

	fs.open(path, std::ios::in);
	if (!fs.is_open()) {
		std::cout << "Error opening file." << std::endl;
		return;
	}

	while (getline(fs, line)) {
		std::stringstream ss(line);

		while (ss >> std::ws) {
			//ignore commas inside of quotes
			if (ss.peek() == '"') {
				ss >> std::quoted(cell);
				getline(ss, ignore, ',');
				new_row.push_back(cell);
			}
			//iterate through line, pushing each cell into the vector
			else {
				getline(ss, cell, ',');
				new_row.push_back(cell);
			}
		}
		
		//add empty cell if row does not have 17 columns as expected
		while (new_row.size() < 17) {
			new_row.push_back("");
		}
		std::move(new_row);
		//pass string vector into actual table
		row * r = new row(new_row[0], new_row[1], new_row[2], new_row[3], new_row[4], new_row[5], new_row[6], new_row[7], new_row[8], new_row[9], new_row[10], new_row[11], new_row[12], new_row[13], new_row[14], new_row[15], new_row[16]);
		table.push_back(r);
		std::vector<std::string>().swap(new_row);
	}
	fs.close();
}

void DataFrame::print_risk_values() {
	for (size_t i = 0; i < table.size(); i++) {
		//insert a pair of risk value and frequency if not in map
		if (RiskValues.count(table[i]->Risk) == 0) {
			RiskValues.insert(std::make_pair(table[i]->Risk, 1));
		} //increment frequency if risk value already in map
		else {
			RiskValues[table[i]->Risk]++;
		}
	}

	for (const auto& pair : RiskValues) {
		std::cout << pair.first << " appears " << pair.second << " times." << std::endl;
	}
}