#include <iostream>
#include <sstream>
#include <string>

#include "page.h"
#include "result_widget.h"

#include "../Models/result.h"
#include "../Models/web_graph.h"

#include "../Utilities/search_engine.h"
#include "../Utilities/initializer.h"
#include "results_page.h"

/// <summary>
/// Searches through the web graph for relevant results
/// </summary>
/// <param name="query">The search query to search with</param>

 void results_page::search(const std::string query) {
	clear_page();
	current_query = query;

	// Searches for actual results
	current_results = search_engine::search(current_query);

	display(current_query, current_results);
}

/// <summary>
/// Displays the results page
/// </summary>
/// <param name="query">The original search query</param>
/// <param name="results">The list of results</param>

 void results_page::display(const std::string query, std::vector<result> results)
{
	display_menu(query, static_cast<int>(results.size()));

	// Creates a new result widget for each result found
	std::vector<result_widget> results_widgets;
	for (size_t i = 0; i < results.size(); i++)
	{
		results_widgets.push_back(result_widget(results[i]));
	}

	// Extracts the keywords for highlighting the relevant keywords
	auto keywords = split_query(current_query);

	// TOOD: Split into pages after exceeding maximum
	for (size_t i = 0; i < results_widgets.size(); i++)
	{
		results_widgets[i].display(static_cast<int>(i + 1), keywords);
	}

	get_input();
}

 void results_page::display_menu(const std::string& query, const int results_count) {
	display_logo();
	display_searchbar(query);
	display_toolbar(results_count);
}

/// <summary>
/// Splits the query into a list of words
/// </summary>
/// <param name="query">The search query</param>
/// <returns>A list of words in the search query</returns>

 std::vector<std::string> results_page::split_query(std::string query) {

	std::vector<std::string> split_query;
	std::stringstream ss(query);
	std::string s;

	while (std::getline(ss, s, ' ')) {
		split_query.push_back(s);
	}

	return split_query;
}

/// <summary>
/// Displays the search engine logo
/// </summary>

 void results_page::display_logo()
{
	std::cout << ("   __________  ____\n");
	std::cout << ("  / ____/ __ \\/ __ )\n");
	std::cout << (" / / __/ / / / __  |\n");
	std::cout << ("/ /_/ / /_/ / /_/ /\n");
	std::cout << ("\\____/\\____/_____/\n");
	std::cout << ("google  on  budget  \n");
}

/// <summary>
/// Displays the search bar with the previous search query
/// </summary>
/// <param name="query">The previous search query</param>

 void results_page::display_searchbar(std::string query)
{
	set_cursor_pos(25, 1);

	std::cout << (" _______________________________________________________________________________");

	set_cursor_pos(25, 2);
	std::cout << ("/                                                                               \\");

	set_cursor_pos(25, 3);
	std::cout << ("|                                                                               |");

	set_cursor_pos(25, 4);
	std::cout << ("\\_______________________________________________________________________________/");

	set_cursor_at_searchbar();
	std::cout << query;
}

/// <summary>
/// Displays the toolbar for guiding the next input
/// </summary>
/// <param name="results_count">The number of results found</param>

 void results_page::display_toolbar(int results_count)
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

/// <summary>
/// Gets the next input
/// </summary>

 void results_page::get_input(short x, short y)
{
	set_cursor_at_input();

	char c;
	std::cin >> c;

	switch (c)
	{
	case 's':
		current_results.clear();
		set_cursor_at_searchbar();

		do {
			std::getline(std::cin, current_query);
		} while (current_query == "");

		search(current_query);
		break;
	case 'q':
		clear_page();
		initializer::save_data(search_engine::get_web_graph());
		exit(0);
		break;
	case 'b':
		clear_page();
		display(current_query, current_results);
		get_input();
		break;
	default:
		if (std::isdigit(c)) {
			int result_index = c - '1';
			if (result_index < current_results.size()) {
				search_engine::display_webpage(current_results[result_index].get_url());
				get_input();
			}
		}
		break;
	}
}

/// <summary>
/// Sets the cursor at the search bar
/// </summary>

 void results_page::set_cursor_at_searchbar() {
	set_cursor_pos(28, 3);
	std::cout << "                                                         ";
	set_cursor_pos(28, 3);
}

/// <summary>
/// Sets the cursor at the input box
/// </summary>

 void results_page::set_cursor_at_input() {
	set_cursor_pos(97, 7);
	std::cout << " ";
	set_cursor_pos(97, 7);
}
