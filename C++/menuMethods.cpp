#pragma once
#include "menuMethods.h"

namespace menuMethods {
	namespace cin_aux {
		_Vertex_t getUnsigned(std::string prompt) {
			_Vertex_t n;
			while (1) {
				std::cout << prompt << ": ";
				std::cin >> n;
				if (std::cin.fail() or n <= 0) {
					std::cin.clear();
					Menu::_Print_error("Value should be > 0");
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				} else return n;
			}
		}

		std::string getName(std::string prompt) {
			std::string name;
			while (1) {
				std::cout << prompt << ": " << std::endl;
				std::cin >> name;
				if (std::cin.fail() or !std::regex_match(name, std::regex("^[a-zA-Z]\\w*$"))) {
					std::cin.clear();
					Menu::_Print_error("Name must start with a letter and contain alphanumeric symbols");
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				} else return name;
			}
		}
		int getIndex(_Menu_shape_cont& cont) {
			if (cont.empty()) {
				std::cout << "Shape list is empty\n";
				return -1;
			}
			int index;
			while (1) {
				std::cout << "Select name index: ";
				std::cin >> index;
				if (std::cin.fail() or !(index >= 1 && index <= cont.size())) {
					std::cin.clear();
					Menu::_Print_error("Incorrect index");
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				} else return index - 1;
			}
		}
	}

	void addRectangle(_Menu_shape_cont& cont) {
		std::string name;
		while (1) {
			name = cin_aux::getName("Enter name");
			if (std::find_if(cont.cbegin(), cont.cend(),
							 [&cont, &name](auto& el) { return el->name == name; }) != cont.cend())
				Menu::_Print_error("This name already exists");
			else break;
		}

		std::cout << "Enter left bottom vertex (x & y): ";
		Vertex vtx; std::cin >> vtx;
		_Vertex_t side_1 = cin_aux::getUnsigned("Enter 1st side");
		_Vertex_t side_2 = cin_aux::getUnsigned("Enter 2nd side");
		
		Rectangle obj(name, vtx, side_1, side_2);
		cont.push_back(std::make_shared<Rectangle>(std::move(obj)));
	}

	void addSquare(_Menu_shape_cont& cont) {
		std::string name;
		while (1) {
			name = cin_aux::getName("Enter name");
			if (std::find_if(cont.cbegin(), cont.cend(),
							 [&cont, &name](auto& el) { return el->name == name; }) != cont.cend())
				Menu::_Print_error("This name already exists");
			else break;
		}

		Vertex vtx;
		std::cout << "Enter left bottom vertex (x & y): ";
		std::cin >> vtx;
		_Vertex_t side = cin_aux::getUnsigned("Enter side");

		Square obj(name, vtx, side);
		cont.push_back(std::make_shared<Square>(std::move(obj)));
	}

	void printShapes(_Menu_shape_cont& cont) {
		for (auto& obj : cont)
			std::cout << *obj << std::endl;
	}

	void printNames(_Menu_shape_cont& cont) {
		for (int i = 1; i <= cont.size(); ++i)
			std::cout << i << ". " << cont[i - 1]->name << std::endl;
	}

	void saveToTxt(_Menu_shape_cont& cont) {
		if (cont.empty()) {
			std::cout << "Nothing to save\n";
			return;
		}
		
		std::string name = cin_aux::getName("Enter file name (without .txt)") + ".txt";
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
		
		std::string name = cin_aux::getName("Enter file name (w/o .json)") + ".json";
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
		std::string name = cin_aux::getName("Enter file name (without .json)") + ".json";
		std::ifstream file(name);
		if (!file)
			throw std::exception(std::format("Cannot open {} for reading", name).c_str());
		nlohmann::json json = nlohmann::json::parse(file);
		file.close();
		 
		for (auto it = json["shapes"].cbegin(); it != json["shapes"].cend(); ++it) {
			std::string name = (*it)["name"];
			std::vector<Vertex> verts;
			verts.reserve((*it)["vertices"].size());
			std::for_each((*it)["vertices"].cbegin(), (*it)["vertices"].cend(), [&verts](auto& el) {
				verts.emplace_back(el["x"].get<_Vertex_t>(), el["y"].get<_Vertex_t>());
			});

			if ((*it)["type"] == "Rectangle")
				cont.push_back(std::make_shared<Rectangle>(Rectangle(name, verts.begin())));
			else if ((*it)["type"] == "Square")
				cont.push_back(std::make_shared<Square>(Square(name, verts.begin())));
		}
	}

	void move(_Menu_shape_cont& cont) {
		printNames(cont);
		int index;
		if (index = cin_aux::getIndex(cont) == -1)
			return;
		std::cout << "How much the shape will be shifted in x & y: ";
		Vertex vtx;
		std::cin >> vtx;
		cont[index]->move(vtx.get_x(), vtx.get_y());
		std::cout << "The new vertices are:\n";
		std::copy(cont[index]->cbegin(), cont[index]->cend(), std::ostream_iterator<Vertex>(std::cout, "\n"));
	}

	void remove(_Menu_shape_cont& cont) {
		printNames(cont);
		int index;
		if (index = cin_aux::getIndex(cont) == -1)
			return;
		cont.erase(cont.begin() + index);
		std::cout << "Updated shape list\n";
		printNames(cont);
	}
	
	void clear(_Menu_shape_cont& cont) {
		std::cout << "Do you really want to clear all shapes? [y/n]: ";
		if (std::cin.get() == 'y') {
			cont.erase(cont.begin(), cont.end());
			std::cout << "Successfully cleaned\n";
		}
	}
}
