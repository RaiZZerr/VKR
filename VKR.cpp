
#include <iostream>
#include <ctime>
#include <random>
#include "Classes.h"

using namespace std;


bool yo[1001][1001] = { false };

int Surface()
{
	int x, y, z;
	z = 0;
	srand(time(0));

	for (int i = 0; i <= 100000; i++)
	{
		x = rand() % 1001;
		y = rand() % 1001;
		yo[y][x] = true;
		cout << x << ',' << y << ',' << z << ' ';
	}

	return 1;
}

void see() {
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (yo[i][j]) cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
}

int main()
{
	Cylinder num;
	num.CreateCylinder();
	for (int i = 0; i < num.x.size(); i++) {
		cout << num.x[i] << " , " << num.z[i] << "  ";
	}
	return 0;
}