
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
		vector <Point> p;
		vector <vector <Point>> f;
		double GetRandNumb(int min, int max); // ������� ��������� ���������� ����� � ��������� �� min �� max
		virtual void GetAsCSV();
		size_t& Number() { static size_t c = 0; return c; }
};

// �����, ����������� �������
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

// �����, ����������� �����������
class Surface: public Figure {
	public:
		int CreateSurface();
		void GetCSV();
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
private:
	size_t& ID() { static size_t c = 0; return c; }
};


