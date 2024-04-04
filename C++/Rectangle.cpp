#include "Rectangle.h"

Rectangle::Rectangle(std::string name, Vertex vtx, _Vertex_t s1, _Vertex_t s2) :
	Shape(name, { vtx,
		  {vtx.get_x(), vtx.get_y() + s1},
		  {vtx.get_x() + s2, vtx.get_y() + s1},
		  {vtx.get_x() + s2, vtx.get_y()}
		  }),
	vtx_(vtx),
	side_1_(s1),
	side_2_(s2)
{
	if (s1 <= 0 or s2 <= 0)
		throw std::invalid_argument("Side lengths must be > 0");
}

Rectangle::Rectangle(Rectangle& other) :
	vtx_(other.vtx_),
	side_1_(other.side_1_),
	side_2_(other.side_2_),
	Shape(other.name, other.vertices) {}

Rectangle::Rectangle(Rectangle&& other) noexcept :
	vtx_(std::move(other.vtx_)),
	side_1_(std::exchange(other.side_1_, 0)),
	side_2_(std::exchange(other.side_2_, 0)),
	Shape(std::move(other.name), std::move(other.vertices)) {}


double Rectangle::square() {
	//return std::fabs((vertices[2] - vertices[0]).get_x()) *
		//std::fabs((vertices[2] - vertices[0]).get_y());
	return side_1_ * side_2_;
}

nlohmann::json Rectangle::makeJson() {
	nlohmann::json json;
	json["type"] = "Rectangle";
	json["name"] = name;
	json["left_bottom_vertex"] = { {"x", vtx_.get_x()}, {"y", vtx_.get_y()} };
	json["side_1"] = side_1_;
	json["side_2"] = side_2_;
	json["square"] = square();
	for (auto& vtx : *this) {
		json["vertices"].push_back({ { "x", vtx.get_x() }, { "y", vtx.get_y() } });
	}

	return json;
}

void Rectangle::showInfo(std::ostream& os) {
	os << "RECTANGLE " << name << std::endl <<
		"Square: " << square() << std::endl <<
		"Left bottom vertex: " << vtx_ << std::endl <<
		"Side 1 length: " << side_1_ << std::endl <<
		"Side 2 length: " << side_2_ << std::endl <<
		"Vertices:" << std::endl;
	for (auto& vtx : *this)
		os << "\x1b[4G" << vtx << std::endl;
}

//inline void Rectangle::checkRectangle() {
//	if (((*this)[2] - (*this)[0]).abs() != ((*this)[3] - (*this)[1]).abs())
//		throw std::invalid_argument("The given points don't form a rectangle");
//}