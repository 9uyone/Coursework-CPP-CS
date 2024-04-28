#include <iostream>
#include "menuMethods.h"
#include "Menu.h"
#include <algorithm>
#include "simpleVector.h"
#include <vector>

using namespace std;
namespace mm = menuMethods;

int main() {
#define MAIN_MENU
#ifndef MAIN_MENU
	try {
		simpleVector<int> sv = { -5, 6, -44, 72, 16 };
		simpleVector<int> sv2 = { 10, 100, -72, 36 };

		sv2.erase(sv2.begin() + 1);
		sv2.resize(2);
		sv2.insert(sv2.begin() + 1, 777);

		for (auto el : sv)
			cout << el << "\n";
		cout << "\n";
		for (auto el : sv2)
			cout << el << "\n";
	} catch (exception& ex) { cout << "EXCEPTION: " << ex.what() << endl; }

#else // MAIN_MENU
	_Menu_shape_cont shapes;

	try {
		Menu menu("Main menu");

		Menu create("Create");
		create.add('r', "Rectangle", mm::addRectangle);
		create.add('s', "Square", mm::addSquare);
		menu.add('c', create);

		Menu edit("Edit");
		edit.add('m', "Move", mm::move);
		edit.add('r', "Remove", mm::remove);
		edit.add('c', "Clear", mm::clear);
		menu.add('e', edit);

		Menu file("File");
		file.add('t', "Save to txt", mm::saveToTxt);
		file.add('j', "Save to json", mm::saveToJson);
		file.add('l', "Load from json", mm::fromJson);
		menu.add('f', file);

		Menu print("Print");
		print.add('p', "Print shape info", mm::printShapes);
		print.add('n', "Print shape names", mm::printNames);
		print.add('s', "Print max square", mm::printMaxSquare);
		menu.add('p', print);

		menu.showMenu();
		menu.cin_loop(shapes);
	}
	catch (exception& ex) {
		Menu::_Print_error(std::format("EXCEPTION: {}", ex.what()));
	}

#endif // MAIN_MENU
	return 0;
}