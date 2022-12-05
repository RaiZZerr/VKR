
#include <iostream>
#include <ctime>
#include <random>
#include "Classes.h"

using namespace std;

int main()
{
	Cylinder num;
	num.CreateCylinder();
	num.GetCSV();
	Sphere cum;
	cum.CreateSphere();
	cum.GetCSV();

	/*
	cout << "Cylinder: " << endl;
	for (int i = 0; i < num.x.size(); i++) {
		cout << num.x[i] << " " << num.y[i] << " " << num.z[i] << " ";
	}
	cout << endl;
	cout << "Sphere: " << endl;
	for (int j = 0; j < cum.x.size(); j++) {
		cout << cum.x[j] << " " << cum.y[j] << " " << cum.z[j] << " ";
	}
	*/

	return 0;
}