#include <iostream>
#include "Shape.h"
#include <unordered_map>
#include <functional>
#include "menuMethods.cpp"

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

	Vertex vtx;
	Vertex tmp(4, 7);
	vtx.set_x(Vertex(11, 2));
	vtx.set_y(tmp);
	//cin >> vtx;
	cout << endl << vtx;
	return 0;
}

inline void showMenu(const unordered_map<char, pair<string, function<void()>>>& menu) {
	for (auto& [key, desc_func] : menu)
		cout << key << " - " << desc_func.first << endl;
	cout << endl;
}