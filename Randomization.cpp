
#include <random>

using namespace std;

inline double GetRandRealNumb(int min, int max); // ������� ��������� ���������� ������������� ����� � ��������� �� min �� max
inline int GetRandIntNumb(int min, int max); // ������� ��������� ���������� ������ ����� � ��������� �� min �� max

// ������� ��������� ���������� ������������� ����� � ��������� �� min �� max
double GetRandRealNumb(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(min, max);
	return dist(gen);
}

// ������� ��������� ���������� ������ ����� � ��������� �� min �� max
int GetRandIntNumb(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}