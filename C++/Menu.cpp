//#include "Menu.h"

//void Menu::showMenu(Menu* menu) {
//	//system("cls");
//	current = menu;
//	std::cout << CSI"91m" << CSI << _Menu_right_border / 2 - menu->desc.size() / 2 + 1 << "G" <<
//		menu->desc <<
//		CSI"0m" << std::endl;
//
//	print_border();
//
//	for (auto& item : menu->items)
//		print_item(item.first, std::visit([](auto&& args) { return args.desc; }, item.second));
//
//	if (menu->parent != nullptr)
//		print_item(_Menu_back, "Back");
//	print_item(_Menu_exit, "Exit");
//
//	print_border(true);
//}