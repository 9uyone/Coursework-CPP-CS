#include "Shape.h"

void Shape::move(_Vertex_t deltaX, _Vertex_t deltaY) {
	for (auto& vtx : *this) {
		vtx += {deltaX, deltaY};
	}
}

Vertex& Shape::operator[](size_t index) {
	return vertices.at(index);
}

std::ostream& operator<<(std::ostream& os, Shape& shp) {
	shp.showInfo(os);
	return os;
}

// iterator
Shape::iterator Shape::begin() {
	return iterator(vertices.begin()._Ptr);
}

Shape::iterator Shape::end() {
	return iterator(vertices.end()._Ptr);
}
