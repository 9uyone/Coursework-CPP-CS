#pragma once
#include "Shape.h"

class Rectangle : public Shape {
private:
	_Vertex_t side_1, side_2;

public: // ctors & dtor
	Rectangle(std::string name, std::initializer_list<Vertex> ilist);

	template<typename InIt>
	Rectangle(std::string name, InIt it_begin) : Shape(name, 4, it_begin) {
		checkAndSet();
	}

	Rectangle(std::string name, Vertex side_bottom_vtx, _Vertex_t s1, _Vertex_t s2);

	Rectangle(Rectangle& other);
	Rectangle(Rectangle&& other) noexcept;

	Rectangle& operator=(Rectangle& other);
	Rectangle& operator=(Rectangle&& other) noexcept;

	virtual ~Rectangle() {}

private:
	void checkAndSet();

	// overriden methods
public:
	double square() override;
	nlohmann::json makeJson() override;
	void showInfo(std::ostream& os = std::cout) override;
};