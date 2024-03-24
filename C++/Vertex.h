#pragma once
#include <iostream>
#include <functional>
#include <stdexcept>
#include <math.h>

using _Vertex_t = int;

class Vertex {
private:
	_Vertex_t x_, y_;

public: // ctors & dtor
	Vertex(_Vertex_t x = 0, _Vertex_t y = 0) :
		x_(x), y_(y) {
		//std::cout << "Default ctor\n";
	}

	Vertex(const Vertex& other) :
		x_(other.x_), y_(other.y_) {
		//std::cout << "Copy ctor\n";
	}

	Vertex(Vertex&& other) noexcept :
		x_(std::exchange(other.x_, 0)),
		y_(std::exchange(other.y_, 0))
	{
		other.x_ = other.y_ = 0;
		//std::cout << "Move ctor\n";
	}
	
	virtual ~Vertex() {}

public: // getters & setters
	const _Vertex_t& get_x() const { return x_; }
	const _Vertex_t& get_y() const { return y_; }

	void set_x(_Vertex_t value) { x_ = value; }
	template<typename T> void set_x(T&& vtx) { this->x_ = vtx.x_; }

	void set_y(_Vertex_t value) { y_ = value; }
	template<typename T> void set_y(T&& vtx) { this->y_ = vtx.x_; }

public: // math ops

	//// object modification
	//void operator+=(_Vertex_t scalar) { x_ += y_ += scalar; }
	//void operator-=(_Vertex_t scalar) { x_ -= y_ -= scalar; }
	//void operator*=(_Vertex_t scalar) { x_ *= y_ *= scalar; }
	//void operator/=(_Vertex_t scalar) {
	//	if (scalar == 0.0)
	//		throw std::invalid_argument("Vertex division by zero");
	//	x_ /= y_ /= scalar;
	//}

	Vertex&& operator+(Vertex delta) { return Vertex(x_ + delta.x_, y_ + delta.y_); }
	Vertex&& operator-(Vertex delta) { return Vertex(x_ - delta.x_, y_ - delta.y_); }
	Vertex&& operator*(Vertex delta) { return Vertex(x_ * delta.x_, y_ * delta.y_); }
	Vertex&& operator/(Vertex delta) {
		if (std::fpclassify((double)delta.x_) == FP_ZERO
			or std::fpclassify((double)delta.y_) == FP_ZERO)
			throw std::exception("Division by zero");
		return Vertex(x_ / delta.x_, y_ / delta.y_);
	}

	//Vertex& operator+=(_Vertex_t scalar) { x_ + delta.x_, y_ + delta.y_; }
	//Vertex& operator-=(_Vertex_t scalar) { x_ - delta.x_, y_ - delta.y_; }
	//Vertex& operator*=(_Vertex_t scalar) { x_ * delta.x_, y_ * delta.y_; }
	//Vertex& operator/=(_Vertex_t scalar) {
	//	if (std::fpclassify((double)delta.x_) == FP_ZERO
	//		or std::fpclassify((double)delta.y_) == FP_ZERO)
	//		throw std::exception("Division by zero");
	//	return Vertex(x_ / delta.x_, y / delta.y_);
	//}

	Vertex& operator+=(Vertex delta) { x_ += delta.x_, y_ += delta.y_; return *this; }
	Vertex& operator-=(Vertex delta) { x_ -= delta.x_, y_ -= delta.y_; return *this; }
	Vertex& operator*=(Vertex delta) { x_ *= delta.x_, y_ *= delta.y_; return *this; }
	Vertex& operator/=(Vertex delta) { x_ /= delta.x_, y_ /= delta.y_; return *this; }

	Vertex& operator=(_Vertex_t value) { x_ = y_ = value; return *this; }
	Vertex& operator=(const Vertex& other) { this->x_ = other.x_; this->y_ = other.y_; return *this; }
	Vertex& operator=(Vertex&& other) noexcept { this->x_ = other.x_; this->y_ = other.y_; return *this; }

	
public: // logical operators
	bool operator==(Vertex other) { return (this->x_ == other.x_) && (this->y_ == other.y_); }
	bool operator!=(Vertex other) { return !(*this == other); }

	Vertex operator~() const { return {this->y_, this->x_}; }

public:
	// input operator >>
	friend std::istream& operator>>(std::istream& is, Vertex& vtx);

	// output operator <<
	#if __cplusplus < 202002L
		template<typename T,
			typename = std::enable_if_t<std::is_same<std::remove_reference_t<T>, Vertex>::value>>
	#else
		template<typename T>
		requires (std::is_same_v<std::remove_reference_t<T>, Vertex>)
	#endif
	friend std::ostream& operator<<(std::ostream& os, T&& vtx) {
		os << '(' << vtx.x_ << "; " << vtx.y_ << ')';
		return os;
	}
};