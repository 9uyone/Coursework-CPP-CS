#include <iostream>
#include "menuMethods.h"
#include "Menu.h"
#include "simpleVector.h"

using namespace std;
namespace mm = menuMethods;

int main() {
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
		file.add('t', "Save as txt", mm::saveAsTxt);
		file.add('j', "Save as json", mm::saveAsJson);
		file.add('l', "Load from json", mm::fromJson);
		menu.add('f', file);

		menu.add('i', "Print shape info", mm::printShapeInfo);
		menu.add('n', "Print shape names", mm::printNames);
		menu.add('m', "Max square", mm::printMaxSquare);
		
		menu.show();
		menu.run(shapes);
	}
	catch (exception& ex) {
		Menu::_PrintError(std::format("EXCEPTION: {}", ex.what()));
		system("pause");
	}

	return 0;
}