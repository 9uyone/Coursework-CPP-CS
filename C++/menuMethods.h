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
		std::string getNameWithFindCheck(_Menu_shape_cont& cont);
		std::string getFileName(std::string prompt, std::string fileext);
		int getIndex(_Menu_shape_cont& cont);
		Vertex getVertex(std::string prompt);
	}

	namespace os_aux {
		void outputMaxSquare(std::ostream& os, _Menu_shape_cont& cont);
		std::shared_ptr<Shape> getMaxSquareShape(_Menu_shape_cont& cont);
	}

	// create
	void addRectangle(_Menu_shape_cont& cont);
	void addSquare(_Menu_shape_cont& cont);

	// print
	void printShapeInfo(_Menu_shape_cont& cont);
	void printNames(_Menu_shape_cont& cont);
	void printMaxSquare(_Menu_shape_cont& cont);

	// file
	void saveAsTxt(_Menu_shape_cont& cont);
	void saveAsJson(_Menu_shape_cont& cont);
	void fromJson(_Menu_shape_cont& cont);

	// change
	void move(_Menu_shape_cont& cont);
	void remove(_Menu_shape_cont& cont);
	void clear(_Menu_shape_cont& cont);
}