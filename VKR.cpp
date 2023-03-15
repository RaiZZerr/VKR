
#include <iostream>
#include <ctime>
#include <random>
#include "Classes.h"
#include "WriteInFile.cpp"

using namespace std;

int main()
{
	string json;
	string csv;
	Figure* T = new Cylinder(1.5);
	csv += T->GetAsCSV();
	json += T->GetAsJSON();
	WriteInCSV(csv);
	WriteInJSON(json);
	return 0;
}
