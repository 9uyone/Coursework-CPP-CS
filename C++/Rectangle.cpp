#include "Rectangle.h"

Rectangle::Rectangle(std::string name, std::initializer_list<Vertex> ilist) : Shape(name, ilist) {
	if (ilist.size() != 4)
		throw std::invalid_argument("Square requires 4 vertices");
	checkAndSet();
}

Rectangle::Rectangle(std::string name, Vertex vtx, _Vertex_t s1, _Vertex_t s2) :
	Shape(name, { vtx,
		  {vtx.get_x(), vtx.get_y() + s1},
		  {vtx.get_x() + s2, vtx.get_y() + s1},
		  {vtx.get_x() + s2, vtx.get_y()}
		  }),
	side_1(s1),
	side_2(s2)
{
	if (s1 <= 0 or s2 <= 0)
		throw std::invalid_argument("Side lengths must be > 0");
}

void Rectangle::checkAndSet() {
	if (((*this)[2] - (*this)[0]).abs() != ((*this)[3] - (*this)[1]).abs() )/*
		|| (((*this)[0] < (*this)[3]) != ((*this)[1] < (*this)[2]))
		|| (((*this)[0] < (*this)[1]) != ((*this)[3] < (*this)[2]))
		)*/
		throw std::invalid_argument("{}: The given points don't form a rectangle");

	//if (!isClockwise())
		//throw std::invalid_argument(std::format("{}: Vertices are located neither clockwise nor counterclockwise", name));

	side_1 = ((*this)[1] - (*this)[0]).hypot();
	side_2 = ((*this)[2] - (*this)[1]).hypot();
}

Rectangle::Rectangle(Rectangle& other) :
	Shape(other.name, other.vertices),
	side_1(other.side_1),
	side_2(other.side_2) {}

Rectangle::Rectangle(Rectangle&& other) noexcept :
	Shape(std::move(other.name), std::move(other.vertices)),
	side_1(std::exchange(other.side_1, 0)),
	side_2(std::exchange(other.side_2, 0)) {}

Rectangle& Rectangle::operator=(Rectangle& other) {
	name = other.name;
	vertices = other.vertices;
	side_1 = other.side_1;
	side_2 = other.side_2;

	return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
	name = std::move(other.name);
	vertices = std::move(other.vertices);
	side_1 = std::exchange(other.side_1, 0);
	side_2 = std::exchange(other.side_2, 0);
	return *this;
}

double Rectangle::square() {
	//return std::fabs((vertices[2] - vertices[0]).get_x()) *
		//std::fabs((vertices[2] - vertices[0]).get_y());
	return side_1 * side_2;
}

nlohmann::json Rectangle::makeJson() {
	nlohmann::json json;
	json["type"] = "Rectangle";
	json["name"] = name;
	json["side_1"] = side_1;
	json["side_2"] = side_2;
	json["square"] = square();
	for (auto& vtx : *this)
		json["vertices"].push_back({ { "x", vtx.get_x() }, { "y", vtx.get_y() } });

	return json;
}

void Rectangle::showInfo(std::ostream& os) {
	os << "RECTANGLE " << name << std::endl <<
		"Square: " << square() << std::endl <<
		"Side 1 length: " << side_1 << std::endl <<
		"Side 2 length: " << side_2 << std::endl <<
		"Vertices:" << std::endl;
	for (auto& vtx : *this)
		os << "\x1b[4G" << vtx << std::endl;
}
