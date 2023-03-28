
#include <vector>
#include <random>
#include <fstream>

using namespace std;

// ����� �������� �����
class Point {
	public:
		double x, y, z;
};

// �����, ����������� ����� ������
class Figure {
	public:
		//vector <Point> p;
		//vector <vector <Point>> f;
		virtual string GetAsCSV(vector <vector <Point>> f);
		virtual string GetAsJSON(vector <vector <Point>> f);
		virtual vector <Point> GetAsPoints(double o);
		size_t& NumberInCSV() { static size_t c = 0; return c; }
		size_t& NumberInJSON() { static size_t c = 0; return c; }
private:
	size_t& ID() { static size_t c = 0; return c; }
};

// �����, ����������� �������
class Cylinder: public Figure {
	public:
		double r, h;
		Cylinder(double r, double h);
		vector <Point> GetAsPoints(double o) override;
		vector <Point> CreateFooting(double r, double h);
		vector <Point> CreateWalls(double r, double h);
		vector <Point> CreateFooting(double r, double h, double o);
		vector <Point> CreateWalls(double r, double h, double o);
		string GetAsCSV(vector <vector <Point>> f) override;
		string GetAsJSON(vector <vector <Point>> f) override;
};

// �����, ����������� �����������
class Plane: public Figure {
	public:
		int Num_Points;
		double angle;
		Plane();
		Plane(int Num_Points);
		/*string GetAsCSV() override;
		string GetAsJSON() override;*/
private:
	size_t& ID() { static size_t c = 0; return c; }
};

// �����, ����������� �����
class Sphere: public Figure {
	public:
		double r;
		Sphere();
		Sphere(double r);
		void CreateFooting(double r);
		void CreateUpHemisphere(double r);
		void CreateDownHemisphere(double r);
		//string GetAsCSV() override;
		//string GetAsJSON() override;
private:
	size_t& ID() { static size_t c = 0; return c; }
};


