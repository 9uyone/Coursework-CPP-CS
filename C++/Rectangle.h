#pragma once
#include "Shape.h"
class Rectangle : public Shape<4> {
public:
	Rectangle() {}
	virtual ~Rectangle() {}

public:
	void move(_Vertex_t deltaX, _Vertex_t deltaY) {
		
	}
};