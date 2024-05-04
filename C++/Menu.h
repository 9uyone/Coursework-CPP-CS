#pragma once
#include <map>
#include <string>
#include <limits>
#include <format>
#include <variant>
#include "simpleVector.h"
#include "Shape.h"

#define ESC "\x1b"
#define CSI "\x1b["

constexpr const char _Menu_back = '-';
constexpr const char _Menu_exit = '0';
constexpr const uint16_t _Menu_right_border = 30;

using _Menu_shape_cont = simpleVector<std::shared_ptr<Shape>>;
//using _Menu_shape_cont = std::vector<std::shared_ptr<Shape>>;
using _Menu_fptr_t = void(*)(_Menu_shape_cont&);

struct MenuItem {
	std::string desc;
	_Menu_fptr_t action;

	MenuItem(std::string& d, _Menu_fptr_t& f) :
		desc(d),
		action(std::move(f)) {}

	MenuItem() = default;
};

class Menu {
private:
	Menu* parent = nullptr;
	static Menu* current;
	std::map<char, std::variant<MenuItem, Menu>> items;

public:
	std::string desc;

	Menu(std::string& desc) : desc(desc) {}
	Menu(std::string&& desc) : desc(std::move(desc)) {}

	void showMenu();

	void add(char key, std::string desc, _Menu_fptr_t func);
	void add(char key, Menu& menu);

	void cin_loop(_Menu_shape_cont& cont);

	static void _Print_error(std::string msg);
private:
	static void print_item(const char key, const std::string& desc);
	static void print_border(bool drawBottom = false);
};