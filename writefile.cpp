 
#include <fstream>
#include <nlohmann/json.hpp>
#include "writefile.h"

using namespace std;

// Функция записи в файл формата .csv
void WriteInCSV(string a)
{
	ofstream File;
	ifstream check("File.csv");
	if (!check.is_open())
	{
		File.open("File.csv");
		File << "Number;Type;Id;X;Y;Z" << endl;
		File.close();
	}
	File.open("File.csv", ios_base::app);
	File << a;
	File.close();
}

// Функция записи в файл формата .json
void WriteInJSON(string a)
{
	a += "}";
	a.erase(a.rfind(","), 1);
	ofstream JSON("JSON.json");
	JSON << setw(4) << a << endl;
}