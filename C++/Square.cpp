#include "Square.h"

Square::Square(Vertex vtx, _Vertex_t side) :
	Shape({ { vtx.get_x(), vtx.get_y() },
		  { vtx.get_x(), vtx.get_y() + side },
		  { vtx.get_x() + side, vtx.get_y() + side },
		  { vtx.get_x() + side, vtx.get_y() } })
{
		if (side <= 0)
			throw std::invalid_argument("Side length should be > 0");
		vtx_ = vtx;
		side_ = side;
}

double Square::square() {
	return std::pow(std::fabs((vertices[1] - vertices[0]).get_y()), 2);
}

nlohmann::json Square::makeJson() {
	nlohmann::json json;
	json["type"] = "Square";
	//json["name"] = name;
	json["left_bottom_vertex"] = { {"x", vtx_.get_x()}, {"y", vtx_.get_y()} };
	json["side"] = side_;
	json["square"] = square();
	json["vertices"] = nlohmann::json::array();
	for (Vertex& vtx : *this) {
		json["vertices"].push_back({ { "x", vtx.get_x() }, { "y", vtx.get_y() } });
	}

	return json;
}

void Square::showInfo(std::ostream& os) {
	os << "SQUARE " << name << std::endl <<
		"Square: " << this->square() << std::endl <<
		"Left bottom vertex: " << vtx_ << std::endl <<
		"Side length: " << side_ << std::endl <<
		"Vertices:" << std::endl;
	for (Vertex& vtx : *this)
		os << "\x1b[4G" << vtx << std::endl;
}

//inline void Square::checkSquare() {
//	if ((*this)[1] - (*this)[0] != (*this)[2] - (*this)[3])
//		throw std::invalid_argument("The given points don't form a square");
//}