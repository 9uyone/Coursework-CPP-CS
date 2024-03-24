#include <iostream>
#include <vector>
#include "menuMethods.h"
#include "Menu.h"
#include <algorithm>
using namespace std;
namespace mm = menuMethods;

int main() {
	vector<std::shared_ptr<Shape>> shapes;

	Menu menu;
	menu.add('r', "Add rectangle", mm::addRectangle, MenuItem::acts::RETURNS);
	menu.add('s', "Add square", mm::addSquare, MenuItem::acts::RETURNS);
	menu.add('c', "Change vertex", mm::change_vtx, MenuItem::acts::PARAMETER);
	menu.add('p', "Print created shapes", mm::printShapes, MenuItem::acts::PARAMETER);
	menu.add('t', "Save shapes to txt", mm::saveToTxt, MenuItem::acts::PARAMETER);
	menu.add('j', "Save shapes to json", mm::saveToJson, MenuItem::acts::PARAMETER);
	menu.add('f', "Load shapes from json", mm::fromJson, MenuItem::acts::PARAMETER);

	Menu::showMenu(&menu);
	try {
		menu.cin_loop(shapes);
	}
	catch (exception& ex) {
		cout << "EXCEPTION: " << ex.what();
	}

	if (!shapes.empty()) {
		cout << "\nMax square: " << max_element(shapes.begin(), shapes.end(),
			[](auto& p1, auto& p2) { return p1->square() < p2->square(); })->get()->square();
	}
	return 0;
}