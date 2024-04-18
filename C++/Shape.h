#pragma once
#include "Vertex.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <iterator>
#include <nlohmann/json.hpp>
#include <algorithm>

using _Shape_vertices_cont = std::vector<Vertex>;

class Shape {
protected:
	_Shape_vertices_cont vertices{};
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

private: // begin & end
protected:
	_Shape_vertices_cont::iterator begin();
	_Shape_vertices_cont::iterator end();
public:
	_Shape_vertices_cont::const_iterator cbegin();
	_Shape_vertices_cont::const_iterator cend();
};