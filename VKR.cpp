
#include <iostream>
#include <ctime>
#include <random>
#include "Classes.h"

using namespace std;

int main()
{
	Figure* F = new Surface();
	F->GetAsCSV();
	delete F;
	F = new Cylinder();
	F->GetAsCSV();
	delete F;

	return 0;
}