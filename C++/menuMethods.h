#pragma once
#include <iostream>
#include "Vertex.h"
#include "Square.h"
#include "Rectangle.h"
#include "Menu.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
#include <regex>
#include <format>
#include <algorithm>
#include <iterator>

namespace menuMethods {
	namespace cin_aux {
		_Vertex_t getUnsigned(std::string prompt);
		std::string getName(std::string prompt);
		int getIndex(_Menu_shape_cont& cont);
	}

	// creating
	void addRectangle(_Menu_shape_cont& cont);
	void addSquare(_Menu_shape_cont& cont);

	// printing
	void printShapes(_Menu_shape_cont& cont);
	void printNames(_Menu_shape_cont& cont);

	// file
	void saveToTxt(_Menu_shape_cont& cont);
	void saveToJson(_Menu_shape_cont& cont);
	void fromJson(_Menu_shape_cont& cont);

	// changing
	void move(_Menu_shape_cont& cont);
	void remove(_Menu_shape_cont& cont);
	void clear(_Menu_shape_cont& cont);
}