#include "Menu.h"
Menu* Menu::current = nullptr;

void Menu::show() {
	current = this;
	printBorder(true);

	for (auto& item : this->items) {
		if (auto* ptr = std::get_if<MenuItem>(&item.second)) // if it's MenuItem, in map value
			printItem(item.first, ptr->first); // get first el (desc)
		else printItem(item.first, std::get<Menu>(item.second).desc); // else it's Menu, get desc field
	}

	if (this->parent != nullptr)
		printItem(backChar, "Back");
	printItem(exitChar, "Exit");

	printBorder(false);
}

void Menu::add(char key, std::string desc, _Menu_fptr_t func) {
	if (key == exitChar or key == backChar or items.contains(key))
		throw std::exception(std::format("`{}` char for menu item already used", key).c_str());
	items[key].emplace<0>(desc, func); // emplace as 0 - MenuItem
}

void Menu::add(char key, Menu& menu) {
	if (key == exitChar or key == backChar or items.contains(key))
		throw std::exception(std::format("`{}` char for menu item already used", key).c_str());
	menu.parent = this;
	items[key] = menu;
}

void Menu::run(_Menu_shape_cont& cont) {
	char ch;
	while (1) {
		std::cout << "Select item: " << CSI"93m";
		while (std::cin.peek() == '\n') {
			std::cin.ignore();
			std::cout << CSI"0m" << "Select item: " << CSI"93m";
		}
		std::cin.get(ch);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << CSI"0m";

		if (current->items.contains(ch)) {
			if (auto* ptr = std::get_if<0>(&current->items[ch])) { // if items is MenuItem, and ptr != nullptr
				std::cout << CSI"92m" << ptr->first << CSI"0m" << std::endl;
				ptr->second(cont);
				std::cout << std::endl;
				current->show();
			}
			else std::get<1>(current->items[ch]).show(); // otherwise it's Menu object
		}
		else if (ch == backChar and current->parent != nullptr) {
			std::cout << CSI"92m" << "Back" << CSI"0m" << std::endl;
			current->parent->show();
		}
		else if (ch == exitChar) {
			std::cout << CSI"92m" << "Exit" << CSI"0m" << std::endl;
			break;
		}
		else Menu::_PrintError("Input error");
	}
}

void Menu::_PrintError(std::string msg) {
	std::cerr << CSI"31m" << CSI"A" << CSI"K" << msg << CSI"0m" << std::endl;
}

void Menu::_PrintSplitBorder() {
	std::cout << CSI"36m";
	for (int i = 0; i < rightBorder; ++i, std::cout << ESC"(0" << 'q' << ESC"(B");
	std::cout << CSI"0m" << "\n";
}

void Menu::printItem(const char key, const std::string& desc) {
	std::cout << CSI"93m" << key << CSI"0m" << " -> " << CSI"92m" << desc; // print menu item
	std::cout << CSI << rightBorder << "G" << CSI"96m" << ESC"(0" << 'x' << ESC"(B"; // print border char
	std::cout << '\r' << std::endl;
}

void Menu::printBorder(bool drawTop) {
	std::cout << ESC"(0" << CSI"96m"; // enter line drawing mode, set color
	if (drawTop) {
		std::cout << 'l'; // draw left-corner char
		for (short i = 0; i < rightBorder - 2; i++, std::cout << 'q'); // draw line
		std::cout << 'k'; // draw right-corner char
		std::cout << ESC"(B" << CSI"91m" << CSI << rightBorder / 2 - this->desc.size() / 2 + 1 << "G" << this->desc << CSI"0m";
		// make padding
		std::cout << CSI << rightBorder / 2 - this->desc.size() / 2 << "G" << " ";
		std::cout << CSI << rightBorder / 2 - this->desc.size() / 2 + desc.size() + 1 << "G" << " ";
		std::cout << std::endl;
	}
	else {
		std::cout << 'm'; // draw left-corner char
		for (short i = 0; i < rightBorder - 2; i++, std::cout << 'q'); // draw line
		std::cout << 'j'; // draw right-corner char
		std::cout << ESC"(B" << CSI"0m" << std::endl; // quit line drawing mode & reset color
	}
}
