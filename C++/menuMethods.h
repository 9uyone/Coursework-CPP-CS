#pragma once
#include <iostream>
#include "Vertex.h"
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Menu.h"

namespace menuMethods {
	namespace cin_aux {
		_Vertex_t get_unsigned();
	}

	// creating acts
	std::shared_ptr<Shape> addRectangle();
	std::shared_ptr<Shape> addSquare();

	void printShapes(_Menu_shape_cont& cont);
	
	//void saveToJson()

	// changing acts
	void change_vtx(_Menu_shape_cont& cont);

	// test
	void w();
	void d();
}