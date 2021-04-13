#include "parser.hpp"

int main()
{
	DataFrame df;
	df.from_csv("sample.csv");
	df.print_all_data();

	std::cout << "Student 1's email is " << df.table[0]->email << std::endl;

	return 0;
}
