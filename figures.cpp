
#define _USE_MATH_DEFINES
#include "figures.h"
#include "randomization.h"
#include <string>
#include <cmath>

// ����������� ����������� � ��������� ���-��� ����� (�� 50 �� 10000)
Plane::Plane()
{
	//Point dot;
	//Num_Points = GetRandIntNumb(50, 10000);
	//angle = GetRandRealNumb(0, 360);
	//double a = cos(angle * M_PI / 180.0);
	//double b = sin(angle * M_PI / 180.0);              // ��������� ������ ���������� ax + by + c = z
	//for (int i = 0; i < Num_Points; i++) {
	//	dot.x = GetRandRealNumb(-50, 50);
	//	dot.y = GetRandRealNumb(-50, 50);
	//	dot.z = -(a * dot.x + b * dot.y);
	//	p.push_back(dot);
	//}
	//f.push_back(p);
	//++ID();
}

// ����������� ����������� � �������� ���-��� ����� (Num_Points)
Plane::Plane(int Num_Points)
{
	//Point dot;
	//angle = GetRandRealNumb(0, 360);
	//double a = cos(angle * M_PI / 180.0);
	//double b = sin(angle * M_PI / 180.0);
	//for (int i = 0; i < Num_Points; i++) {
	//	dot.x = GetRandRealNumb(0, 1);
	//	dot.y = GetRandRealNumb(0, 1);
	//	dot.z = -(a * dot.x + b * dot.y);
	//	p.push_back(dot);
	//}
	//f.push_back(p);
	//++ID();
}

// ����������� ���������� ��������
//Cylinder::Cylinder()
//{
//	
//	h = GetRandRealNumb(5, 100);
//	r = GetRandRealNumb(5, 100);
//	// ��������� ��������� � ������� ��������
//	CreateFooting(r, h);
//
//	// ��������� ������ ��������
//	CreateWalls(r, h);
//	f.push_back(p);
//	++ID();
//}

// ����������� �������� � �������� �������� � �������
Cylinder::Cylinder(double radius, double height)
{
	r = radius;
	h = height;
	// ��������� ��������� � ������� ��������
	CreateFooting(r, h);

	// ��������� ������ ��������
	CreateWalls(r, h);
}

vector <Point> Cylinder::GetAsPoints(double o)
{
	vector <Point> p;
	vector <Point> hlp;
	if (o == 0)
	{
		hlp = CreateFooting(r, h);
		p.insert(p.end(), hlp.begin(), hlp.end());
		hlp = CreateWalls(r, h);
		p.insert(p.end(), hlp.begin(), hlp.end());
	}
	else
	{
		hlp = CreateFooting(r, h, o);
		p.insert(p.end(), hlp.begin(), hlp.end());
		hlp = CreateWalls(r, h, o);
		p.insert(p.end(), hlp.begin(), hlp.end());
	}
	return p;
}

// ����������� �������� � ���������� �������������� ��� ������ ����� � ������� ����������� o
//Cylinder::Cylinder(double o)
//{
//	h = GetRandRealNumb(5, 100);
//	r = GetRandRealNumb(5, 100);
//	// ��������� ��������� � ������� ��������
//	CreateFooting(r, h, o);
//
//	// ��������� ������ ��������
//	CreateWalls(r, h, o);
//	f.push_back(p);
//	++ID();
//}

// ����������� ��������� �����
Sphere::Sphere()
{
	
	//r = GetRandRealNumb(5, 100);
	//// ��������� ���������� ���������� �����
	//CreateFooting(r);

	//// ��������� ������� ���������
	//CreateUpHemisphere(r);

	//// ��������� ������ ���������
	//CreateDownHemisphere(r);

	//f.push_back(p);
	//++ID();
}

// ����������� ����� � �������� ��������
Sphere::Sphere(double r)
{
	//// ��������� ���������� ���������� �����
	//CreateFooting(r);

	//// ��������� ������� ���������
	//CreateUpHemisphere(r);

	//// ��������� ������ ���������
	//CreateDownHemisphere(r);

	//f.push_back(p);
	//++ID();
}

// ���������� ������� � ���� ������ ��� ������ .csv
string Cylinder::GetAsCSV(vector <vector <Point>> f)
{
	string str;
	++NumberInCSV();
	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j < f[i].size(); j++)
		{
			str += to_string(i+1) + ";" + "1" + ";" + to_string(f[i][j].x) + ";" + to_string(f[i][j].y) + ";" + to_string(f[i][j].z) + "\n";
		}	
	}
	return str;
}

