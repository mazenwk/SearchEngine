#pragma once
#include <iostream>
#include <string>

#include "page.h"

class loading_page : public page
{
public:
	void display() {
		display_logo();
		display_searchbar();
	}

	void read_input() {
		set_cursor_pos(40, 8);
		std::string search_query;
		std::cin >> search_query;
		search(search_query);
	}

	void search(std::string& query) {

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

