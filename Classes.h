
#include <vector>
#include <random>
#include <fstream>

using namespace std;

// Класс описания точки
class Point {
	public:
		double x, y, z;
};

// Класс, описывающий любую фигуру
class Figure {
	public:
		vector <Point> p;
		double GetRandNumb(int min, int max); // Функция генерации рандомного числа в диапазоне от min до max
};

// Класс, описывающий цилиндр
class Cylinder: public Figure {
	public:
		double r, h;
		void CreateFooting(Point crd, double r, double h);
		void CreateWalls(Point crd, double r, double h);
		int CreateCylinder();
		void GetCSV();
};

// Класс, описывающий поверхность
class Surface: public Figure {
	public:
		int CreateSurface();
		void GetCSV();
};

// Класс, описывающий сферу
class Sphere: public Figure {
	public:
		double r;
		void CreateFooting(Point crd, double r);
		void CreateUpHemisphere(Point crd, double r);
		void CreateDownHemisphere(Point crd, double r);
		int CreateSphere();
		void GetCSV();
};