// ���������� ������� � ���� ������ ��� ������ .json
string Cylinder::GetAsJSON(vector <vector <Point>> f)
{	
	string str;
	//++NumberInJSON();
	//if (NumberInJSON() == 1)
	//{
	//	str += "{ \n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 1,\n";
	//}
	//else
	//{
	//	str += "\n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 1,\n";
	//}
	//str += "\"X\": [\n";
	//for (int i = 0; i < p.size(); i++)
	//{
	//	if (i == p.size() - 1)
	//	{
	//		str += to_string(p[i].x) + "\n";
	//		break;
	//	}
	//	str += to_string(p[i].x) + ",\n";
	//	
	//}
	//str += "],\n";
	//str += "\"Y\": [\n";
	//for (int i = 0; i < p.size(); i++)
	//{
	//	if (i == p.size() - 1)
	//	{
	//		str += to_string(p[i].y) + "\n";
	//		break;
	//	}
	//	str += to_string(p[i].y) + ",\n";

	//}
	//str += "],\n";
	//str += "\"Z\": [\n";
	//for (int i = 0; i < p.size(); i++)
	//{
	//	if (i == p.size() - 1)
	//	{
	//		str += to_string(p[i].z) + "\n";
	//		break;
	//	}
	//	str += to_string(p[i].z) + ",\n";

	//}
	//str += "]\n";
	//str += "},\n";
	return str;
}

//// ���������� ����� � ���� ������ ��� ������ .csv
//string Sphere::GetAsCSV()
//
//{
//	string str;
//	++NumberInCSV();
//	for (int i = 0; i < p.size(); i++)
//	{
//		str += to_string(NumberInCSV()) + ";" + "2" + ";" + to_string(ID()) + ";" + to_string(p[i].x) + ";" + to_string(p[i].y) + ";" + to_string(p[i].z) + "\n";
//	}
//	return str;
//}

// ���������� ����� � ���� ������ ��� ������ .json
//string Sphere::GetAsJSON()
//{
//	string str;
//	++NumberInJSON();
//	if (NumberInJSON() == 1)
//	{
//		str += "{ \n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 2,\n";
//	}
//	else
//	{
//		str += "\n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 2,\n";
//	}
//	str += "\"X\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].x) + "\n";
//			break;
//		}
//		str += to_string(p[i].x) + ",\n";
//
//	}
//	str += "],\n";
//	str += "\"Y\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].y) + "\n";
//			break;
//		}
//		str += to_string(p[i].y) + ",\n";
//
//	}
//	str += "],\n";
//	str += "\"Z\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].z) + "\n";
//			break;
//		}
//		str += to_string(p[i].z) + ",\n";
//
//	}
//	str += "]\n";
//	str += "},\n";
//	return str;
//}


// ���������� ����������� � ���� ������ ��� ������ .csv
//string Plane::GetAsCSV()
//{
//	string str;
//	++NumberInCSV();
//	for (int i = 0; i < p.size(); i++)
//	{
//		str += to_string(NumberInCSV()) + ";" + "3" + ";" + to_string(ID()) + ";" + to_string(p[i].x) + ";" + to_string(p[i].y) + ";" + to_string(p[i].z) + "\n";
//	}
//	return str;
//}

// ���������� ����������� � ���� ������ ��� ������ .json
//string Plane::GetAsJSON()
//{
//	string str;
//	++NumberInJSON();
//	if (NumberInJSON() == 1)
//	{
//		str += "{ \n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 3,\n";
//	}
//	else
//	{
//		str += "\n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 3,\n";
//	}
//	str += "\"X\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].x) + "\n";
//			break;
//		}
//		str += to_string(p[i].x) + ",\n";
//
//	}
//	str += "],\n";
//	str += "\"Y\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].y) + "\n";
//			break;
//		}
//		str += to_string(p[i].y) + ",\n";
//
//	}
//	str += "],\n";
//	str += "\"Z\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].z) + "\n";
//			break;
//		}
//		str += to_string(p[i].z) + ",\n";
//
//	}
//	str += "]\n";
//	str += "},\n";
//	return str;
//}

// ������� ��������� ��������� � ������� ��������
vector <Point> Cylinder::CreateFooting(double r, double h)
{
	vector <Point> p;
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
	return p;
}

