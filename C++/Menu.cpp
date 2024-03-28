#include "Menu.h"

void Menu::showMenu(Menu* menu) {
	//system("cls");
	current = menu;
	std::cout << CSI"91m" << CSI << _Menu_right_border / 2 - menu->desc.size() / 2 + 1 << "G" <<
		menu->desc <<
		CSI"0m" << std::endl;

	print_border();

	for (auto& item : menu->items)
		print_item(item.first, std::visit([](auto&& args) { return args.desc; }, item.second));

	if (menu->parent != nullptr)
		print_item(_Menu_back, "Back");
	print_item(_Menu_exit, "Exit");

	print_border(true);
}

void Menu::add(char key, std::string desc, _Menu_func func, MenuItem::acts actionType) {
	if (key == _Menu_exit or key == _Menu_back or items.contains(key))
		throw std::exception(std::format("`{}` char for menu item already used", key).c_str());
	items[key].emplace<0>(desc, func, actionType); // emplace as 0 - MenuItem
}

void Menu::add(char key, Menu& menu) {
	if (key == _Menu_exit or key == _Menu_back or items.contains(key))
		throw std::exception(std::format("`{}` char for menu item already used", key).c_str());
	menu.parent = this;
	items[key] = menu;
}

void Menu::cin_loop(_Menu_shape_cont& cont) {
	while (1) {
		std::cout << "\nSelect item: " << CSI"93m";
		while (std::cin.peek() == '\n') {
			std::cin.ignore();
			//std::cout << CSI"0m" << "Select item: " << CSI"93m";
		}
		char ch = std::cin.get();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << CSI"0m";

		if (ch == _Menu_exit)
			break;
		else if (ch == _Menu_back and current->parent != nullptr)
			showMenu(current->parent);

		else if (current->items.contains(ch)) {
			if (auto* ptr = std::get_if<0>(&current->items[ch])) { // if ptr != nullptr and items is MenuItem
				std::cout << CSI"92m" << ptr->desc << CSI"0m" << std::endl;
				/*if (const auto* f_ptr = std::get_if<1>(&current->items[ch].action))
					cont.push_back((*f_ptr)());
				else std::get<void(*)()>(current->items[ch].action)();*/
				auto& act = ptr->action;
				switch (ptr->actionType) {
					case MenuItem::acts::VOID:
						std::get<0>(act)();
						break;
					case MenuItem::acts::RETURNS:
						cont.push_back((*std::get<1>(act))());
						break;
					case MenuItem::acts::PARAMETER:
						(*std::get<2>(act))(cont);
						break;
				}
			} else showMenu(&std::get<1>(current->items[ch])); // otherwise it's Menu object
		}

		else {
			std::cout << CSI"31m" << CSI"A" << CSI"K";
			std::cerr << "Input error";
			std::cout << CSI"0m";
		}
	}
}

void Menu::print_item(const char key, const std::string& desc) {
	std::cout << CSI"G";
	std::cout << CSI"93m" << key << CSI"0m" << " -> " << CSI"92m" << desc; // print menu item
	std::cout << CSI << _Menu_right_border << "G" << CSI"96m" << ESC"(0" << 'x' << ESC"(B"; // print border char
	std::cout << '\r' << std::endl;
}

void Menu::print_border(bool drawBottom) {
	std::cout << ESC"(0" << CSI"96m" << (drawBottom?'m':'l'); // enter line drawing mode & set color
	for (short i = 0; i < _Menu_right_border - 2; i++, std::cout << 'q');
	std::cout << (drawBottom?'j':'k');
	std::cout << ESC"(B" << CSI"0m" << std::endl; // quit line drawing mode & reset color
}
