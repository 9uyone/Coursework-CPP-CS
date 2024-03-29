#pragma once
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

using _Menu_shape_cont = std::vector<std::shared_ptr<Shape>>;
using _Menu_func = std::variant<void(*)(), std::shared_ptr<Shape>(*)(), void(*)(_Menu_shape_cont&)>;

struct MenuItem {
	std::string desc;
	_Menu_func action;

	static enum acts { // type of item function
		NOTHING,	// void(*)()
		RETURNS,	// std::shared_ptr<Shape>(*)()
		PARAMETER	// void(*)(_Menu_shape_cont&)
	};
	acts actionType;

	MenuItem(std::string& d, _Menu_func& f, acts actionType) :
		desc(d),
		action(std::move(f)),
		actionType(actionType) {}

	MenuItem() = default;
};

class Menu {
private:
	Menu* parent = nullptr;
	static inline Menu* current = nullptr;
	std::unordered_map<char, std::variant<MenuItem, Menu>> items;

public:
	std::string desc;

	Menu(std::string& desc) : desc(desc) {}
	Menu(std::string&& desc = "Main menu") : desc(std::move(desc)) {}

	static void showMenu(Menu* menu);

	void add(char key, std::string desc, _Menu_func func, MenuItem::acts actionType);
	void add(char key, Menu& menu);

	void cin_loop(_Menu_shape_cont& cont);

private:
	static void print_item(const char key, const std::string& desc);
	static void print_border(bool drawBottom = false);
};