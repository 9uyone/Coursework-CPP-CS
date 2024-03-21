#include <iostream>
#include <vector>
#include "menuMethods.cpp"
#include "Menu.h"
using namespace std;

namespace mm = menuMethods;

int main() {
	vector<std::shared_ptr<Shape>> shapes;

	Menu menu;
	menu.add('r', "Add rectangle", mm::addRectangle);
	menu.add('s', "Add square", mm::addSquare);

	Menu::showMenu(&menu);
	menu.cin_loop(&shapes);
	
	for (auto i : shapes)
		cout << i->square() << endl;
	return 0;
}