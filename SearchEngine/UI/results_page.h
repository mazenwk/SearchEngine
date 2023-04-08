#pragma once
#include "page.h"
#include "result.h"
#include <iostream>
#include <string>

class results_page : public page
{
public:
	results_page(std::string query)
	{
		clear_page();
		current_query = query;
	}

	void display()
	{
		display_logo();
		display_searchbar(current_query);
		display_toolbar(5);
		auto r = result("Tests page", { "test", "test 2" });
		r.display(1, { "test 2" });

		auto r2 = result("Tests page", { "test", "test 2" });
		r2.display(2, { "test 2", "test" });

		get_input();
	}

private:
	std::string current_query;

	void display_logo()
	{
		std::cout << ("   __________  ____\n");
		std::cout << ("  / ____/ __ \\/ __ )\n");
		std::cout << (" / / __/ / / / __  |\n");
		std::cout << ("/ /_/ / /_/ / /_/ /\n");
		std::cout << ("\\____/\\____/_____/\n");
		std::cout << ("google  on  budget  \n");
	}

	void display_searchbar(std::string query = " ")
	{
		set_cursor_pos(25, 1);

		std::cout << (" _______________________________________________________________________________");

		set_cursor_pos(25, 2);
		std::cout << ("/                                                                               \\");

		set_cursor_pos(25, 3);
		std::cout << ("|                                                                               |");

		set_cursor_pos(25, 4);
		std::cout << ("\\_______________________________________________________________________________/");

		set_cursor_pos(28, 3);
		std::cout << query;
	}

	void display_toolbar(int results_count = 0)
	{
		set_cursor_pos(0, 6);

		std::cout << ("-------------------------------------------------------------------------------------------------------------\n");
		if (results_count > 0)
		{
			std::cout << "[1-" << results_count << "] Select Result \t";
		}
		else
		{
			std::cout << "[0-0] Select Result \t";
		}

		std::cout << "[s] Search \t[n] Next Page\t[p] Previous Page\t[q] Quit\t[ ]\n";
		std::cout << ("-------------------------------------------------------------------------------------------------------------\n");
	}

	void get_input()
	{
		set_cursor_pos(97, 7);
		std::string s;
		std::cin >> s;
	}
};
