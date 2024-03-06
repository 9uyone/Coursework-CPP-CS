#include <iostream>
#include "Shape.h"
#include <unordered_map>
#include <functional>
#include "menuMethods.cpp"
#include <list>
#include <vector>
#include <fstream>

using namespace std;

inline void showMenu(const unordered_map<char, pair<string, function<void()>>>& menu);

int main() {
	/*unordered_map<char, pair<string, function<void()>>> menu;
	menu.try_emplace('w', "w_desc", menu::w);
	menu.try_emplace('d' ,"d_desc", menu::d);
	menu.try_emplace('q', "exit", menu::exit);

	showMenu(menu);
	while (1) {
		while (cin.peek() == '\n') cin.ignore();
		char c = cin.get();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

		if (menu.contains(c))
			menu[c].second();
		else {
			cerr << "Incorrect!\n";
		}
	}*/


	//vector<Vertex> vec{{9, 5}, {-4, -6}, {0, 7}};
	//list<Vertex> lst{{9, 5}, {-4, -6}, {0, 7}};
	//Shape shp(3, lst.begin());
	try {
		ifstream file("v.txt");	Shape shp(4, istream_iterator<Vertex>(file));
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	/*Shape shp;
	//Vertex vtx(10, -7);
	// shp.add_vertex(vtx);
	shp.add_vertex(Vertex(-9, 4));
	*/
	return 0;
}

/*inline void showMenu(const unordered_map<char, pair<string, function<void()>>>& menu) {
	for (auto& [key, desc_func] : menu)
		cout << key << " - " << desc_func.first << endl;
	cout << endl;
}*/