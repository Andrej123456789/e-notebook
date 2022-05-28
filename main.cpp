#include <iostream>
#include <string>

#include <map>
#include <vector>

#include <boost/range/combine.hpp>
#include <boost/tuple/tuple.hpp>

using namespace std;

vector<string> names = {"Babin-Čaljkušić Ameli", "Bakota Ivona", "Bartulin Andrej", "Bezjak Viljem", "Bilić-Matišić Stjepan", "Bilić-Prcić Paula", "Jagoda"};
vector<int> row = {};

map<string, int> students = 
{

};

void Help()
{
	cout << "Help: \n";
	cout << "a - show all students\n";
};

int init()
{
	sort(names.begin(), names.end());

	for (int i = 1; i < size(names) + 1; i++)
	{
		row.push_back(i);
	}
	
	try
	{
		for (auto const& [name, row2] : boost::combine(names, row))
		{
			auto position(end(students));
			position = students.insert
			(
				position,
				{
					name,
					row2
				}
			);
		}

		return 0;
	}

	catch (const std::exception& e)
	{
		cout << "Cathed exception: '" << e.what() << "'!\nReturning error...\n";
		return 1;
	}
};

int main(int argc, const char **argv)
{
	char selection;

	if (init() != 0)
	{
		return 1;
	}

	if (argc != 2)
	{
		cout << "Choose an option: ";
		cin >> selection;
	}

	else
	{
		selection = argv[1][0];
	}

	switch (selection)
	{
		case 'a':
			for (auto& x : students)
			{
				cout << "Name: " << x.first << " | Order: " << x.second << "\n";
			}

			break;

		case 'h':
			Help();
			break;

		default:
			Help();
			break;
	}

	return 0;
}
