#include "parser.hpp"

row::row(std::string nb, std::string c, std::string nm, std::string e) {
	number = nb;
	category = c;
	name = nm;
	email = e;
}

void DataFrame::from_csv(const std::string &path) {
	std::vector<std::vector<std::string>> matrix = std::vector<std::vector<std::string>>();
	std::fstream fs;
	fs.open(path, std::ios::in);

	std::string line, cell;

	if (!fs.is_open()){
		std::cout << "Error opening file." << std::endl;
		return;
	}

	while (getline(fs, line)) {
		//add vector (row) into matrix
		matrix.push_back(std::vector<std::string>());

		std::stringstream ss(line);

		//iterate through line, pushing each cell into the vector that was added to matrix
		while (getline(ss, cell, ',')) {
			if (!cell.empty()) {
				matrix.back().push_back(cell);
			}
			else {
				matrix.back().push_back("NaN");
			}
		}
		//add an empty cell if number of cells on row does not match that of columns
		while (matrix.back().size() != 4) {
			matrix.back().push_back("NaN");
		}	 
	} std::move(matrix);
	fs.close();

	for (size_t i = 0; i < matrix.size(); i++) {
		row * r = new row(matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
		table.push_back(r);
	}
}

void DataFrame::print_all_data() {
	for (size_t i = 0; i < table.size(); i++) {
		std::cout << table[i]->number << "\t" << table[i]->category << "\t" << table[i]->name << "\t" << table[i]->email << std::endl;
	}
}