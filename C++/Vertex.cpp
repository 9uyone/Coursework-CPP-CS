#include "Vertex.h"

// assignment operators
Vertex& Vertex::operator=(_Vertex_t value) {
	x_ = y_ = value;
	return *this;
}
Vertex& Vertex::operator=(const Vertex& other) {
	this->x_ = other.x_;
	this->y_ = other.y_;
	return *this;
}
Vertex& Vertex::operator=(Vertex&& other) noexcept {
	this->x_ = other.x_;
	this->y_ = other.y_;
	return *this;
}

// comparison operators
bool Vertex::operator==(Vertex other) {
	return this->x_ == other.x_ && this->y_ == other.y_;
}
bool Vertex::operator!=(Vertex other) {
	return !(*this == other);
}
bool Vertex::operator<(Vertex other) {
	return sqrt(pow(this->x_, 2) + pow(this->y_, 2)) <
		sqrt(pow(other.x_, 2) + pow(other.y_, 2));
}

// arithmetic ops
Vertex Vertex::operator+(Vertex other) const{
	return { x_ + other.x_, y_ + other.y_ };
}
Vertex Vertex::operator-(Vertex other) const {
	return { x_ - other.x_, y_ - other.y_ };
}
Vertex Vertex::operator*(Vertex other) const {
	return { x_ * other.x_, y_ * other.y_ };
}
Vertex Vertex::operator/(Vertex other) const {
	if (std::fpclassify((double)other.x_) == FP_ZERO
		or std::fpclassify((double)other.y_) == FP_ZERO)
		throw std::exception("Division by zero");
	return { x_ / other.x_, y_ / other.y_ };
}

// with assignment
Vertex& Vertex::operator+=(Vertex other) {
	x_ += other.x_;
	y_ += other.y_;
	return *this;
}
Vertex& Vertex::operator-=(Vertex other) {
	x_ -= other.x_;
	y_ -= other.y_;
	return *this;
}
Vertex& Vertex::operator*=(Vertex other) {
	x_ *= other.x_;
	y_ *= other.y_;
	return *this;
}
Vertex& Vertex::operator/=(Vertex other) {
	x_ /= other.x_;
	y_ /= other.y_;
	return *this;
}

Vertex Vertex::abs() {
	return {
		static_cast<_Vertex_t>(std::fabs(x_)),
		static_cast<_Vertex_t>(std::fabs(y_))
	};
}

Vertex Vertex::operator~() const {
	return { this->y_, this->x_ };
}


// input operator >>
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
				std::cerr << "\x1b[31m" << "Input error\n" << "\x1b[0m";
			} else break;
		}
		(i == 0 ? vtx.set_x(value) : vtx.set_y(value));
	}
	return is;
}

// output operator <<
std::ostream& operator<<(std::ostream& os, Vertex vtx) {
	os << '(' << vtx.x_ << "; " << vtx.y_ << ')';
	return os;
}