#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class row {
public:
	std::string number;
	std::string category;
	std::string name;
	std::string email;
	row(std::string nb, std::string c, std::string nm, std::string e);
};

class DataFrame {
public:
	std::vector<row*> table;
	void from_csv(const std::string &path);
	void print_all_data();
};
