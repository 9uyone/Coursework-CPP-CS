#pragma once
#include "menuMethods.cpp"
#include <unordered_map>
#include <string>
#include <limits>
#include <format>
#include <variant>
#include <vector>
#include "Shape.h"

#define ESC "\x1b"
#define CSI "\x1b["

const char _Menu_back = '-';
const char _Menu_exit = '0';
const uint16_t _Menu_right_border = 33;

using _Menu_f1_ptr = void(*)();
using _Menu_f2_ptr = std::shared_ptr<Shape>(*)();
using _Menu_func = std::variant<_Menu_f1_ptr, _Menu_f2_ptr>;

struct MenuItem {
	std::string desc;
	_Menu_func action;
	
	MenuItem(std::string& d, _Menu_func& f) {
		this->desc = d;
		this->action = std::move(f);
	}
	MenuItem() = default;
};

class Menu {
private:
	Menu* parent = nullptr;
	static inline Menu* current = nullptr;

	std::unordered_map<char, MenuItem> items;
	std::unordered_map<char, Menu> submenus;

public:
	std::string desc;

	Menu(std::string desc = "Main menu") : desc(desc) {}

	static void showMenu(Menu* menu) {
		//system("cls");
		current = menu;
		std::cout << CSI"93m" << CSI << _Menu_right_border/2 - menu->desc.size()/2 + 1 << "G" <<
			menu->desc <<
			CSI"0m" << std::endl;

		print_border();

		for (auto& item : menu->items)
			print_item(item.first, item.second.desc);
		for (auto& submenu : menu->submenus)
			print_item(submenu.first, submenu.second.desc);
		
		if (menu->parent != nullptr)
			print_item(_Menu_back, "back");
		print_item(_Menu_exit, "exit");

		print_border(true);
	}

	void add(char key, std::string desc, _Menu_func func) {
		if (key == _Menu_exit or key == _Menu_back or submenus.contains(key) or !items.try_emplace(key, desc, func).second)
			throw std::exception(std::format("{} char for menu item already used", key).c_str());
	}

	void add(char key, Menu& menu) {
		if (key == _Menu_exit or key == _Menu_back or items.contains(key))
			throw std::exception(std::format("{} char for menu item already used", key).c_str());
		menu.parent = this;
		submenus[key] = menu;
	}

	void cin_loop(std::vector<std::shared_ptr<Shape>>* shapes = nullptr) {
		while (1) {
			std::cout << std::endl << "Select item: " << CSI"93m";
			while (std::cin.peek() == '\n')	std::cin.ignore();
			char ch = std::cin.get();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << CSI"0m";

			if (ch == _Menu_exit)
				break;
			else if (ch == _Menu_back and current->parent != nullptr)
				showMenu(current->parent);

			else if (current->items.contains(ch)) {
				std::cout << CSI"92m" << current->items[ch].desc << CSI"0m" << std::endl;
				if (shapes != nullptr) {
					if (const auto* f_ptr = std::get_if<1>(&current->items[ch].action)) {
						shapes->push_back((*f_ptr)());
					}
				}
				else std::get<void(*)()>(current->items[ch].action)();
			}
			else if (current->submenus.contains(ch))
				showMenu(&current->submenus.find(ch)->second);

			else {
				std::cout << CSI"31m" << CSI"A" << CSI"K";
				std::cerr << "Input error";
				std::cout << CSI"0m";
			}
		}
	}

private:
	inline static void print_item(const char key, const std::string& desc) {
		std::cout << CSI"G";
		std::cout << CSI"93m" << key << CSI"0m" << " -> " << CSI"92m" << desc; // print menu item
		std::cout << CSI << _Menu_right_border << "G" << CSI"96m" << ESC"(0" << 'x' << ESC"(B"; // print border char
		std::cout << '\r' << std::endl;
	}

	inline static void print_border(bool drawBottom = false) {
		std::cout << ESC"(0" << CSI"96m" << (drawBottom ? 'm' : 'l'); // enter line drawing mode & set color
		for (short i = 0; i < _Menu_right_border - 2; i++, std::cout << 'q');
		std::cout << (drawBottom ? 'j' : 'k');
		std::cout << ESC"(B" << CSI"0m" << std::endl; // quit line drawing mode & reset color
	}
};