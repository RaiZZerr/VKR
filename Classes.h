
#include <vector>
#include <random>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using nlohmann::json;

// ����� �������� �����
class Point {
	public:
		double x, y, z;
};

// �����, ����������� ����� ������
class Figure {
	public:
		json j = {
			{"Number", {}},
			{"Type", {}},
			{"ID", {}},
			{"X", {}},
			{"Y", {}},
			{"Z", {}}
		};;
		vector <Point> p;
		vector <vector <Point>> f;
		void CreateCSV(string a);
		virtual string GetAsCSV();
		virtual void GetAsJSON();
		size_t& Number() { static size_t c = 0; return c; }
private:
	size_t& ID() { static size_t c = 0; return c; }
};

// �����, ����������� �������
class Cylinder: public Figure {
	public:
		double r, h;
		Cylinder();
		Cylinder(double r, double h);
		void CreateFooting(double r, double h);
		void CreateWalls(double r, double h);
		string GetAsCSV() override;
		void GetAsJSON() override;
private:
	size_t& ID() { static size_t c = 0; return c; }
	
};

// �����, ����������� �����������
class Plane: public Figure {
	public:
		int Num_Points;
		double angle;
		Plane();
		Plane(int Num_Points);
		void GetAsCSV() override;
		void GetAsJSON() override;
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
		void GetAsCSV() override;
		void GetAsJSON() override;
private:
	size_t& ID() { static size_t c = 0; return c; }
};


