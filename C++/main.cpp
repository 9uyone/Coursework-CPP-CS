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
		create.add('r', "Rectangle", mm::addRectangle);
		create.add('s', "Square", mm::addSquare);
		menu.add('c', create);

		Menu edit("Edit");
		edit.add('m', "Move", mm::move);
		edit.add('r', "Remove", mm::move);
		menu.add('e', edit);

		Menu save_load("File");
		save_load.add('t', "Save to txt", mm::saveToTxt);
		save_load.add('j', "Save to json", mm::saveToJson);
		save_load.add('l', "Load from json", mm::fromJson);
		menu.add('f', save_load);

		menu.add('p', "Print shape info", mm::printShapes);
		menu.add('n', "Print shape names", mm::printNames);

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