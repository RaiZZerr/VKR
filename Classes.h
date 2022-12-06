
#include <vector>
#include <random>
#include <fstream>

using namespace std;

class Figure {
	public:
		vector <float> x;
		vector <float> y;
		vector <float> z;
};

class Cylinder: public Figure {
	public:
		float r, h;
		int CreateCylinder();
		void GetCSV();
};

class Surface: public Figure {
	public:
		int CreateSurface();
		void GetCSV();
};

class Sphere: public Figure {
	public:
		float r;
		int CreateSphere();
		void GetCSV();
};

int Surface::CreateSurface()
{
	static int ID = 0;

	ID++;
	return ID;
}

int Cylinder::CreateCylinder()
{
	static int ID = 0;
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(5, 100);
	h = dist(gen);
	r = dist(gen);
	// x = r*cos(fi), y = r * sin(fi)
 
	// ��������� ��������� � ������� ��������
	for (float hlp_r = r; hlp_r > 0; hlp_r -= 2)  // ��������� ������� ����� ��� ���������� ���������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			x.push_back(hlp_r* cos(i));
			y.push_back(0);
			z.push_back(hlp_r * sin(i));
			
		}
	}

	for (float hlp_r = r; hlp_r > 0; hlp_r -= 2)  // ��������� ������� ����� ��� ���������� �������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			x.push_back(hlp_r * cos(i));
			y.push_back(h);
			z.push_back(hlp_r * sin(i));
			
		}
	}
	//---------------------------------------
	
	// ��������� ������ ��������
	float hlp_y = 0;
	float k = 0;
	while (hlp_y < h)
	{
		uniform_real_distribution<> dist(2, 4);
		k = dist(gen);
		hlp_y += k;
		for (int i = 0; i <= 360; i += 5)
		{
			x.push_back(r * cos(i));
			y.push_back(hlp_y);
			z.push_back(r * sin(i));
		}		
	}
	ID++;
	return ID;
}

int Sphere::CreateSphere()
{
	static int ID = 0;
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(5, 100);
	r = dist(gen);

	// ��������� ���������� ���������� �����
	for (int i = 0; i <= 360; i += 2)
	{
		x.push_back(r * cos(i));
		y.push_back(0);
		z.push_back(r * sin(i));
	}
	//--------------------------------------

	// ��������� ������� ���������
	float hlp_y = 0;
	float hlp_r = 0;
	while (hlp_y < r)
	{
		uniform_real_distribution<> dist(5, 10);
		hlp_y += 2;
		hlp_r = sqrt(r * r - hlp_y * hlp_y);
		for (int i = 0; i <= 360; i += 2)
		{
			x.push_back(hlp_r * cos(i));
			y.push_back(hlp_y);
			z.push_back(hlp_r * sin(i));
		}
	}
	//----------------------------------------

	// ��������� ������ ���������
	hlp_y = 0;
	hlp_r = 0;
	while ((-hlp_y) < r)
	{
		uniform_real_distribution<> dist(5, 10);
		hlp_y -= dist(gen);
		hlp_r = sqrt(r * r - ((-hlp_y) * (-hlp_y)));
		for (int i = 0; i <= 360; i += 20)
		{
			x.push_back(hlp_r * cos(i));
			y.push_back(hlp_y);
			z.push_back(hlp_r * sin(i));
		}
	}
	//----------------------------------------

	ID++;
	return ID;
}

void Cylinder::GetCSV()
{
	int ID = Cylinder::CreateCylinder();
	ofstream CSV;
	ifstream check("Example.csv");
	if (!check.is_open())
	{
		CSV.open("Example.csv");
		CSV << "Type;ID;X;Y;Z" << endl;
		CSV.close();
	}
	CSV.open("Example.csv", ios_base::app);
	for (int i = 0; i < x.size(); i++)
	{
		CSV << "1;" << ID << ';' << x[i] << ';' << y[i] << ';' << z[i] << endl;
	}
	CSV.close();
}

void Sphere::GetCSV()

{
	int ID = Sphere::CreateSphere();
	ofstream CSV;
	ifstream check("Example.csv");
	if (!check.is_open())
	{
		CSV.open("Example.csv");
		CSV << "Type;ID;X;Y;Z" << endl;
		CSV.close();
	}
	CSV.open("Example.csv", ios_base::app);
	for (int i = 0; i < x.size(); i++)
	{
		CSV << "2;" << ID << ';' << x[i] << ';' << y[i] << ';' << z[i] << endl;
	}
	CSV.close();
}

void Surface::GetCSV()
{

}
