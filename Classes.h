
#include <vector>
#include <random>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using nlohmann::json;

// Класс описания точки
class Point {
	public:
		double x, y, z;
};

// Класс, описывающий любую фигуру
class Figure {
	public:
		json j;
		vector <Point> p;
		vector <vector <Point>> f;
		virtual void WriteInCSV(string a);
		virtual void WriteInJSON(string a);
		virtual string GetAsCSV();
		virtual string GetAsJSON();
		size_t& NumberInCSV() { static size_t c = 0; return c; }
		size_t& NumberInJSON() { static size_t c = 0; return c; }
private:
	size_t& ID() { static size_t c = 0; return c; }
};

// Класс, описывающий цилиндр
class Cylinder: public Figure {
	public:
		double r, h;
		Cylinder();
		Cylinder(double r, double h);
		void CreateFooting(double r, double h);
		void CreateWalls(double r, double h);
		void WriteInCSV(string a) override;
		void WriteInJSON(string a) override;
		string GetAsCSV() override;
		string GetAsJSON() override;
private:
	size_t& ID() { static size_t c = 0; return c; }
	
};

// Класс, описывающий поверхность
class Plane: public Figure {
	public:
		int Num_Points;
		double angle;
		Plane();
		Plane(int Num_Points);
		string GetAsCSV() override;
		string GetAsJSON() override;
		void WriteInCSV(string a) override;
		void WriteInJSON(string a) override;
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
		string GetAsCSV() override;
		string GetAsJSON() override;
		void WriteInCSV(string a) override;
		void WriteInJSON(string a) override;
private:
	size_t& ID() { static size_t c = 0; return c; }
};


