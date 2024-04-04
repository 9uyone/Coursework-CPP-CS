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
		x_(x), y_(y) {}

	Vertex(const Vertex& other) :
		x_(other.x_), y_(other.y_) {}

	Vertex(Vertex&& other) noexcept :
		x_(std::exchange(other.x_, 0)),
		y_(std::exchange(other.y_, 0)) {}
	
	virtual ~Vertex() {}

public: // getters & setters
	const _Vertex_t& get_x() const { return x_; }
	const _Vertex_t& get_y() const { return y_; }

	void set_x(_Vertex_t value) { x_ = value; }
	void set_y(_Vertex_t value) { y_ = value; }

public: // assignment ops
	Vertex& operator=(_Vertex_t value);
	Vertex& operator=(const Vertex& other);
	Vertex& operator=(Vertex&& other) noexcept;

public: // comparison ops
	bool operator==(Vertex other);
	bool operator!=(Vertex other);
	bool operator<(Vertex other);

public: // arithmetic ops
	Vertex operator+(Vertex other) const;
	Vertex operator-(Vertex other) const;
	Vertex operator*(Vertex other) const;
	Vertex operator/(Vertex other) const;

	// with assignment
	Vertex& operator+=(Vertex other);
	Vertex& operator-=(Vertex other);
	Vertex& operator*=(Vertex other);
	Vertex& operator/=(Vertex other);

	Vertex abs();
	Vertex operator~() const;

public:
	// iostream ops
	friend std::istream& operator>>(std::istream& is, Vertex& vtx);
	friend std::ostream& operator<<(std::ostream& os, const Vertex& vtx);
};