#pragma once
#include "Vertex.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <iterator>
#include <nlohmann/json.hpp>
#include <algorithm>

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
		vertices(it_begin, it_begin + vertex_count) { checkShape(); }

	Shape(std::string name, std::initializer_list<Vertex> ilist) :
		name(name),
		vertices(ilist) { checkShape(); }

	template<typename Verts_vec>
	requires(std::is_same_v<std::remove_reference_t<Verts_vec>, decltype(vertices)>)
	Shape(std::string name, Verts_vec&& v) :
		name(name),
		vertices(std::forward<Verts_vec>(v)) { checkShape(); }

	virtual ~Shape() {}

private:
	bool isClockwise();
	void checkShape();

public: // methods
	void move(_Vertex_t deltaX, _Vertex_t deltaY);

	virtual double square() = 0;

	virtual void showInfo(std::ostream& os = std::cout) = 0;
	friend std::ostream& operator<< (std::ostream& os, Shape& shp);

	virtual nlohmann::json makeJson() = 0;

private: // iterator
	template<typename Val_type>
	struct base_iterator {
		using iterator_category = std::random_access_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = Val_type;
		using pointer = Val_type*;
		using reference = Val_type&;

		base_iterator(pointer ptr) : ptr(ptr) {}
		base_iterator(const base_iterator& other) : ptr(other.ptr) {}
		base_iterator operator=(const base_iterator& other) { ptr = other.ptr; }
		
		reference operator*() const {
			return *ptr;
		}
		pointer operator->() const {
			return ptr;
		}

		base_iterator& operator++() {
			++ptr; return *this;
		}
		base_iterator operator++(int) {
			base_iterator tmp = *this; ++(*this); return tmp;
		}
		base_iterator& operator--() {
			--ptr; return *this;
		}
		base_iterator operator--(int) {
			iterator tmp = *this; --(*this); return tmp;
		}

		// Random access ops
		base_iterator& operator+=(difference_type n) {
			ptr += n;
			return *this;
		}
		base_iterator operator+(difference_type n) const {
			return iterator(ptr + n);
		}
		base_iterator& operator-=(difference_type n) {
			ptr -= n;
			return *this;
		}
		base_iterator operator-(difference_type n) const {
			return iterator(ptr - n);
		}

		difference_type operator-(const base_iterator& other) const {
			return ptr - other.ptr;
		}

		// comparison ops
		bool operator== (const base_iterator& other) {
			return ptr == other.ptr;
		};
		bool operator!= (const base_iterator& other) {
			return ptr != other.ptr;
		};

	protected:
		pointer ptr;
	};

protected:
	using iterator = base_iterator<Vertex>;
	iterator begin() const;
	iterator end() const;

public:
	using const_iterator = base_iterator<const Vertex>;
	const_iterator cbegin() const;
	const_iterator cend() const;
};