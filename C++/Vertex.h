#pragma once
#include <iostream>
#include <functional>
#include <stdexcept>

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
		x_(std::move(other.x_)),
		y_(std::move(other.y_))
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
	Vertex operator+(_Vertex_t scalar);
	Vertex operator-(_Vertex_t scalar);
	Vertex operator*(_Vertex_t scalar);
	Vertex operator/(_Vertex_t scalar);

	// object modification
	void operator+=(_Vertex_t scalar) { x_ += y_ += scalar; }
	void operator-=(_Vertex_t scalar) { x_ -= y_ -= scalar; }
	void operator*=(_Vertex_t scalar) { x_ *= y_ *= scalar; }
	void operator/=(_Vertex_t scalar) {
		if (scalar == 0.0)
			throw std::invalid_argument("Vertex division by zero");
		x_ /= y_ /= scalar;
	}

	void operator=(_Vertex_t value) { x_ = y_ = value; }
	Vertex& operator=(const Vertex& other) { this->x_ = other.x_; this->y_ = other.y_; return *this; }


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
		os << "x = " << vtx.x_ << std::endl
			<< "y = " << vtx.y_ << std::endl;
		return os;
	}
};