#include "parser.hpp"

int main()
{
	DataFrame df;
	df.from_csv("C:\\Stuff\\col\\8S2021\\CPP2\\csv_parse\\csv_parse\\sample.csv");
	df.print_all_data();

	std::cout << "Student 1's email is " << df.table[0]->email << std::endl;

	return 0;
}