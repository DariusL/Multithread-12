#include <omp.h>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

struct Struct
{
	string pav;
	int kiekis;
	double kaina;
	Struct(string input);
	string Print();
};

Struct::Struct(string input)
{
	int start, end;
	start = 0;
	end = input.find(' ');
	pav = input.substr(0, end);
	start = end + 1;
	end = input.find(' ', start);
	kiekis = stoi(input.substr(start, end - start));
	start = end + 1;
	kaina = stod(input.substr(start));
}

string Struct::Print()
{
	stringstream ss;
	ss << setw(20) << pav << setw(5) << kiekis << setw(20) << kaina << endl;
	return ss.str();
}

vector<vector<Struct>> ReadStuff(string file);
vector<string> ReadLines(string file);

int main()
{
	auto input = ReadStuff("LapunasD.txt");
	return 0;
}

vector<vector<Struct>> ReadStuff(string file)
{
	auto lines = ReadLines(file);
	vector<vector<Struct>> ret;
	vector<Struct> tmp;
	for(int i = 0; i < lines.size(); i++)
	{
		if(lines[i] == "")
		{
			ret.push_back(tmp);
			tmp = vector<Struct>();
		}
		else
		{
			tmp.emplace_back(lines[i]);
		}
	}
	return ret;
}

vector<string> ReadLines(string file)
{
	vector<string> ret;
	ifstream duom(file);
	while(!duom.eof())
	{
		string line;
		getline(duom, line);
		ret.push_back(line);
	}
	return ret;
}