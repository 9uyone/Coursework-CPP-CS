#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public: // ctors & dtor

	//template<typename Vtx1, Vtx2>
	Rectangle(Vertex v1, Vertex v2) :
		Shape({v1,
			  {v1.get_x(), v2.get_y()},
			  v2,
			  {v2.get_x(), v1.get_y()}})
	{}

	Rectangle(std::initializer_list<Vertex> ilist) : Shape(ilist) {
		if (ilist.size() != 4)
			throw std::invalid_argument("Square requires 4 vertices");
	}

	template<typename InIt>
	//requires (std::is_base_of_v<std::input_iterator_tag, InIt>)
	Rectangle(InIt it_begin):
		Shape(4, it_begin) {}

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

	nlohmann::json makeJson() override {
		nlohmann::json json;
		json["type"] = "Rectangle";
		//json["name"] = name;
		json["square"] = square();
		for (Vertex& vtx : *this) {
			json["vertices"].push_back({ { "x", vtx.get_x() }, { "y", vtx.get_y() } });
		}

		return json;
	}

public:
	// iostream operators
	void showInfo(std::ostream& os = std::cout) override {
		os << "RECTANGLE" << name << std::endl << "Vertices:" << std::endl;
		os << "Square: " << square() << std::endl;
		for (Vertex& vtx : *this)
			os << "\x1b[4G" << vtx << std::endl;
	}
};