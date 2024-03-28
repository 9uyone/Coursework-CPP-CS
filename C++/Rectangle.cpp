#include "Rectangle.h"

Rectangle::Rectangle(Vertex vtx, _Vertex_t s1, _Vertex_t s2) :
	Shape({ vtx,
		  {vtx.get_x(), vtx.get_y() + s1},
		  {vtx.get_x() + s2, vtx.get_y() + s1},
		  {vtx.get_x() + s2, vtx.get_y()}
		  }),
	vtx_(vtx),
	side_1_(s1),
	side_2_(s2) {}

double Rectangle::square() {
	return std::fabs((vertices[2] - vertices[0]).get_x()) *
		std::fabs((vertices[2] - vertices[0]).get_y());
}

nlohmann::json Rectangle::makeJson() {
	nlohmann::json json;
	json["type"] = "Rectangle";
	//json["name"] = name;
	json["left_bottom_vertex"] = { {"x", vtx_.get_x()}, {"y", vtx_.get_y()} };
	json["side_1"] = side_1_;
	json["side_2"] = side_2_;
	json["square"] = square();
	for (Vertex& vtx : *this) {
		json["vertices"].push_back({ { "x", vtx.get_x() }, { "y", vtx.get_y() } });
	}

	return json;
}

void Rectangle::showInfo(std::ostream& os) {
	os << "RECTANGLE" << name << std::endl <<
		"Square: " << square() << std::endl <<
		"Left bottom vertex: " << vtx_ <<
		"Side 1 length: " << side_1_ <<
		"Side 2 length: " << side_2_ <<
		"Vertices:" << std::endl;
	for (Vertex& vtx : *this)
		os << "\x1b[4G" << vtx << std::endl;
}

//inline void Rectangle::checkRectangle() {
//	if (((*this)[2] - (*this)[0]).abs() != ((*this)[3] - (*this)[1]).abs())
//		throw std::invalid_argument("The given points don't form a rectangle");
//}