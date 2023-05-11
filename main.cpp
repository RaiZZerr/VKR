
#include "API.h"

using namespace std;

int main()
{
	CreateShapes("Sphere.csv", { ShapeType::Sphere, 1, 2.5 });
	CreateRandomShapes("RandomShape.csv", { 1, 2.5 });
	return 0;
}
