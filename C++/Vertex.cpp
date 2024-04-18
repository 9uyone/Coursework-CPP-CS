#include "Vertex.h"

// assignment ops
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
	this->x_ = std::exchange(other.x_, 0);
	this->y_ = std::exchange(other.y_, 0);
	return *this;
}

// comparison ops
bool Vertex::operator==(const Vertex& other) {
	return this->x_ == other.x_ && this->y_ == other.y_;
}
bool Vertex::operator!=(const Vertex& other) {
	return !(*this == other);
}

bool Vertex::operator<(const Vertex& other) {
	//return this->hypot() < other.hypot();
	return x_ < other.x_ || x_ == other.x_ && y_ < other.y_;
}
bool Vertex::operator>(const Vertex& other) {
	return x_ > other.x_ || x_ == other.x_ && y_ > other.y_;
}
bool Vertex::operator<=(const Vertex& other) {
	return *this < other || *this == other;
}
bool Vertex::operator>=(const Vertex& other) {
	return *this > other || *this == other;
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

// additional ops
Vertex Vertex::abs() const {
	return {
		static_cast<_Vertex_t>(std::fabs(x_)),
		static_cast<_Vertex_t>(std::fabs(y_))
	};
}

_Vertex_t Vertex::hypot() const {
	return std::hypot(x_, y_);
}

// input op >>
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

// output op <<
std::ostream& operator<<(std::ostream& os, const Vertex& vtx) {
	os << '(' << vtx.x_ << "; " << vtx.y_ << ')';
	return os;
}