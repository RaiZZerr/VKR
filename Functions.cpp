
#include "Classes.h"

// ��������� ����� �����������
int Surface::CreateSurface()
{
	static int ID = 0;

	ID++;
	return ID;
}

// ��������� ����� ��������
int Cylinder::CreateCylinder()
{
	Point crd;
	crd.x = 0;
	crd.y = 0;
	crd.z = 0;
	static int ID = 0;
	h = GetRandNumb(5, 100);
	r = GetRandNumb(5, 100);

	// ��������� ��������� � ������� ��������
	CreateFooting(crd, r, h);

	// ��������� ������ ��������
	CreateWalls(crd, r, h);

	ID++;
	return ID;
}

// ��������� ����� �����
int Sphere::CreateSphere()
{
	Point crd;
	crd.x = 0;
	crd.y = 0;
	crd.z = 0;
	static int ID = 0;
	//r = GetRandNumb(5, 100);
	r = 65.65423;

	// ��������� ���������� ���������� �����
	for (int i = 0; i <= 360; i += 2)
	{
		crd.x = r * cos(i);
		crd.y = 0;
		crd.z = r * sin(i);
		p.push_back(crd);
	}
	//--------------------------------------

	// ��������� ������� ���������
	float hlp_y = 0;
	float hlp_r = 0;
	while (hlp_y < r)
	{
		if (hlp_y + 2 > r)
		{
			break;
		}
		hlp_y += GetRandNumb(2, 3);
		hlp_r = sqrt(r * r - hlp_y * hlp_y);
		for (int i = 0; i <= 360; i += GetRandNumb(1, 10))
		{
			crd.x = hlp_r * cos(i);
			crd.y = hlp_y;
			crd.z = hlp_r * sin(i);
			p.push_back(crd);
		}
	}
	//----------------------------------------

	// ��������� ������ ���������
	hlp_y = 0;
	hlp_r = 0;
	while ((-hlp_y) < r)
	{
		if (-(hlp_y - 2) > r)
		{
			break;
		}
		hlp_y -= GetRandNumb(2, 3);
		hlp_r = sqrt(r * r - ((-hlp_y) * (-hlp_y)));
		for (int i = 0; i <= 360; i += GetRandNumb(1, 10))
		{
			crd.x = hlp_r * cos(i);
			crd.y = hlp_y;
			crd.z = hlp_r * sin(i);
			p.push_back(crd);
		}
	}
	//----------------------------------------

	ID++;
	return ID;
}

// ������ ����� �������� � CSV
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
	for (int i = 0; i < p.size(); i++)
	{
		CSV << "1;" << ID << ';' << p[i].x << ';' << p[i].y << ';' << p[i].z << endl;
	}
	CSV.close();
}

// ������ ����� ����� � CSV
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
	for (int i = 0; i < p.size(); i++)
	{
		CSV << "2;" << ID << ';' << p[i].x << ';' << p[i].y << ';' << p[i].z << endl;
	}
	CSV.close();
}

// ������ ����� ����������� � CSV
void Surface::GetCSV()
{

}

// ������� ��������� ���������� ����� � ��������� �� min �� max
double Figure::GetRandNumb(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(min, max);
	return dist(gen);
}

// ������� ��������� ��������� � ������� ��������
void Cylinder::CreateFooting(Point crd, double r, double h)
{
	// x = r*cos(fi), y = r * sin(fi)
	double hlp_r = r;
	for (r; r > 0; r -= 2)  // ��������� ������� ����� ��� ���������� ���������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			crd.x = r * cos(i);
			crd.y = 0;
			crd.z = r * sin(i);
			p.push_back(crd);
		}
	}
	for (hlp_r; hlp_r > 0; hlp_r -= 2)  // ��������� ������� ����� ��� ���������� �������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			crd.x = hlp_r * cos(i);
			crd.y = h;
			crd.z = hlp_r * sin(i);
			p.push_back(crd);

		}
	}
}

// ������� ��������� ������ ��������
void Cylinder::CreateWalls(Point crd, double r, double h)
{
	double hlp_y = 0;
	double k = 0;
	while (hlp_y < h)
	{
		k = GetRandNumb(2, 4);
		hlp_y += k;
		for (int i = 0; i <= 360; i += 5)
		{
			crd.x = r * cos(i);
			crd.y = hlp_y;
			crd.z = r * sin(i);
			p.push_back(crd);
		}
	}
}