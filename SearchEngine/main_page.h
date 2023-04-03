#pragma once
#include <iostream>
#include <string>

#include "page.h"

class main_page : public page
{
public:
	void display() {
		std::cout << "\n\n\n\n\n";
		display_logo();
		display_searchbar();
	}

	std::string get_search() {
		set_cursor_pos(40, 13);
		std::string search_query;
		std::getline(std::cin, search_query);
		return search_query;
	}

private:
	void display_logo() {
		cout_centered("   __________  ____");
		cout_centered("  / ____/ __ \\/ __ )");
		cout_centered(" / / __/ / / / __  |");
		cout_centered("/ /_/ / /_/ / /_/ /");
		cout_centered("\\____/\\____/_____/ ");
		cout_centered("google  on  budget  ");
	}

	void display_searchbar() {
		cout_centered(" ____________________________________________");
		cout_centered("/                                            \\");
		cout_centered("|                                            |");
		cout_centered("\\____________________________________________/");
	}
};

