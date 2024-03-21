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

	Menu::showMenu(&menu);
	
	menu.cin_loop(shapes);

	cout << "Max square: " << max_element(shapes.begin(), shapes.end(), [](auto& p1, auto& p2) { return p1->square() < p2->square(); })->get()->square();

	return 0;
}