#pragma once
#include <iostream>
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"

namespace menuMethods {
	static void w() { std::cout << "ww\n"; }
	static void d() { std::cout << "ddd\n"; }
	
	static std::shared_ptr<Shape> addRectangle() {
		Vertex v1, v2;
		int side;
		std::cout << "Enter 1st point: ";
		std::cin >> v1;
		std::cout << "Enter 2nd point: ";
		std::cin >> v2;

		Rectangle obj(v1, v2);
		return std::make_shared<Rectangle>(obj);
	}

	static std::shared_ptr<Shape> addSquare() {
		Vertex bl_vtx;
		int side;
		std::cout << "Enter left bottom point: ";
		std::cin >> bl_vtx;
		std::cout << "Enter side: ";
		std::cin >> side;

		Square obj(bl_vtx, side);
		return std::make_shared<Square>(obj);
	}
}