#include "Vertex.h"

std::istream& operator>>(std::istream& is, Vertex& vtx) {
	_Vertex_t value;

	for (uint8_t i(0); i < 2; ++i) {
		while (true) {
			if (is.eof())
				throw std::out_of_range("Vertex input end of stream");

			while (is.peek() == ' ' or is.peek() == '\n') is.ignore();
			is >> value;
			if (is.fail()) {
				is.clear();
				is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cerr << "Input error!\n";
			}
			else break;
		}
		(i == 0 ? vtx.set_x(value) : vtx.set_y(value));
	}
	return is;
}

// math ops
//Vertex Vertex::operator+(_Vertex_t scalar) {
//	return Vertex(x_ + scalar, y_ + scalar);
//}
//
//Vertex Vertex::operator-(_Vertex_t scalar) {
//	return Vertex(x_ - scalar, y_ - scalar);
//}
//
//Vertex Vertex::operator*(_Vertex_t scalar) {
//	return Vertex(x_ * scalar, y_ * scalar);
//}
//
//Vertex Vertex::operator/(_Vertex_t scalar) {
//	if (scalar == 0.0)
//		throw std::invalid_argument("Vertex division by zero");
//	return Vertex(x_ / scalar, y_ / scalar);
//}

