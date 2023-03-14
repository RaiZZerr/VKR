
#include <iostream>
#include <ctime>
#include <random>
#include "Classes.h"

using namespace std;

int main()
{
	string json;
	string csv;
	Figure* f = new Cylinder();
	csv = f->GetAsCSV();
	json = f->GetAsJSON();
	delete f;
	Figure* g = new Plane();
	csv += g->GetAsCSV();
	json += g->GetAsJSON();
	Figure* S = new Sphere();
	csv += S->GetAsCSV();
	json += S->GetAsJSON();
	delete S;
	Figure* T = new Cylinder();
	csv += T->GetAsCSV();
	json += T->GetAsJSON();
	T->WriteInCSV(csv);
	T->WriteInJSON(json);
	return 0;
}
