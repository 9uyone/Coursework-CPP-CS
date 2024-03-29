#pragma once
#include "Vertex.h"
#include <vector>
#include <stdexcept>
#include <iterator>
#include <nlohmann/json.hpp>

class Shape {
protected:
	std::vector<Vertex> vertices{};
	Vertex& operator[](size_t index);

public:
	std::string name;

public: // vertices init ctors
	template<typename InIt>
	Shape(size_t vertex_count, InIt it_begin) :
		vertices(it_begin, it_begin + vertex_count) {}

	Shape(std::initializer_list<Vertex> ilist) :
		vertices(ilist) {}

	template<typename Verts_vec>
	Shape(Verts_vec&& v) : vertices(std::forward<Verts_vec>(v)) {}

	void move(_Vertex_t deltaX, _Vertex_t deltaY);

	virtual double square() = 0;

	virtual void showInfo(std::ostream& os = std::cout) = 0;
	friend std::ostream& operator<< (std::ostream& os, Shape& shp);

	virtual nlohmann::json makeJson() = 0;

public: // iterator
	struct iterator {
		using iterator_category = std::random_access_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = Vertex;
		using pointer = Vertex*;
		using reference = Vertex&;

		iterator(pointer ptr) : m_ptr(ptr) {}
		iterator(iterator& other) : m_ptr(other.m_ptr) {}
		iterator(iterator&& other) noexcept : m_ptr(std::move(other.m_ptr)) {}

		reference operator*() const {
			return *m_ptr;
		}
		pointer operator->() {
			return m_ptr;
		}
		iterator& operator++() {
			m_ptr++; return *this;
		}
		iterator operator++(int) {
			iterator tmp = *this; ++(*this); return tmp;
		}
		friend bool operator== (const iterator& a, const iterator& b) {
			return a.m_ptr == b.m_ptr;
		};
		friend bool operator!= (const iterator& a, const iterator& b) {
			return a.m_ptr != b.m_ptr;
		};

	private:
		pointer m_ptr;
	};

	iterator begin();
	iterator end();

public:
	virtual ~Shape() {}
};