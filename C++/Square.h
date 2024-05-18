#pragma once
#include "Shape.h"

class Square : public Shape {
private:
	_Vertex_t side;

public: // ctors & dtor
	// @brief by vertices list
	Square(std::string name, std::initializer_list<Vertex> ilist);

	// @brief copies vertices using iterator
	template<typename InIt>
	Square(std::string name, InIt it_begin) : Shape(name, 4, it_begin) {
		checkAndSet();
	}

	// @brief by left bottom point and side length
	Square(std::string name, Vertex lb_vtx, _Vertex_t side);

	Square(Square& other);
	Square(Square&& other) noexcept;

	Square& operator=(Square& other);
	Square& operator=(Square&& other) noexcept;

	virtual ~Square() {}

private:
	void checkAndSet();

//methods
public:
	_Vertex_t get_side();

	double square() override;
	nlohmann::json makeJson() override;
	void showInfo(std::ostream& os = std::cout) override;
};