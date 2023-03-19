
#include <iostream>
#include "figures.h"
#include "writefile.h"

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
	delete T;
	return 0;
}
