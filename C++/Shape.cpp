#include "Shape.h"

bool Shape::isClockwise() {
	long double sum = 0;
	for (int i = 0; i < vertices.size(); ++i) {
		auto& cur = vertices[i];
		auto& next = vertices[(i + 1) % vertices.size()];
		sum += ((next.get_x() - cur.get_x()) * (next.get_y() + cur.get_y()));
	}
	return sum > 0;
}

void Shape::checkShape() {
	if (!isClockwise())
		throw std::invalid_argument(std::format("{}: The sequence of vertices is not clockwise", name));
}

void Shape::move(_Vertex_t deltaX, _Vertex_t deltaY) {
	//for (Vertex& vtx: vertices)
	for (Vertex& vtx : *this)
		vtx += {deltaX, deltaY};
}

Vertex& Shape::operator[](size_t index) {
	return vertices.at(index);
}

std::ostream& operator<<(std::ostream& os, Shape& shp) {
	shp.showInfo(os);
	return os;
}

std::vector<Vertex>::iterator Shape::begin() {
	return vertices.begin();
}
std::vector<Vertex>::iterator Shape::end() {
	return vertices.end();
}

std::vector<Vertex>::const_iterator Shape::cbegin() {
	return vertices.cbegin();
}
std::vector<Vertex>::const_iterator Shape::cend() {
	return vertices.cend();
}