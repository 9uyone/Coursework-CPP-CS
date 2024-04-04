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
	Shape(std::string name, size_t vertex_count, InIt it_begin) :
		name(name),
		vertices(it_begin, it_begin + vertex_count) {}

	Shape(std::string name, std::initializer_list<Vertex> ilist) :
		name(name),
		vertices(ilist) {}

	template<typename Verts_vec>
	Shape(std::string name, Verts_vec&& v) :
		name(name),
		vertices(std::forward<Verts_vec>(v)) {}

	virtual ~Shape() {}

public: // methods
	void move(_Vertex_t deltaX, _Vertex_t deltaY);

	virtual double square() = 0;

	virtual void showInfo(std::ostream& os = std::cout) = 0;
	friend std::ostream& operator<< (std::ostream& os, Shape& shp);

	virtual nlohmann::json makeJson() = 0;

public: // iterator
	struct const_iterator {
		using iterator_category = std::random_access_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = const Vertex;
		using pointer = const Vertex*;
		using reference = const Vertex&;

		const_iterator(pointer ptr) : ptr(ptr) {}
		const_iterator(const const_iterator& other) : ptr(other.ptr) {}
		const_iterator operator=(const const_iterator& other) { ptr = other.ptr; }
		
		reference operator*() const {
			return *ptr;
		}
		pointer operator->() const {
			return ptr;
		}

		const_iterator& operator++() {
			++ptr; return *this;
		}
		const_iterator operator++(int) {
			const_iterator tmp = *this; ++(*this); return tmp;
		}
		const_iterator& operator--() {
			--ptr; return *this;
		}
		const_iterator operator--(int) {
			const_iterator tmp = *this; --(*this); return tmp;
		}

		// Random access operators
		const_iterator& operator+=(difference_type n) {
			ptr += n;
			return *this;
		}
		const_iterator operator+(difference_type n) const {
			return const_iterator(ptr + n);
		}
		const_iterator& operator-=(difference_type n) {
			ptr -= n;
			return *this;
		}
		const_iterator operator-(difference_type n) const {
			return const_iterator(ptr - n);
		}

		difference_type operator-(const const_iterator& other) const {
			return ptr - other.ptr;
		}

		// comparison operators
		bool operator== (const const_iterator& other) {
			return ptr == other.ptr;
		};
		bool operator!= (const const_iterator& other) {
			return ptr != other.ptr;
		};

		bool operator<(const const_iterator& other) const {
			return ptr < other.ptr;
		}
		bool operator>(const const_iterator& other) const {
			return ptr > other.ptr;
		}
		bool operator<=(const const_iterator& other) const {
			return ptr <= other.ptr;
		}
		bool operator>=(const const_iterator& other) const {
			return ptr >= other.ptr;
		}

	private:
		pointer ptr;
	};

	const_iterator begin() const;
	const_iterator end() const;
};