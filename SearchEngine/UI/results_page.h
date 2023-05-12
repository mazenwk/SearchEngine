#pragma once
#include <iostream>
#include <sstream>
#include <string>

#include "page.h"
#include "result_widget.h"

#include "../Models/result.h"
#include "../Models/web_graph.h"

#include "../Utilities/search_engine.h"
#include "../Utilities/initializer.h"

/// <summary>
/// The results page. Displays the search query results
/// </summary>
class results_page : public page
{
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	results_page() = default;

	/// <summary>
	/// Searches through the web graph for relevant results
	/// </summary>
	/// <param name="query">The search query to search with</param>
	void search(const std::string query);

private:
	/// <summary>
	/// The current search query
	/// </summary>
	std::string current_query;

	/// <summary>
	/// The maximum number of results displayd per page
	/// </summary>
	int max_results_per_page = 5;

	std::vector<result> current_results;

	/// <summary>
	/// Displays the results page
	/// </summary>
	/// <param name="query">The original search query</param>
	/// <param name="results">The list of results</param>
	void display(const std::string query, std::vector<result> results);

	/// <summary>
	/// Displays the search bar menu
	/// </summary>
	/// <param name="query">Current qeruy</param>
	/// <param name="results_count">Results count</param>
	void display_menu(const std::string& query, const int results_count);

	/// <summary>
	/// Splits the query into a list of words
	/// </summary>
	/// <param name="query">The search query</param>
	/// <returns>A list of words in the search query</returns>
	std::vector<std::string> split_query(std::string query);

	/// <summary>
	/// Displays the search engine logo
	/// </summary>
	void display_logo();

	/// <summary>
	/// Displays the search bar with the previous search query
	/// </summary>
	/// <param name="query">The previous search query</param>
	void display_searchbar(std::string query = " ");

	/// <summary>
	/// Displays the toolbar for guiding the next input
	/// </summary>
	/// <param name="results_count">The number of results found</param>
	void display_toolbar(int results_count = 0);

	/// <summary>
	/// Gets the next input
	/// </summary>
	void get_input(short x = -1, short y = -1);

	/// <summary>
	/// Sets the cursor at the search bar
	/// </summary>
	void set_cursor_at_searchbar();

	/// <summary>
	/// Sets the cursor at the input box
	/// </summary>
	void set_cursor_at_input();
};
