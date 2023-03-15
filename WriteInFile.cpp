 
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;

inline void WriteInCSV(string a);
inline void WriteInJSON(string a);

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

void WriteInJSON(string a)
{
	a += "}";
	a.erase(a.rfind(","), 1);
	ofstream JSON("JSON.json");
	JSON << setw(4) << a << endl;
}