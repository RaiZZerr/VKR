
#include <iostream>
#include <ctime>
#include <random>
#include "Classes.h"

using namespace std;

int main()
{
	Sphere Sph = Sphere();
	Cylinder Cyl = Cylinder();
	Cyl.GetAsCSV();
	Sph.GetAsCSV();
	Cyl = Cylinder();
	Sph = Sphere();
	Cyl.GetAsCSV();
	Sph.GetAsCSV();

	return 0;
}