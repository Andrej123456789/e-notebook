#include <iostream>
#include <string>

#include <map>
#include <vector>

#include <boost/range/combine.hpp>
#include <boost/tuple/tuple.hpp>

using namespace std;

vector<string> names = {"Test", "New"};
vector<int> row = {};

map<string, int> students = 
{

};

void Help()
{
	cout << "Help: \n";
	cout << "a - show all students\n";
	cout << "+ - add new name to 'names' list\n";
};

int init()
{
	row.clear();

	sort(names.begin(), names.end());

	for (size_t i = 1; i < names.size() + 1; i++)
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
	string name;
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

	while (selection != 'x')
	{
		switch (selection)
		{
			case 'a':
				for (auto& x : students)
				{
					cout << "Name: " << x.first << " | Order: " << x.second << "\n";
				}

				break;

			case '+':
				cout << "Enter name: ";
				cin >> name;
				names.push_back(name);
				name = " ";

				init();
				break;

			case '-':
				cout << "Enter name to remove: ";
				cin >> name;

				for (auto i = names.begin(); i != names.end(); ++i)
				{
					if (*i == name)
					{
						names.erase(i);
						i--;
					}
				}

				students.clear();
				init();
				break;

			case 'h':
				Help();
				break;

			case 'x':
				break;

			default:
				Help();
				break;
		}

		cout << "Choose an option: ";
		cin >> selection;
	}

	return 0;
}
