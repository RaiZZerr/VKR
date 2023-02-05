
#include "Classes.h"

// ��������� ����� �����������
int Surface::CreateSurface()
{
	static int ID = 0;

	ID++;
	return ID;
}

// ����������� ���������� ��������
Cylinder::Cylinder()
{
	
	h = GetRandNumb(5, 100);
	r = GetRandNumb(5, 100);
	// ��������� ��������� � ������� ��������
	CreateFooting(r, h);

	// ��������� ������ ��������
	CreateWalls(r, h);
	++ID();
}

// ����������� �������� � �������� �������� � �������
Cylinder::Cylinder(double r, double h)
{
	// ��������� ��������� � ������� ��������
	CreateFooting(r, h);

	// ��������� ������ ��������
	CreateWalls(r, h);
	++ID();
}

// ����������� ��������� �����
Sphere::Sphere()
{
	
	r = GetRandNumb(5, 100);
	// ��������� ���������� ���������� �����
	CreateFooting(r);

	// ��������� ������� ���������
	CreateUpHemisphere(r);

	// ��������� ������ ���������
	CreateDownHemisphere(r);

	++ID();
}

// ����������� ����� � �������� ��������
Sphere::Sphere(double r)
{
	// ��������� ���������� ���������� �����
	CreateFooting(r);

	// ��������� ������� ���������
	CreateUpHemisphere(r);

	// ��������� ������ ���������
	CreateDownHemisphere(r);

	++ID();
}

void Figure::GetAsCSV()
{
	ofstream CSV;
	ifstream check("Example.csv");
	if (!check.is_open())
	{
		CSV.open("Example.csv");
		CSV << "Number;Type;ID;X;Y;Z" << endl;
		CSV.close();
	}
	CSV.open("Example.csv", ios_base::app);
	for (int i = 0; i < p.size(); i++)
	{
//		CSV << Number << ';' << <<  << endl;
	}
	CSV.close();
}

// ������ �������� � CSV
void Cylinder::GetAsCSV() 
{
	ofstream CSV;
	ifstream check("CSV.csv");
	if (!check.is_open())
	{
		CSV.open("CSV.csv");
		CSV << "Number;Type;ID;X;Y;Z" << endl;
		CSV.close();
	}
	++Number();
	CSV.open("CSV.csv", ios_base::app);
	for (int i = 0; i < p.size(); i++)
	{
		CSV << Number() << ';' << '1' << ';' << ID() << ';' << p[i].x << p[i].y << p[i].z << endl;
	}
	CSV.close();
}

// ������ ����� � CSV
void Sphere::GetAsCSV()

{
	ofstream CSV;
	ifstream check("CSV.csv");
	if (!check.is_open())
	{
		CSV.open("CSV.csv");
		CSV << "Number;Type;ID;X;Y;Z" << endl;
		CSV.close();
	}
	++Number();
	CSV.open("CSV.csv", ios_base::app);
	for (int i = 0; i < p.size(); i++)
	{
		CSV << Number() << ';' << '2' << ';' << ID() << ';' << p[i].x << p[i].y << p[i].z << endl;
	}
	CSV.close();
}


// ������ ����������� � CSV
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
void Cylinder::CreateFooting(double r, double h)
{
	Point dot;
	// x = r*cos(fi), y = r * sin(fi)
	double hlp_r = r;
	for (r; r > 0; r -= 2)  // ��������� ������� ����� ��� ���������� ���������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = r * cos(i);
			dot.y = 0;
			dot.z = r * sin(i);
			p.push_back(dot);
		}
	}
	for (hlp_r; hlp_r > 0; hlp_r -= 2)  // ��������� ������� ����� ��� ���������� �������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = hlp_r * cos(i);
			dot.y = h;
			dot.z = hlp_r * sin(i);
			p.push_back(dot);

		}
	}
}

// ������� ��������� ������ ��������
void Cylinder::CreateWalls(double r, double h)
{
	Point dot;
	double hlp_y = 0;
	double k = 0;
	while (hlp_y < h)
	{
		k = GetRandNumb(2, 4);
		hlp_y += k;
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = r * cos(i);
			dot.y = hlp_y;
			dot.z = r * sin(i);
			p.push_back(dot);
		}
	}
}

void Sphere::CreateFooting(double r)
{
	Point dot;
	for (int i = 0; i <= 360; i += 2)
	{
		dot.x = r * cos(i);
		dot.y = 0;
		dot.z = r * sin(i);
		p.push_back(dot);
	}
}

void Sphere::CreateUpHemisphere(double r)
{
	Point dot;
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
			dot.x = hlp_r * cos(i);
			dot.y = hlp_y;
			dot.z = hlp_r * sin(i);
			p.push_back(dot);
		}
	}
}

void Sphere::CreateDownHemisphere(double r)
{
	Point dot;
	float hlp_y = 0;
	float hlp_r = 0;
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
			dot.x = hlp_r * cos(i);
			dot.y = hlp_y;
			dot.z = hlp_r * sin(i);
			p.push_back(dot);
		}
	}
}