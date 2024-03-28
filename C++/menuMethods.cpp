#pragma once
#include "menuMethods.h"

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
		Vertex vtx;
		std::cout << "Enter left bottom vertex (x & y): ";
		std::cin >> vtx;
		std::cout << "Enter 1st side: ";
		_Vertex_t side_1 = cin_aux::getUnsigned();
		std::cout << "Enter 2nd side: ";
		_Vertex_t side_2 = cin_aux::getUnsigned();
		
		Rectangle obj(vtx, side_1, side_2);
		return std::make_shared<Rectangle>(std::move(obj));
	}

	std::shared_ptr<Shape> addSquare() {
		Vertex vtx;
		std::cout << "Enter left bottom vertex (x & y): ";
		std::cin >> vtx;
		std::cout << "Enter side: ";
		_Vertex_t side = cin_aux::getUnsigned();

		Square obj(vtx, side);
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
		nlohmann::json json = nlohmann::json::parse(file);
		file.close();
		if (json.empty() or !file)
			throw std::exception(std::format("Cannot open {} for reading", name).c_str());
		 
		cont.reserve(1.5 * json["count"].get<size_t>());
		for (auto it = json["shapes"].cbegin(); it != json["shapes"].cend(); ++it) {
			auto& j_v = (*it)["vertices"];
			//std::vector<Vertex> verts;
			//std::for_each(j_v.cbegin(), j_v.cend(),
				//[&verts](auto& el) { verts.emplace_back(el["x"].get<_Vertex_t>(), el["y"].get<_Vertex_t>()); });

			if ((*it)["type"] == "Rectangle") {
				Vertex vtx{ (*it)["left_bottom_vertex"]["x"].get<_Vertex_t>(), (*it)["left_bottom_vertex"]["y"].get<_Vertex_t>() };
				_Vertex_t s1 = (*it)["side_1"].get<_Vertex_t>();
				_Vertex_t s2 = (*it)["side_2"].get<_Vertex_t>();
				cont.push_back(std::make_shared<Rectangle>(Rectangle(vtx, s1, s2)));
			} else if ((*it)["type"] == "Square") {
				Vertex vtx{ (*it)["left_bottom_vertex"]["x"].get<_Vertex_t>(), (*it)["left_bottom_vertex"]["y"].get<_Vertex_t>() };
				_Vertex_t side = (*it)["side"].get<_Vertex_t>();
				cont.push_back(std::make_shared<Square>(Square(vtx, side)));
			}
		}
	}

	

}