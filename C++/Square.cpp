#include "Square.h"

Square::Square(std::string name, std::initializer_list<Vertex> ilist) : Shape(name, ilist) {
	if (ilist.size() != 4)
		throw std::invalid_argument("Square requires 4 vertices");
	checkAndSet();
}

Square::Square(std::string name, Vertex lb_vtx, _Vertex_t side) :
	Shape(name, { lb_vtx,
		  { lb_vtx.get_x(), lb_vtx.get_y() + side },
		  { lb_vtx.get_x() + side, lb_vtx.get_y() + side },
		  { lb_vtx.get_x() + side, lb_vtx.get_y() } }),
	side(side) {
		if (side <= 0)
			throw std::invalid_argument("Side length must be > 0");
}

void Square::checkAndSet() {
	if ((*this)[1] - (*this)[0] != (*this)[2] - (*this)[3])
		throw std::invalid_argument(std::format("{}: The given points don't form a square", name));

	side = ((*this)[1] - (*this)[0]).hypot();
}

Square::Square(Square& other) :
	Shape(other.name, other.vertices),
	side(other.side) {}

Square::Square(Square&& other) noexcept :
	Shape(std::move(other.name), std::move(other.vertices)),
	side(std::exchange(other.side, 0)) {}

Square& Square::operator=(Square& other) {
	name = other.name;
	vertices = other.vertices;
	side = other.side;
	return *this;
}

Square& Square::operator=(Square&& other) noexcept {
	name = std::move(other.name);
	vertices = std::move(other.vertices);
	side = std::exchange(other.side, 0);
	return *this;
}

_Vertex_t Square::get_side() {
	return side;
}

double Square::square() {
	return pow(side, 2);
}

nlohmann::json Square::makeJson() {
	nlohmann::json json;
	json["type"] = "Square";
	json["name"] = name;
	for (auto& vtx : *this) {
		json["vertices"].push_back({ { "x", vtx.get_x() }, { "y", vtx.get_y() } });
	}

	return json;
}

void Square::showInfo(std::ostream& os) {
	os << "Name: " << name << std::endl <<
		"Type: " << "Square" << std::endl <<
		"Square: " << this->square() << std::endl <<
		"Vertices:" << std::endl;
	for (auto& vtx : *this)
		os << "  " << vtx << std::endl;
	os << "Side: " << side << std::endl;
}