// ������� ��������� ��������� � ������� �������� � ���������� �������������� �����
vector <Point> Cylinder::CreateFooting(double r, double h, double o)
{
	vector <Point> p;
	Point dot;
	// x = r*cos(fi), y = r * sin(fi)
	double hlp_r = r;
	for (r; r > 0; r -= 2)  // ��������� ������� ����� ��� ���������� ���������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = GetNormDistNumb(r * cos(i),o);
			dot.y = GetNormDistNumb(0, o);;
			dot.z = GetNormDistNumb(r * sin(i), o);
			p.push_back(dot);
		}
	}
	for (hlp_r; hlp_r > 0; hlp_r -= 2)  // ��������� ������� ����� ��� ���������� �������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = GetNormDistNumb(hlp_r * cos(i),o);
			dot.y = GetNormDistNumb(h, o);
			dot.z = GetNormDistNumb(hlp_r * sin(i), o);
			p.push_back(dot);

		}
	}
	return p;
}

// ������� ��������� ������ ��������
vector <Point> Cylinder::CreateWalls(double r, double h)
{
	vector <Point> p;
	Point dot;
	double hlp_y = 0;
	double k = 0;
	while (hlp_y < h)
	{
		k = GetRandRealNumb(2, 4);
		hlp_y += k;
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = r * cos(i);
			dot.y = hlp_y;
			dot.z = r * sin(i);
			p.push_back(dot);
		}
	}
	return p;
}

// ������� ��������� ������ �������� � ���������� �������������� �����
vector <Point> Cylinder::CreateWalls(double r, double h, double o)
{
	vector <Point> p;
	Point dot;
	double hlp_y = 0;
	double k = 0;
	while (hlp_y < h)
	{
		k = GetRandRealNumb(2, 4);
		hlp_y += k;
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = GetNormDistNumb(r * cos(i), o);
			dot.y = GetNormDistNumb(hlp_y, o);
			dot.z = GetNormDistNumb(r * sin(i), o);
			p.push_back(dot);
		}
	}
	return p;
}

// ������� ��������� ����������-������ �����
//void Sphere::CreateFooting(double r)
//{
//	Point dot;
//	for (int i = 0; i <= 360; i += 2)
//	{
//		dot.x = r * cos(i);
//		dot.y = 0;
//		dot.z = r * sin(i);
//		p.push_back(dot);
//	}
//}

// ������� ��������� ������� ���������
//void Sphere::CreateUpHemisphere(double r)
//{
//	Point dot;
//	float hlp_y = 0;
//	float hlp_r = 0;
//	while (hlp_y < r)
//	{
//		if (hlp_y + 2 > r)
//		{
//			break;
//		}
//		hlp_y += GetRandRealNumb(2, 3);
//		hlp_r = sqrt(r * r - hlp_y * hlp_y);
//		for (int i = 0; i <= 360; i += GetRandRealNumb(1, 10))
//		{
//			dot.x = hlp_r * cos(i);
//			dot.y = hlp_y;
//			dot.z = hlp_r * sin(i);
//			p.push_back(dot);
//		}
//	}
//}

// ������� ��������� ������ ���������
//void Sphere::CreateDownHemisphere(double r)
//{
//	Point dot;
//	float hlp_y = 0;
//	float hlp_r = 0;
//	while ((-hlp_y) < r)
//	{
//		if (-(hlp_y - 2) > r)
//		{
//			break;
//		}
//		hlp_y -= GetRandRealNumb(2, 3);
//		hlp_r = sqrt(r * r - ((-hlp_y) * (-hlp_y)));
//		for (int i = 0; i <= 360; i += GetRandRealNumb(1, 10))
//		{
//			dot.x = hlp_r * cos(i);
//			dot.y = hlp_y;
//			dot.z = hlp_r * sin(i);
//			p.push_back(dot);
//		}
//	}
//}

string Figure::GetAsCSV(vector <vector <Point>> f)
{
	//ofstream CSV;
	//ifstream check("CSV.csv");
	//if (!check.is_open())
	//{
	//	CSV.open("CSV.csv");
	//	CSV << "Number;Type;ID;X;Y;Z" << endl;
	//	CSV.close();
	//}
	//CSV.open("CSV.csv", ios_base::app);
	//for (int i = 0; i < f.size(); i++)
	//{
	//	for (int g = 0; g < p.size(); g++)
	//	{
	//		CSV << NumberInCSV() << ';' << '1' << ';' << ID() << ';' << f[i][g].x << ';' << f[i][g].y << ';' << f[i][g].z << endl;
	//	}
	//}
	//CSV.close();
	string str;
	return str;
}

string Figure::GetAsJSON(vector <vector <Point>> f)
{
	string str;
	return str;
}

vector <Point> Figure::GetAsPoints(double o)
{
	vector <Point> p;
	return p;
}