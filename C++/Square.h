#pragma once
#include "Shape.h"

class Square : public Shape {
private:
	Vertex vtx_;
	_Vertex_t side_;

public: // ctors & dtor
	// @brief by vertices list
	/*Square(std::initializer_list<Vertex> ilist) : Shape(ilist) {
		if (ilist.size() != 4)
			throw std::invalid_argument("Square requires 4 vertices");
		checkSquare();
	}*/

	// @brief copies vertices using iterator
	/*template<typename InIt>
	Square(InIt it_begin) : Shape(4, it_begin) {
		checkSquare();
	}*/

	// @brief by left bottom point and side length
	Square(Vertex vtx, _Vertex_t side);

	virtual ~Square() {}

//methods
public:
	double square() override;

	nlohmann::json makeJson() override;

	void showInfo(std::ostream& os = std::cout) override;

private:
	//inline void checkSquare();
};