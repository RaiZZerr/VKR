 
#include <fstream>
#include <iomanip>
#include "writefile.h"
#include <iostream>

using namespace std;

// Функция записи в файл
void WriteFile(const char fileName[],string a)
{
	if (fileName[strlen(fileName) - 1] == 'v' &&
		fileName[strlen(fileName) - 2] == 's' &&
		fileName[strlen(fileName) - 3] == 'c')
	{
		ofstream File;
		ifstream check(fileName);
		if (!check.is_open())
		{
			File.open(fileName);
			File << "Number;Type;X;Y;Z" << endl;
			File.close();
		}
		File.open(fileName, ios_base::app);
		File << a;
		File.close();
	}
	else if (fileName[strlen(fileName) - 1] == 'n' &&
			 fileName[strlen(fileName) - 2] == 'o' &&
			 fileName[strlen(fileName) - 3] == 's' &&
			 fileName[strlen(fileName) - 4] == 'j')
	{
		a += "}";
		a.erase(a.rfind(","), 1);
		ofstream JSON(fileName);
		JSON << setw(4) << a << endl;
	}

}

// Функция записи в файл формата .json
//void WriteInJSON(char fileName[], string a)
//{
//	a += "}";
//	a.erase(a.rfind(","), 1);
//	ofstream JSON(fileName);
//	JSON << setw(4) << a << endl;
//}