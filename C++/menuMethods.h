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

namespace menuMethods {
	namespace cin_aux {
		_Vertex_t getUnsigned();
		std::string getName();
	}

	// creating
	std::shared_ptr<Shape> addRectangle();
	std::shared_ptr<Shape> addSquare();

	void printShapes(_Menu_shape_cont& cont);

	// save
	void saveToTxt(_Menu_shape_cont& cont);
	void saveToJson(_Menu_shape_cont& cont);
	void fromJson(_Menu_shape_cont& cont);

	// changing
	void change_vtx(_Menu_shape_cont& cont);

	// test
	void w();
	void d();
}