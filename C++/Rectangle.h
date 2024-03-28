#pragma once
#include "Shape.h"

class Rectangle : public Shape {
private:
	Vertex vtx_;
	_Vertex_t side_1_, side_2_;

public: // ctors & dtor

	//template<typename Vtx1, Vtx2>
	/*Rectangle(Vertex v1, Vertex v2) :
		Shape({v1,
			  {v1.get_x(), v2.get_y()},
			  v2,
			  {v2.get_x(), v1.get_y()}
			  }) {}

	(std::initializer_list<Vertex> ilist) : Shape(ilist) {
		if (ilist.size() != 4)
			throw std::invalid_argument("Square requires 4 vertices");
	}

	template<typename InIt>
	Rectangle(InIt it_begin): Shape(4, it_begin) {
		checkRectangle();
	}*/

	Rectangle(Vertex vtx, _Vertex_t s1, _Vertex_t s2);

	virtual ~Rectangle() {}

public:
	double square() override;

	nlohmann::json makeJson() override;

public:
	void showInfo(std::ostream& os = std::cout) override;

private:
	//inline void checkRectangle();
};