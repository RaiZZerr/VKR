
#include <iostream>
#include <ctime>
#include <random>
#include "Classes.h"

using namespace std;

int main()
{
	std::string csv;
	Figure* F = new Cylinder();
	csv = F->GetAsCSV();
	CreateCSV(csv);
	delete F;
	return 0;
}