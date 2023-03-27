
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
	Figure* G = new Cylinder(300, 500);
	Points = T->GetAsPoints(0);
	Figures.push_back(Points);
	Points = G->GetAsPoints(0);
	Figures.push_back(Points);
	csv += T->GetAsCSV(Figures);
	WriteInCSV(csv);
	/*json += T->GetAsJSON();
	WriteInJSON(json);*/
	delete T;
	delete G;
	return 0;
}
