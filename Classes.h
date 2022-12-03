
#include <vector>
#include <random>

using namespace std;

class Cylinder {
	public:
		float r, h;
		vector <float> x;
		vector <float> y;
		vector <float> z;
		void CreateCylinder();
		void GetCSV();
};

class Surface {
	public:
		vector <float> x;
		vector <float> y;
		vector <float> z;
		void CreateSurface();
		void GetCSV();

};

class Sphere {
	public:
		float r;
		vector <float> x;
		vector <float> y;
		vector <float> z;
		void CreateSphere();
		void GetCSV();
};

void Surface::CreateSurface()
{

}

void Cylinder::CreateCylinder()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(5, 100);
	h = dist(gen);
	r = dist(gen);
	// x = r*cos(fi), y = r * sin(fi)
 
	// Генерация основания и вершины цилиндра
	for (float hlp_r = r; hlp_r > 0; hlp_r -= 10)  // изменение радиуса круга для заполнения основания
	{
		for (int i = 0; i <= 360; i += 20)
		{
			x.push_back(hlp_r* cos(i));
			y.push_back(0);
			z.push_back(hlp_r * sin(i));
			
		}
	}

	for (float hlp_r = r; hlp_r > 0; hlp_r -= 10)  // изменение радиуса круга для заполнения вершины
	{
		for (int i = 0; i <= 360; i += 20)
		{
			x.push_back(hlp_r * cos(i));
			y.push_back(h);
			z.push_back(hlp_r * sin(i));
			
		}
	}
	//---------------------------------------
	
	// Генерация стенок цилиндра
	float hlp_y = 0;
	float k = 0;
	while (hlp_y < h)
	{
		uniform_real_distribution<> dist(5, 10);
		k = dist(gen);
		hlp_y += k;
		for (int i = 0; i <= 360; i += 20)
		{
			x.push_back(r * cos(i));
			y.push_back(hlp_y);
			z.push_back(r * sin(i));
		}		
	}
}

void Sphere::CreateSphere()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(5, 100);
	r = dist(gen);

	// Генерация образующей окружности сферы
	for (int i = 0; i <= 360; i += 20)
	{
		x.push_back(r * cos(i));
		y.push_back(0);
		z.push_back(r * sin(i));
	}
	//--------------------------------------

	// Генерация верхней полусферы
	float hlp_y = 0;
	float hlp_r = 0;
	while (hlp_y < r)
	{
		uniform_real_distribution<> dist(5, 10);
		hlp_y += dist(gen);
		hlp_r = sqrt(r * r - hlp_y * hlp_y);
		for (int i = 0; i <= 360; i += 20)
		{
			x.push_back(hlp_r * cos(i));
			y.push_back(hlp_y);
			z.push_back(hlp_r * sin(i));
		}
	}
	//----------------------------------------

	// Генерация нижней полусферы
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

}

void Cylinder::GetCSV()
{

}

void Surface::GetCSV()
{

}