
#include <iostream>
#include <ctime>
#include <random>
#include "Classes.h"

using namespace std;

int main()
{
	std::string csv;
	Figure* F = new Cylinder();
	csv = F->GetAsJSON();
	delete F;
	Figure* S = new Sphere();
	csv += S->GetAsJSON();
	delete S;
	return 0;
}