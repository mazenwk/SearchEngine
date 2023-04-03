#pragma once
#include <iostream>
#include <string>

#include "page.h"
class results_page : public page
{
public:
	results_page(std::string query)
	{
		clear_page();
		current_query = query;
	}

	void display() {
		display_logo();
		display_searchbar(current_query);
		display_toolbar(5);
		std::string s;
		std::cin >> s;
		return;
	}

private:
	std::string current_query;

	void display_logo() {
		std::cout << ("   __________  ____\n");
		std::cout << ("  / ____/ __ \\/ __ )\n");
		std::cout << (" / / __/ / / / __  |\n");
		std::cout << ("/ /_/ / /_/ / /_/ /\n");
		std::cout << ("\\____/\\____/_____/\n");
		std::cout << ("google  on  budget  \n");
	}

	void display_searchbar(std::string query = " ") {
		set_cursor_pos(25, 1);

		std::cout << (" ______________________________________________________");

		set_cursor_pos(25, 2);
		std::cout << ("/                                                      \\");

		set_cursor_pos(25, 3);
		std::cout << ("|                                                      |");

		set_cursor_pos(25, 4);
		std::cout << ("\\______________________________________________________/");


		set_cursor_pos(28, 3);
		std::cout << query;
	}

	void display_toolbar(int results_count = 0) {
		set_cursor_pos(0, 6);

		std::cout << ("-------------------------------------------------------------------------------------------------------------\n");
		if (results_count > 0) {
			std::cout << "[1-" << results_count << "] Select Result \t";
		}
		else {
			std::cout << "[0-0] Select Result \t";
		}

		std::cout << "[s] Search Again\t[n] Next Page\t[p] Previous Page\t[q] Quit\t[ ]\n";
		std::cout << ("-------------------------------------------------------------------------------------------------------------\n");

		set_cursor_pos(105, 7);

	}
};

