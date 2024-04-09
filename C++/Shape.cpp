#include "Shape.h"

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

// iterator
Shape::iterator Shape::begin() const {
	return iterator(vertices.begin()._Ptr);
}

Shape::iterator Shape::end() const{
	return iterator(vertices.end()._Ptr);
}

Shape::const_iterator Shape::cbegin() const {
	return const_iterator(vertices.begin()._Ptr);
}

Shape::const_iterator Shape::cend() const {
	return const_iterator(vertices.end()._Ptr);
}
