
#define _USE_MATH_DEFINES
#include "Classes.h"
#include "Randomization.cpp"
#include <cmath>

// Конструктор поверхности с рандомным кол-вом точек (от 50 до 10000)
Plane::Plane()
{
	Point dot;
	Num_Points = GetRandIntNumb(50, 10000);
	angle = GetRandRealNumb(0, 360);
	double a = cos(angle * M_PI / 180.0);
	double b = sin(angle * M_PI / 180.0);              // Плоскость задана уравнением ax + by + c = z
	for (int i = 0; i < Num_Points; i++) {
		dot.x = GetRandRealNumb(-1, 1);
		dot.y = GetRandRealNumb(-1, 1);
		dot.z = -(a * dot.x + b * dot.y);
		p.push_back(dot);
	}
	f.push_back(p);
	++ID();
}

// Конструктор поверхности с заданным кол-вом точек (Num_Points)
Plane::Plane(int Num_Points)
{
	Point dot;
	angle = GetRandRealNumb(0, 360);
	double a = cos(angle * M_PI / 180.0);
	double b = sin(angle * M_PI / 180.0);
	for (int i = 0; i < Num_Points; i++) {
		dot.x = GetRandRealNumb(0, 1);
		dot.y = GetRandRealNumb(0, 1);
		dot.z = -(a * dot.x + b * dot.y);
		p.push_back(dot);
	}
	f.push_back(p);
	++ID();
}

// Конструткор рандомного цилиндра
Cylinder::Cylinder()
{
	
	h = GetRandRealNumb(5, 100);
	r = GetRandRealNumb(5, 100);
	// Генерация основания и вершины цилиндра
	CreateFooting(r, h);

	// Генерация стенок цилиндра
	CreateWalls(r, h);
	f.push_back(p);
	++ID();
}

// Конструктор цилиндра с заданным радиусом и высотой
Cylinder::Cylinder(double r, double h)
{
	// Генерация основания и вершины цилиндра
	CreateFooting(r, h);

	// Генерация стенок цилиндра
	CreateWalls(r, h);
	f.push_back(p);
	++ID();
}

// Конструктор рандомной сферы
Sphere::Sphere()
{
	
	r = GetRandRealNumb(5, 100);
	// Генерация образующей окружности сферы
	CreateFooting(r);

	// Генерация верхней полусферы
	CreateUpHemisphere(r);

	// Генерация нижней полусферы
	CreateDownHemisphere(r);

	f.push_back(p);
	++ID();
}

// Конструктор сферы с заданным радиусом
Sphere::Sphere(double r)
{
	// Генерация образующей окружности сферы
	CreateFooting(r);

	// Генерация верхней полусферы
	CreateUpHemisphere(r);

	// Генерация нижней полусферы
	CreateDownHemisphere(r);

	f.push_back(p);
	++ID();
}

void Figure::GetAsCSV()
{
	ofstream CSV;
	ifstream check("CSV.csv");
	if (!check.is_open())
	{
		CSV.open("CSV.csv");
		CSV << "Number;Type;ID;X;Y;Z" << endl;
		CSV.close();
	}
	CSV.open("CSV.csv", ios_base::app);
	for (int i = 0; i < f.size(); i++)
	{ 
		for (int g = 0; g < p.size(); g++)
		{
			CSV << Number() << ';' << '1' << ';' << ID() << ';' << f[i][g].x << ';' << f[i][g].y << ';' << f[i][g].z << endl;
		}
	}
	CSV.close();
}

void Figure::GetAsJSON()
{

}

// Запись цилиндра в CSV
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
		CSV << Number() << ';' << '1' << ';' << ID() << ';' << p[i].x << ';' << p[i].y << ';' << p[i].z << endl;
	}
	CSV.close();
}

// Запись цилиндра в JSON
void Cylinder::GetAsJSON()
{
	json j;
	ofstream JSON("JSON.json");
	++Number();
	for (int i = 0; i < p.size(); i++)
	{
		j = {
			{"Number", Number()},
			{"Type", 1},
			{"ID", ID()},
			{"X", p[i].x},
			{"Y", p[i].y},
			{"Z", p[i].z}
		};
	}
	JSON << setw(4) << j << endl;
}

// Запись сферы в CSV
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
		CSV << Number() << ';' << '2' << ';' << ID() << ';' << p[i].x << ';' << p[i].y << ';' << p[i].z << endl;
	}
	CSV.close();
}

// Запись сферы в JSON
void Sphere::GetAsJSON()
{

}


// Запись поверхности в CSV
void Plane::GetAsCSV()
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
		CSV << Number() << ';' << '3' << ';' << ID() << ';' << p[i].x << ';' << p[i].y << ';' << p[i].z << endl;
	}
	CSV.close();
}

// Запись поверхности в JSON
void Plane::GetAsJSON()
{
	
}

// Функция генерации основания и вершины цилиндра
void Cylinder::CreateFooting(double r, double h)
{
	Point dot;
	// x = r*cos(fi), y = r * sin(fi)
	double hlp_r = r;
	for (r; r > 0; r -= 2)  // изменение радиуса круга для заполнения основания
	{
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = r * cos(i);
			dot.y = 0;
			dot.z = r * sin(i);
			p.push_back(dot);
		}
	}
	for (hlp_r; hlp_r > 0; hlp_r -= 2)  // изменение радиуса круга для заполнения вершины
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

// Функция генерации стенок цилиндра
void Cylinder::CreateWalls(double r, double h)
{
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
}

// Функция генерации окружности-основы сферы
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

// Функция генерации верхней полусферы
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
		hlp_y += GetRandRealNumb(2, 3);
		hlp_r = sqrt(r * r - hlp_y * hlp_y);
		for (int i = 0; i <= 360; i += GetRandRealNumb(1, 10))
		{
			dot.x = hlp_r * cos(i);
			dot.y = hlp_y;
			dot.z = hlp_r * sin(i);
			p.push_back(dot);
		}
	}
}

// Функция генерации нижней полусферы
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
		hlp_y -= GetRandRealNumb(2, 3);
		hlp_r = sqrt(r * r - ((-hlp_y) * (-hlp_y)));
		for (int i = 0; i <= 360; i += GetRandRealNumb(1, 10))
		{
			dot.x = hlp_r * cos(i);
			dot.y = hlp_y;
			dot.z = hlp_r * sin(i);
			p.push_back(dot);
		}
	}
}