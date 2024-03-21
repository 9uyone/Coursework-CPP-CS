#pragma once
#include "Shape.h"
class Rectangle : public Shape {
public:
	//template<typename Vtx1, Vtx2>
	Rectangle(Vertex v1, Vertex v2) :
		Shape({ v1, {v1.get_x(), v2.get_y()}, v2, {v2.get_x(), v1.get_y()}})
	{}
	virtual ~Rectangle() {}

public:
	void move(_Vertex_t deltaX, _Vertex_t deltaY) {
		for (auto& vtx : *this) {
			vtx += {deltaX, deltaY};
		}
	}

	double square() override {
		return pow(std::fabs(vertices[1].get_x() - vertices[0].get_x()), 2) +
			pow(std::fabs(vertices[1].get_y() - vertices[0].get_y()), 2);;
	}

public:
	// iostream operators
	friend std::ostream& operator<<(std::ostream& os, Rectangle& obj) {
		os << "RECTANGLE" << std::endl << "Coordinates:" << std::endl;
		for (Vertex& vtx : obj)
			os << "\x1b[4G" << vtx << std::endl;
		os << "Square: " << obj.square() << std::endl;

		return os;
	}
};