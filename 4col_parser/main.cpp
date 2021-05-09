#include "parser.hpp"

int main()
{
	DataFrame df;
	df.from_csv("sample.csv");
	df.print_all_data();

	std::cout << "Student 1's email is " << df.table[0]->email << std::endl;

	df.table[0]->name = "C. S. V. Lewis";
	df.table[0]->email = "csv.lewis@wejustgotaletter.com";

	std::cout << "Student 1's email is " << df.table[0]->email << std::endl;
	
	df.to_csv("exportedcsv.csv");

	return 0;
}
