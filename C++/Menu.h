#pragma once
#include <unordered_map>
#include <string>
#include <limits>
#include <format>
#include <variant>
#include <vector>
#include "simpleVector.h"
#include "Shape.h"

#define ESC "\x1b"
#define CSI "\x1b["

const char _Menu_back = '-';
const char _Menu_exit = '0';
const uint16_t _Menu_right_border = 33;

//using _Menu_shape_cont = std::vector<std::shared_ptr<Shape>>;
using _Menu_shape_cont = simpleVector<std::shared_ptr<Shape>>;
using _Menu_func = void(*)(_Menu_shape_cont&);

struct MenuItem {
	std::string desc;
	_Menu_func action;

	MenuItem(std::string& d, _Menu_func& f) :
		desc(d),
		action(std::move(f)) {}

	MenuItem() = default;
};

class Menu {
private:
	Menu* parent = nullptr;
	static Menu* current;
	std::unordered_map<char, std::variant<MenuItem, Menu>> items;

public:
	std::string desc;

	Menu(std::string& desc) : desc(desc) {}
	Menu(std::string&& desc) : desc(std::move(desc)) {}

	void showMenu();

	void add(char key, std::string desc, _Menu_func func);
	void add(char key, Menu& menu);

	void cin_loop(_Menu_shape_cont& cont);

	static void _Print_error(std::string msg);
private:
	static void print_item(const char key, const std::string& desc);
	static void print_border(bool drawBottom = false);
};