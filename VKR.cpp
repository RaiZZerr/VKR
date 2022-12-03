
#include <iostream>
#include <ctime>
#include <random>
#include "Classes.h"

using namespace std;

int main()
{
	Cylinder num;
	num.CreateCylinder();
	cout << "Cylinder: " << endl;
	for (int i = 0; i < num.x.size(); i++) {
		cout << num.x[i] << " , " << num.y[i] << " , " << num.z[i] << " ;; ";
	}
	cout << endl;
	Sphere cum;
	cum.CreateSphere();
	cout << "Sphere: " << endl;
	for (int j = 0; j < cum.x.size(); j++) {
		cout << cum.x[j] << " , " << cum.y[j] << " , " << cum.z[j] << " ;; ";
	}
	return 0;
}