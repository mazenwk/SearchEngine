#include "main_page.h"

void main_page::display()
{
	std::cout << "\n\n\n\n\n";
	display_logo();
	display_searchbar();
	display_warning();
}

std::string main_page::get_search()
{
	set_cursor_pos(40, 13);
	std::string search_query;
	std::getline(std::cin, search_query);

	if (search_query == "quit" || search_query == "exit")
	{
		clear_page();
		exit(0);
	}

	return search_query;
}

void main_page::display_logo()
{
	cout_centered("   __________  ____");
	cout_centered("  / ____/ __ \\/ __ )");
	cout_centered(" / / __/ / / / __  |");
	cout_centered("/ /_/ / /_/ / /_/ /");
	cout_centered("\\____/\\____/_____/ ");
	cout_centered("google  on  budget  ");
}

void main_page::display_searchbar()
{
	cout_centered(" ____________________________________________");
	cout_centered("/                                            \\");
	cout_centered("|                                            |");
	cout_centered("\\____________________________________________/");
}

void main_page::display_warning()
{
	// todo: fix to work on *inuxes
	cout_centered("Input 'exit' or 'quit' to exit the application");
	cout_centered("WARNING: THIS APP ONLY WORKS ON WINDOWS");
}
