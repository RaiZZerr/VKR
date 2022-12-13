
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
		double GetRandNumb(int min, int max); // ������� ��������� ���������� ����� � ��������� �� min �� max
};

// �����, ����������� �������
class Cylinder: public Figure {
	public:
		double r, h;
		void CreateFooting(Point crd, double r, double h);
		void CreateWalls(Point crd, double r, double h);
		int CreateCylinder();
		void GetCSV();
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
		void CreateFooting(Point crd, double r);
		void CreateUpHemisphere(Point crd, double r);
		void CreateDownHemisphere(Point crd, double r);
		int CreateSphere();
		void GetCSV();
};


