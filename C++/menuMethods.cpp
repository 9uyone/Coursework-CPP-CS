#pragma once
#include "menuMethods.h"

#define CSI "\x1b["

namespace menuMethods {
	namespace cin_aux {
		_Vertex_t getUnsigned() {
			_Vertex_t n;
			while (1) {
				std::cin >> n;
				if (!std::cin.good() or n <= 0) {
					std::cin.clear();
					std::cerr << CSI"31m" << CSI"K" << "The value should be > 0\n" << CSI"0m";
				} else return n;
			}
		}

		std::string getName() {
			std::string name;
			while (1) {
				std::cin >> name;
				if (!std::cin.good() or !std::regex_match(name, std::regex("^[a-zA-Z]\\w*$"))) {
					std::cin.clear();
					std::cerr << CSI"31m" << CSI"K" << "The name must start with a letter and contain alphanumeric symbols\n" << CSI"0m";
				} else return name;
			}
		}
	}
	
	std::shared_ptr<Shape> addRectangle() {
		Vertex v1, v2;
		std::cout << "Enter 1st point: ";
		std::cin >> v1;
		std::cout << "Enter 2nd point: ";
		std::cin >> v2;

		Rectangle obj(v1, v2);
		return std::make_shared<Rectangle>(std::move(obj));
	}

	std::shared_ptr<Shape> addSquare() {
		Vertex bl_vtx;
		std::cout << "Enter left bottom point: ";
		std::cin >> bl_vtx;
		std::cout << "Enter side: ";
		_Vertex_t side = cin_aux::getUnsigned();

		Square obj(bl_vtx, side);
		return std::make_shared<Square>(std::move(obj));
	}

	void printShapes(_Menu_shape_cont& cont) {
		for (auto& obj : cont)
			std::cout << *obj << std::endl;
	}

	void saveToTxt(_Menu_shape_cont& cont) {
		if (cont.empty()) {
			std::cout << "Nothing to save\n";
			return;
		}
		
		std::cout << "Enter file name (without .txt)\n";
		std::string name = cin_aux::getName() + ".txt";
		std::ofstream file(name);
		if (!file)
			throw std::exception(std::format("Cannot open {} for writing", name).c_str());
		
		for (auto& obj : cont)
			file << *obj << std::endl;
		file.close();
	}

	void saveToJson(_Menu_shape_cont& cont) {
		if (cont.empty()) {
			std::cout << "Nothing to save\n";
			return;
		}
		
		std::cout << "Enter file name (without .json)\n";
		std::string name = cin_aux::getName() + ".json";
		std::ofstream file(name);
		if (!file)
			throw std::exception(std::format("Cannot open {} for writing", name).c_str());

		nlohmann::json json;
		json["count"] = cont.size();
		for (auto& obj : cont) {
			json["shapes"].push_back(std::move(obj->makeJson()));
		}
		file << json.dump(4) << std::endl;
		file.close();
	}

	void fromJson(_Menu_shape_cont& cont) {
		std::cout << "Enter file name (without .json)\n";
		std::string name = cin_aux::getName() + ".json";
		std::ifstream file(name);
		if (!file)
			throw std::exception(std::format("Cannot open {} for reading", name).c_str());

		nlohmann::json json;
		json.parse(file);
		file.close();

		cont.reserve(1.5 * json["count"].get<size_t>());
		for (auto it = json["shapes"].cbegin(); it != json["shapes"].cend(); ++it) {
			std::string type = (*it)["type"];

			auto& j_v = (*it)["vertices"];
			std::vector<Vertex> verts;
			std::for_each(j_v.cbegin(), j_v.cend(),
				[&verts, &j_v](auto el) { verts.emplace_back(el["x"].get<_Vertex_t>(), el["y"].get<_Vertex_t>()); });

			if (type == "Rectangle") {
				cont.push_back(std::make_shared<Rectangle>(Rectangle(verts.begin())));
			} else if (type == "Square") {
				cont.push_back(std::make_shared<Square>(Square(verts.begin())));
			}
		}
	}

	void change_vtx(_Menu_shape_cont& cont) {
		cont[0]->operator[](2) = { 3, -2 };
	}

	void w() { std::cout << "ww\n"; }
	void d() { std::cout << "ddd\n"; }
}