#pragma once
#include "Vertex.h"
#include <vector>
#include <stdexcept>
#include <iterator>
#include <nlohmann/json.hpp>

class Shape {
protected:
	std::vector<Vertex> vertices{};
public:
	std::string name;

// ctors
public:
	//Shape() = default;

	template<typename InIt = std::istream_iterator<Vertex>>
	Shape(size_t vertex_count, InIt it_begin = InIt(std::cin)) {
		if (vertex_count < 2)
			throw std::domain_error("Count of vertex must be >= 2");
		//vertices.resize(vertex_count);
		//std::copy_n(it_begin, vertex_count, vertices.begin());
		vertices.reserve(vertex_count);
		std::copy_n(it_begin, vertex_count, std::back_inserter(vertices));
	}
	
	Shape(std::initializer_list<Vertex> init) {
		vertices.reserve(init.size());
		vertices.assign(init);
	}

	virtual void move(_Vertex_t deltaX, _Vertex_t deltaY) = 0;
	virtual double square() = 0;

	// додати видалити вершину
	void add_vertex(_Vertex_t x, _Vertex_t y) { vertices.emplace_back(x, y); }
	template<typename T> void add_vertex(T&& vx) { vertices.push_back(std::forward<T>(vx)); }

	virtual void showInfo(std::ostream& os = std::cout) = 0;
	friend std::ostream& operator<< (std::ostream& os, Shape& shp) {
		shp.showInfo(os);
		return os;
	}

	//virtual void saveJson() = 0;

	Vertex& operator[](size_t index) { return vertices.at(index); }

public:
	struct iterator {
		using iterator_category = std::random_access_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = Vertex;
		using pointer = Vertex*;
		using reference = Vertex&;

		iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }
		iterator& operator++() { m_ptr++; return *this; }
		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
		friend bool operator== (const iterator& a, const iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const iterator& a, const iterator& b) { return a.m_ptr != b.m_ptr; };

	private:
		pointer m_ptr;
	};

	iterator begin() { return iterator(vertices.begin()._Ptr); }
	iterator end() { return iterator(vertices.end()._Ptr); }

public:
	virtual ~Shape() {}
};