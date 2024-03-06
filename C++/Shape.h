#pragma once
#include "Vertex.h"
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>

class Shape {
private:
	size_t vertex_count_;

protected:
	std::vector<Vertex> vertices{};

public:
	template<typename InIt = std::istream_iterator<Vertex>>
	Shape(size_t vertex_count, InIt it_begin = InIt(std::cin)) {
		if (vertex_count < 2)
			throw std::domain_error("Count of vertex must be >= 2");
		
		this->vertex_count_ = vertex_count_;
		//vertices.resize(vertex_count);
		//std::copy_n(it_begin, vertex_count, vertices.begin());
		vertices.reserve(vertex_count);
		std::copy_n(it_begin, vertex_count, std::back_inserter(vertices));
	}
	Shape() {}

	//virtual void move(_Vertex_t deltaX, _Vertex_t deltaY) = 0;

	// додати видалити вершину
	//template<typename T> void add_vertex(T&& vx) { vertices.push_back(vx); }
	template<typename T> void add_vertex(T&& vx) { vertices.push_back(std::forward<T>(vx)); }

protected:
	std::vector<Vertex>::iterator begin() { return vertices.begin(); }
	std::vector<Vertex>::iterator end() { return vertices.end(); }

public:
	virtual ~Shape() {}
};