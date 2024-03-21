#pragma once
#include "Shape.h"
class Rectangle : public Shape {
public:
	//template<typename Vtx1, Vtx2>
	Rectangle(Vertex v1, Vertex v2) :
		Shape({v1,
			  {v1.get_x(), v2.get_y()},
			  v2,
			  {v2.get_x(), v1.get_y()}})
	{}
	virtual ~Rectangle() {}

public:
	void move(_Vertex_t deltaX, _Vertex_t deltaY) {
		for (auto& vtx : *this) {
			vtx += {deltaX, deltaY};
		}
	}

	double square() override {
		return std::fabs((vertices[2] - vertices[0]).get_x()) *
			std::fabs((vertices[2] - vertices[0]).get_y());
	}

public:
	// iostream operators
	void showInfo(std::ostream& os = std::cout) override {
		os << "RECTANGLE" << name << std::endl << "Coordinates:" << std::endl;
		for (Vertex& vtx : *this)
			os << "\x1b[4G" << vtx << std::endl;
		os << "Square: " << this->square() << std::endl;
	}
};