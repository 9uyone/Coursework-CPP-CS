#pragma once
#include "Shape.h"
class Square : public Shape {
//ctors & dtor
public:
	Square() : Shape() {}

	// by left bottom point and side length
	//template<typename InIt = std::istream_iterator<Vertex>> Square(InIt it = InIt(std::cin)) :
	//	Shape(1, it) {
	//	//_Vertex_t side = 5;
	//	add_vertex(vertices[0].get_x(), vertices[0].get_x() + side);
	//	add_vertex(vertices[0].get_x() + side, vertices[0].get_x() + side);
	//	add_vertex(vertices[0].get_x() + side, vertices[0].get_x());
	//} 

	// by left bottom point and side length
	Square(Vertex vtx, _Vertex_t side) :
		Shape({ { vtx.get_x(), vtx.get_y() },
			  { vtx.get_x(), vtx.get_y() + side },
			  { vtx.get_x() + side, vtx.get_y() + side },
			  { vtx.get_x() + side, vtx.get_y() } }) {}

	virtual ~Square() {}

//methods
public:
	void move(_Vertex_t deltaX, _Vertex_t deltaY) {
		for (auto& vtx : *this) {
			vtx += {deltaX, deltaY};
		}
	}

	double square() override {
		return pow(std::fabs(vertices[1].get_x() - vertices[0].get_x()), 2) +
			pow(std::fabs(vertices[1].get_y() - vertices[0].get_y()), 2);
	}

public:
// iostream operators
	friend std::ostream& operator<<(std::ostream& os, Square& obj) {
		os << "SQUARE" << std::endl << "Coordinates:" << std::endl;
		for (Vertex& vtx : obj)
			os << "\x1b[4G" << vtx << std::endl;
		os << "Square: " << obj.square() << std::endl;

		return os;
	}

	friend std::istream& operator>>(std::istream& is, Square& obj) {
		Vertex bl_vtx;
		int side;
		std::cin >> bl_vtx;
		

		return is;
	}
};