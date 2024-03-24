#pragma once
#include "Shape.h"

class Square : public Shape {
public: // ctors & dtor
	//Square() : Shape() {}

	// by left bottom point and side length
	//template<typename InIt = std::istream_iterator<Vertex>> Square(InIt it = InIt(std::cin)) :
	//	Shape(1, it) {
	//	//_Vertex_t side = 5;
	//	add_vertex(vertices[0].get_x(), vertices[0].get_x() + side);
	//	add_vertex(vertices[0].get_x() + side, vertices[0].get_x() + side);
	//	add_vertex(vertices[0].get_x() + side, vertices[0].get_x());
	//} 

	// by vertices
	
	Square(std::initializer_list<Vertex> ilist) : Shape(ilist) {
		if (ilist.size() != 4)
			throw std::invalid_argument("Square requires 4 vertices");

		if (((*this)[1] - (*this)[0]) != ~((*this)[3] - (*this)[2]))
			throw std::invalid_argument("The given points don't form a square");
	}

	// by left bottom point and side length
	Square(Vertex vtx, _Vertex_t side) :
		Shape({ { vtx.get_x(), vtx.get_y() },
			  { vtx.get_x(), vtx.get_y() + side },
			  { vtx.get_x() + side, vtx.get_y() + side },
			  { vtx.get_x() + side, vtx.get_y() } })
	{
		if (side <= 0)
			throw std::invalid_argument("Side length should be > 0");
	}
	// @brief copies vertices using iterator
	template<typename InIt>
	//requires (std::is_base_of_v<std::input_iterator_tag, InIt>)
	Square(InIt it_begin) :
		Shape(4, it_begin) {}

	virtual ~Square() {}

//methods
public:
	void move(_Vertex_t deltaX, _Vertex_t deltaY) {
		for (auto& vtx : *this) {
			vtx += {deltaX, deltaY};
		}
	}

	double square() override {
		return std::pow(std::fabs((vertices[1] - vertices[0]).get_y()), 2);
	}

	nlohmann::json makeJson() override {
		nlohmann::json json;
		json["type"] = "Square";
		//json["name"] = name;
		json["square"] = square();
		json["vertices"] = nlohmann::json::array();
		for (Vertex& vtx : *this) {
			json["vertices"].push_back({ { "x", vtx.get_x() }, { "y", vtx.get_y() } });
		}

		return json;
	}

public:
// iostream operators
	void showInfo(std::ostream& os = std::cout) override {
		os << "SQUARE " << name << std::endl << "Vertices:" << std::endl;
		os << "Square: " << this->square() << std::endl;
		for (Vertex& vtx : *this)
			os << "\x1b[4G" << vtx << std::endl;
	}

	friend std::istream& operator>>(std::istream& is, Square& obj) {
		Vertex bl_vtx;
		int side;
		std::cin >> bl_vtx;
		

		return is;
	}
};