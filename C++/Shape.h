#pragma once
#include "Vertex.h"
#include <vector>
#include <array>

#if __cplusplus < 202002L
template<uint8_t _Vertex_count, typename = std::enable_if_t<std::greater<>()(_Vertex_count, 0)>>
#else
template<uint8_t _Vertex_count>
requires (_Vertex_count > 0)
#endif
class Shape {
protected:
	std::vector<Vertex> vertices_ {_Vertex_count};

public:
	Shape() : vertices_{} {  }

	virtual void move(_Vertex_t deltaX, _Vertex_t deltaY) = 0;

	// додати видалити вершину
	template<typename T> void add_vertex(T&& vx) { vertices_.emplace_back(vx); }

protected:
	auto* begin() { return vertices_.begin(); }
	auto* end() { return vertices_.end(); }

public:
	virtual ~Shape() {}
};