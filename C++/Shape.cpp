#include "Shape.h"

void Shape::move(_Vertex_t deltaX, _Vertex_t deltaY) {
	//for (auto& vtx : *this)
	for (auto& vtx: vertices)
		vtx += {deltaX, deltaY};
}

Vertex& Shape::operator[](size_t index) {
	return vertices.at(index);
}

std::ostream& operator<<(std::ostream& os, Shape& shp) {
	shp.showInfo(os);
	return os;
}

// iterator
Shape::const_iterator Shape::begin() const {
	return const_iterator(vertices.begin()._Ptr);
}

Shape::const_iterator Shape::end() const{
	return const_iterator(vertices.end()._Ptr);
}
