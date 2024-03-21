#pragma once
#include "menuMethods.h"

#define CSI "\x1b["

namespace menuMethods {
	namespace cin_aux {
		_Vertex_t get_unsigned() {
			while (1) {
				_Vertex_t n;
				std::cin >> n;
				if (!std::cin.good() or n <= 0) {
					std::cin.clear();
					std::cerr << CSI"31m" << CSI"K" << "The value should be > 0\n" << CSI"0m";
				} else return n;
			}
		}
	}
	
	std::shared_ptr<Shape> addRectangle() {
		Vertex v1, v2;
		std::cout << "Enter 1st point: ";
		std::cin >> v1;
		std::cout << "Enter 2nd point: ";
		std::cin >> v2;

		Rectangle obj(v1, v2);
		return std::make_shared<Rectangle>(std::move(obj));
	}

	std::shared_ptr<Shape> addSquare() {
		Vertex bl_vtx;
		std::cout << "Enter left bottom point: ";
		std::cin >> bl_vtx;
		std::cout << "Enter side: ";
		_Vertex_t side = cin_aux::get_unsigned();

		Square obj(bl_vtx, side);
		return std::make_shared<Square>(std::move(obj));
	}

	void printShapes(_Menu_shape_cont& cont) {
		for (auto& obj : cont)
			std::cout << *obj << std::endl;
	}

	void change_vtx(_Menu_shape_cont& cont) {
		cont[0]->operator[](2) = { 3, -2 };
	}

	void w() { std::cout << "ww\n"; }
	void d() { std::cout << "ddd\n"; }
}