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

constexpr const uint16_t _Menu_right_border = 30;
constexpr const char _Menu_back = 'b';
constexpr const char _Menu_exit = 'e';

using _Menu_shape_cont = simpleVector<std::shared_ptr<Shape>>;
using _Menu_fptr_t = void(*)(_Menu_shape_cont&);
using MenuItem = std::pair<std::string, _Menu_fptr_t>;

class Menu {
private:
	Menu* parent = nullptr;
	static Menu* current;
	std::map<char, std::variant<MenuItem, Menu>> items;

public:
	std::string desc;

	Menu(std::string& desc) : desc(desc) {}
	Menu(std::string&& desc) : desc(std::move(desc)) {}

	void show();
	
	void add(char key, std::string desc, _Menu_fptr_t func);
	void add(char key, Menu& menu);

	void run(_Menu_shape_cont& cont);

public: // static aux methods
	static void _PrintError(std::string msg);
	static void _PrintSplitBorder();
private:
	static void printItem(const char key, const std::string& desc);
	static void printBorder(bool drawBottom = false);
};