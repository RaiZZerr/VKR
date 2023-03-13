
#include <iostream>
#include <ctime>
#include <random>
#include "Classes.h"

using namespace std;

int main()
{
	string csv;
	Figure* F = new Cylinder();
	csv = F->GetAsCSV();
	delete F;
	Figure* G = new Cylinder();
	csv += G->GetAsCSV();
	G->CreateCSV(csv);
	return 0;
}