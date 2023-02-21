
#include <iostream>
#include <ctime>
#include <random>
#include "Classes.h"

using namespace std;

int main()
{
	Figure* F = new Plane();
	F->GetAsJSON();
	delete F;
	Figure* S = new Cylinder();
	S->GetAsJSON();
	delete S;
	return 0;
}