
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
class Figure: public Point {
	public:
		//vector <Point> p;
		//vector <vector <Point>> f;
		virtual string GetAsCSV(vector <vector <Point>> f);
		virtual string GetAsCSV(vector <Point> p);
		virtual string GetAsJSON(vector <vector <Point>> f);
		virtual vector <Point> GetAsPoints(double o);
		size_t& NumberInCSV() { static size_t c = 0; return ++c; }
};

// Класс, описывающий цилиндр
class Cylinder: public Figure {
	public:
		double r, h;
		Cylinder(double radius, double height);
		vector <Point> GetAsPoints(double o) override;
		vector <Point> CreateFooting(double r, double h);
		vector <Point> CreateWalls(double r, double h);
		vector <Point> CreateFooting(double r, double h, double o);
		vector <Point> CreateWalls(double r, double h, double o);
		string GetAsCSV(vector <vector <Point>> f) override;
		string GetAsCSV(vector <Point> p) override;
		string GetAsJSON(vector <vector <Point>> f) override;
};

// Класс, описывающий поверхность
class Plane: public Figure {
	public:
		int Point_Count;
		double angle;
		Plane(int Count);
		vector <Point> GetAsPoints(double o) override;
		string GetAsCSV(vector <vector <Point>> f) override;
		string GetAsCSV(vector <Point> p) override;
		string GetAsJSON(vector <vector <Point>> f) override;
};

// Класс, описывающий сферу
class Sphere: public Figure {
	public:
		double r;
		Sphere(double radius);
		vector <Point> GetAsPoints(double o) override;
		vector <Point> CreateFooting(double r);
		vector <Point> CreateUpHemisphere(double r);
		vector <Point> CreateDownHemisphere(double r);
		vector <Point> CreateFooting(double r, double o);
		vector <Point> CreateUpHemisphere(double r, double o);
		vector <Point> CreateDownHemisphere(double r, double o);
		string GetAsCSV(vector <vector <Point>> f) override;
		string GetAsCSV(vector <Point> p) override;
		string GetAsJSON(vector <vector <Point>> f) override;
};


