
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

void Surface::CreateSurface()
{

}

void Cylinder::CreateCylinder()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(1, 100);
	h = dist(gen);
	r = dist(gen);
	// x = r*cos(fi), y = r * sin(fi)
 
	// Генерация основания цилиндра
	for (float hlpr = r; hlpr > 0; hlpr -= 10)
	{
		for (int i = 0; i <= 360; i += 5)
		{
			x.push_back(hlpr* cos(i));
			z.push_back(hlpr * sin(i));
			y.push_back(0);
		}
	}
	//---------------------------------------
	
	// Генерация стенок цилиндра
	while ( <= h)
}