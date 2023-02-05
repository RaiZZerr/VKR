
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
		vector <vector <Point>> f;
		double GetRandRealNumb(int min, int max); // Функция генерации рандомного вещественного числа в диапазоне от min до max
		int GetRandIntNumb(int min, int max); // Функция генерации рандомного целого числа в диапазоне от min до max
		virtual void GetAsCSV();
		size_t& Number() { static size_t c = 0; return c; }
};

// Класс, описывающий цилиндр
class Cylinder: public Figure {
	public:
		double r, h;
		Cylinder();
		Cylinder(double r, double h);
		void CreateFooting(double r, double h);
		void CreateWalls(double r, double h);
		void GetAsCSV() override;
private:
	size_t& ID() { static size_t c = 0; return c; }
	
};

// Класс, описывающий поверхность
class Surface: public Figure {
	public:
		int Num_Points;
		double angle;
		Surface();
		Surface(int Num_Points);
		void GetAsCSV() override;
private:
	size_t& ID() { static size_t c = 0; return c; }
};

// Класс, описывающий сферу
class Sphere: public Figure {
	public:
		double r;
		Sphere();
		Sphere(double r);
		void CreateFooting(double r);
		void CreateUpHemisphere(double r);
		void CreateDownHemisphere(double r);
		void GetAsCSV() override;
private:
	size_t& ID() { static size_t c = 0; return c; }
};


