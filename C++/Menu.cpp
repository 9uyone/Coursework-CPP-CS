#include "Menu.h"
Menu* Menu::current = nullptr;

void Menu::showMenu() {
	current = this;
	std::cout << CSI"91m" << CSI << _Menu_right_border / 2 - this->desc.size() / 2 + 1 << "G" <<
		this->desc << CSI"0m" << std::endl;

	print_border();

	for (auto& item : this->items)
		print_item(item.first, std::visit([](auto&& args) { return args.desc; }, item.second));

	if (this->parent != nullptr)
		print_item(_Menu_back, "Back");
	print_item(_Menu_exit, "Exit");

	print_border(true);
}

void Menu::add(char key, std::string desc, _Menu_fptr func) {
	if (key == _Menu_exit or key == _Menu_back or items.contains(key))
		throw std::exception(std::format("`{}` char for menu item already used", key).c_str());
	items[key].emplace<0>(desc, func); // emplace as 0 - MenuItem
}

void Menu::add(char key, Menu& menu) {
	if (key == _Menu_exit or key == _Menu_back or items.contains(key))
		throw std::exception(std::format("`{}` char for menu item already used", key).c_str());
	menu.parent = this;
	items[key] = menu;
}

void Menu::cin_loop(_Menu_shape_cont& cont) {
	char ch;
	while (1) {
		std::cout << "Select item: " << CSI"93m";
		while (std::cin.peek() == '\n') {
			std::cin.ignore();
		}
		std::cin.get(ch);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << CSI"0m";

		if (current->items.contains(ch)) {
			if (auto* ptr = std::get_if<0>(&current->items[ch])) { // if ptr != nullptr and items is MenuItem
				std::cout << CSI"92m" << ptr->desc << CSI"0m" << std::endl;
				(ptr->action)(cont);
				std::cout << std::endl;
				current->showMenu();
			}
			else std::get<1>(current->items[ch]).showMenu(); // otherwise it's Menu object
		}
		else if (ch == _Menu_back and current->parent != nullptr) {
			std::cout << CSI"92m" << "Back" << CSI"0m" << std::endl;
			current->parent->showMenu();
		}
		else if (ch == _Menu_exit) {
			std::cout << CSI"92m" << "Exit" << CSI"0m" << std::endl;
			break;
		}
		else Menu::_Print_error("Input error");
	}
}

void Menu::_Print_error(std::string msg) {
	std::cerr << CSI"31m" << CSI"A" << CSI"K" << msg << CSI"0m" << std::endl;
}

void Menu::print_item(const char key, const std::string& desc) {
	std::cout << CSI"93m" << key << CSI"0m" << " -> " << CSI"92m" << desc; // print menu item
	std::cout << CSI << _Menu_right_border << "G" << CSI"96m" << ESC"(0" << 'x' << ESC"(B"; // print border char
	std::cout << '\r' << std::endl;
}

void Menu::print_border(bool drawBottom) {
	std::cout << ESC"(0" << CSI"96m" << (drawBottom ? 'm' : 'l'); // enter line drawing mode & set color
	for (short i = 0; i < _Menu_right_border - 2; i++, std::cout << 'q');
	std::cout << (drawBottom ? 'j' : 'k');
	std::cout << ESC"(B" << CSI"0m" << std::endl; // quit line drawing mode & reset color
}
