#include "Rectangle.h"

Rectangle::Rectangle(std::string name, std::initializer_list<Vertex> ilist) : Shape(name, ilist) {
	if (ilist.size() != 4)
		throw std::invalid_argument("Square requires 4 vertices");
	checkAndSet();
}

Rectangle::Rectangle(std::string name, Vertex lb_vtx, _Vertex_t sW, _Vertex_t sH) :
	Shape(name, { lb_vtx,
		  {lb_vtx.get_x(), lb_vtx.get_y() + sH},
		  {lb_vtx.get_x() + sW, lb_vtx.get_y() + sH},
		  {lb_vtx.get_x() + sW, lb_vtx.get_y()}
		  }),
	side_w(sW),
	side_h(sH)
{
	if (sW <= 0 or sH <= 0)
		throw std::invalid_argument("Side lengths must be > 0");
}

void Rectangle::checkAndSet() {
	if (((*this)[2] - (*this)[0]).abs() != ((*this)[3] - (*this)[1]).abs())
		throw std::invalid_argument("{}: The given points don't form a rectangle");

	side_h = ((*this)[1] - (*this)[0]).hypot();
	side_w = ((*this)[2] - (*this)[1]).hypot();
}

_Vertex_t Rectangle::get_side_w() const {
	return side_w;
}

_Vertex_t Rectangle::get_side_h() const {
	return side_h;
}

Rectangle::Rectangle(Rectangle& other) :
	Shape(other.name, other.vertices),
	side_h(other.side_h),
	side_w(other.side_w) {}

Rectangle::Rectangle(Rectangle&& other) noexcept :
	Shape(std::move(other.name), std::move(other.vertices)),
	side_h(std::exchange(other.side_h, 0)),
	side_w(std::exchange(other.side_w, 0)) {}

Rectangle& Rectangle::operator=(Rectangle& other) {
	name = other.name;
	vertices = other.vertices;
	side_h = other.side_h;
	side_w = other.side_w;

	return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
	name = std::move(other.name);
	vertices = std::move(other.vertices);
	side_h = std::exchange(other.side_h, 0);
	side_w = std::exchange(other.side_w, 0);
	return *this;
}

double Rectangle::square() {
	return side_h * side_w;
}

nlohmann::json Rectangle::makeJson() {
	nlohmann::json json;
	json["type"] = "Rectangle";
	json["name"] = name;
	for (auto& vtx : *this)
		json["vertices"].push_back({ { "x", vtx.get_x() }, { "y", vtx.get_y() } });

	return json;
}

void Rectangle::showInfo(std::ostream& os) {
	os << "Name: " << name << std::endl <<
		"Type: " << "Rectangle" << std::endl <<
		"Square: " << square() << std::endl <<
		"Vertices:" << std::endl;
	for (auto& vtx : *this)
		os << "  " << vtx << std::endl;
	os << "Side_w: " << side_w << std::endl <<
		"Side h: " << side_h << std::endl;
}
