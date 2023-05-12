#include <iostream>
#include <string>

#include "page.h"
#include "main_page.h"

/// <summary>
/// Displays the main page
/// </summary>

 void main_page::display()
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

 std::string main_page::get_search_query()
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

/// <summary>
/// Displays the search engine logo centered

 void main_page::display_logo()
/// </summary>
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

 void main_page::display_searchbar()
{
	cout_centered(" ____________________________________________");
	cout_centered("/                                            \\");
	cout_centered("|                                            |");
	cout_centered("\\____________________________________________/");
}

/// <summary>
/// Displays warnings centered
/// </summary>

 void main_page::display_warning()
{
	// todo: fix to work on *inuxes
	cout_centered("Input '*' to display all results unfiltered and unranked");
	cout_centered("Input 'exit' or 'quit' to exit the application");
}
