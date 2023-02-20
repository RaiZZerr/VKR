
#include <random>

using namespace std;

inline double GetRandRealNumb(int min, int max); // Функция генерации рандомного вещественного числа в диапазоне от min до max
inline int GetRandIntNumb(int min, int max); // Функция генерации рандомного целого числа в диапазоне от min до max

// Функция генерации рандомного вещественного числа в диапазоне от min до max
double GetRandRealNumb(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(min, max);
	return dist(gen);
}

// Функция генерации рандомного целого числа в диапазоне от min до max
int GetRandIntNumb(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}