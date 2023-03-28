
#include <iostream>
#include "figures.h"
#include "writefile.h"

using namespace std;

int main()
{
	vector <Point> Points;
	vector <vector <Point>> Figures;
	string json;
	string csv;

	Figure* T = new Cylinder(100, 150);
	Points = T->GetAsPoints(0);
	Figures.push_back(Points);
	csv += T->GetAsCSV(Figures);
	WriteInCSV(csv);
	/*json += T->GetAsJSON();
	WriteInJSON(json);*/
	delete T;
	return 0;
}
