#pragma once
#include <iostream>
#include <string>

#include "page.h"


/// <summary>
/// The main Page with the search engine logo and search bar
/// </summary>
class main_page : public page
{
public:
	/// <summary>
	/// Displays the main page
	/// </summary>
	void display()
	{
		std::cout << "\n\n\n\n\n";
		display_logo();
		display_searchbar();
		display_warning();
	}

	/// <summary>
	/// Gets the search query from the search bar
	/// </summary>
	/// <returns>The search query</returns>
	std::string get_search_query()
	{
		set_cursor_pos(40, 13);
		std::string search_query;
		std::getline(std::cin, search_query);

		if (search_query == "quit" || search_query == "exit")
		{
			clear_page();

			// TODO: exit in a cleaner way
			exit(0);
		}

		return search_query;
	}

private:
	/// <summary>
	/// Displays the search engine logo centered
	/// </summary>
	void display_logo()
	{
		cout_centered("   __________  ____");
		cout_centered("  / ____/ __ \\/ __ )");
		cout_centered(" / / __/ / / / __  |");
		cout_centered("/ /_/ / /_/ / /_/ /");
		cout_centered("\\____/\\____/_____/ ");
		cout_centered("google  on  budget  ");
	}

	/// <summary>
	/// Displays the search engine search bar centered
	/// </summary>
	void display_searchbar()
	{
		cout_centered(" ____________________________________________");
		cout_centered("/                                            \\");
		cout_centered("|                                            |");
		cout_centered("\\____________________________________________/");
	}

	/// <summary>
	/// Displays warnings centered
	/// </summary>
	void display_warning()
	{
		// todo: fix to work on *inuxes
		cout_centered("Input '*' to display all results unfiltered and unranked");
		cout_centered("Input 'exit' or 'quit' to exit the application");
	}
};
