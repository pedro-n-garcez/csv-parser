#include "parser.hpp"

int main()
{
	DataFrame df;
	df.from_csv("Food_Inspections.csv");
	df.print_risk_values();

	return 0;
}