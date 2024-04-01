#include <iostream>
#include <vector>
#include "menuMethods.h"
#include "Menu.h"
#include <algorithm>
using namespace std;
namespace mm = menuMethods;

int main() {
	vector<std::shared_ptr<Shape>> shapes;

	try {
		Menu menu("Main menu");
		Menu create("Create");
		create.add('r', "Rectangle", mm::addRectangle, MenuItem::acts::PARAMETER);
		create.add('s', "Square", mm::addSquare, MenuItem::acts::PARAMETER);
		menu.add('c', create);

		Menu modify("Modify");
		modify.add('m', "Move", mm::move, MenuItem::acts::PARAMETER);
		menu.add('m', modify);

		Menu save_load("File");
		save_load.add('t', "Save to txt", mm::saveToTxt, MenuItem::acts::PARAMETER);
		save_load.add('j', "Save to json", mm::saveToJson, MenuItem::acts::PARAMETER);
		save_load.add('l', "Load from json", mm::fromJson, MenuItem::acts::PARAMETER);
		menu.add('f', save_load);

		menu.add('p', "Print created shapes", mm::printShapes, MenuItem::acts::PARAMETER);

		Menu::showMenu(&menu);
		menu.cin_loop(shapes);
	}
	catch (exception& ex) {
		cout << "\n\x1b[31m" << "EXCEPTION: " << ex.what();
	}

	if (!shapes.empty()) {
		cout << "\nMax square: " << max_element(shapes.begin(), shapes.end(),
			[](auto& p1, auto& p2) { return p1->square() < p2->square(); })->get()->square();
	}

	return 0;
}