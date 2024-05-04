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
				} else {
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					return n;
				}
			}
		}

		std::string getName(std::string prompt) {
			std::string name;
			while (1) {
				std::cout << prompt << ": ";
				std::cin >> name;
				if (std::cin.fail() or !std::regex_match(name, std::regex("^[a-zA-Z]\\w*$"))) {
					std::cin.clear();
					Menu::_Print_error("Name must start with a letter and contain alphanumeric symbols");
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				} else {
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					return name;
				}
			}
		}

		std::string getNameWithFindCheck(_Menu_shape_cont& cont) {
			std::string name;
			while (1) {
				name = cin_aux::getName("Enter name");
				if (std::find_if(cont.cbegin(), cont.cend(), [&cont, &name](auto& el) {
					return el->name == name;
				}) != cont.cend())
					Menu::_Print_error("This name already exists");
				else return name;
			}
		}

		std::string getFileName(std::string prompt, std::string fileext) {
			std::string fname;
			while (1) {
				std::cout << prompt << ": ";
				std::cin >> fname;

				if (std::cin.fail()) {
					std::cin.clear();
					Menu::_Print_error("Filename error");
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				} else {
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (fname[0] == '"')
						fname.erase(fname.begin());
					if (fname[fname.size() - 1] == '"')
						fname.erase(fname.begin() + fname.size() - 1);

					int pos = 0;
					while ((pos = fname.find('\\', pos)) != std::string::npos) {
						fname.replace(pos, 1, "\\\\");
						pos += 2;
					}

					if (!fname.ends_with(fileext))
						fname += fileext;
					return fname;
				}
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
				} else {
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					return index - 1;
				}
			}
		}

		Vertex getVertex(std::string prompt) {
			Vertex vtx;
			vtx_input:
			while (true) {
				std::cout << prompt << ": ";
				try {
					std::cin >> vtx;
				} catch (std::exception&) {
					Menu::_Print_error("Vertex input error");
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					goto vtx_input;
				}
				return vtx;
			}
		}
	}

	void addRectangle(_Menu_shape_cont& cont) {
		std::string name = cin_aux::getNameWithFindCheck(cont);
		Vertex vtx = cin_aux::getVertex("Enter left bottom vertex (x & y)");
		_Vertex_t side_w = cin_aux::getUnsigned("Enter side_w");
		_Vertex_t side_h = cin_aux::getUnsigned("Enter side_h");
		
		Rectangle obj(name, vtx, side_w, side_h);
		cont.push_back(std::make_shared<Rectangle>(std::move(obj)));
	}

	void addSquare(_Menu_shape_cont& cont) {
		std::string name = cin_aux::getNameWithFindCheck(cont);
		Vertex vtx = cin_aux::getVertex("Enter left bottom vertex (x & y)");
		_Vertex_t side = cin_aux::getUnsigned("Enter side");
		Square obj(name, vtx, side);
		cont.push_back(std::make_shared<Square>(std::move(obj)));
	}

	void printShapeInfo(_Menu_shape_cont& cont) {
		if (cont.empty()) {
			std::cout << "Nothing to print\n";
			return;
		}

		_OutputMaxSquare(std::cout, cont);
		std::cout << std::endl;
		for (auto& obj : cont)
			std::cout << *obj << std::endl;
	}

	void printNames(_Menu_shape_cont& cont) {
		if (cont.empty()) {
			std::cout << "Nothing to print\n";
			return;
		}
		for (int i = 1; i <= cont.size(); ++i)
			std::cout << i << ". " << cont[i - 1]->name << std::endl;
	}

	inline void _OutputMaxSquare(std::ostream& os, _Menu_shape_cont& cont) {
		auto shp = _GetMaxSquareShape(cont);
		os << "Max square: " << shp->square() << " (" << shp->name << ')' << "\n";
	}

	std::shared_ptr<Shape> _GetMaxSquareShape(_Menu_shape_cont& cont) {
		return *std::max_element(cont.begin(), cont.end(),
				[](auto& p1, auto& p2) { return p1->square() < p2->square(); });
	}

	void printMaxSquare(_Menu_shape_cont& cont) {
		if (cont.empty()) {
			std::cout << "Create at least one shape, please\n";
			return;
		}
		_OutputMaxSquare(std::cout, cont);
	}

	void saveAsTxt(_Menu_shape_cont& cont) {
		if (cont.empty()) {
			std::cout << "Nothing to save\n";
			return;
		}
		
		std::string name = cin_aux::getFileName("Enter path / file name", ".txt");
		std::ofstream file(name);
		if (!file)
			throw std::exception(std::format("Cannot open {} for writing", name).c_str());

		_OutputMaxSquare(file, cont);
		file << std::endl;

		for (auto& obj : cont)
			file << *obj << std::endl;
		file.close();
	}

	void saveAsJson(_Menu_shape_cont& cont) {
		if (cont.empty()) {
			std::cout << "Nothing to save\n";
			return;
		}
		
		std::string name = cin_aux::getFileName("Enter path / file name", ".json");
		std::ofstream file(name);
		if (!file)
			throw std::exception(std::format("Cannot open {} for writing", name).c_str());

		nlohmann::json json;
		nlohmann::json& j_info = json["info"];

		j_info["count"] = cont.size();
		nlohmann::json& j_max_sq = j_info["max_square"];
		auto max_sq_shp = _GetMaxSquareShape(cont);
		j_max_sq["square"] = max_sq_shp->square();
		j_max_sq["shape_name"] = max_sq_shp->name;

		for (auto& obj : cont)
			json["shapes"].push_back(std::move(obj->makeJson()));
		file << json.dump(4) << std::endl;
		file.close();
	}

	void fromJson(_Menu_shape_cont& cont) {
		std::string name = cin_aux::getFileName("Enter path / file name", ".json");
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
			cont.clear();
			std::cout << "Successfully cleaned\n";
		}
	}
}
