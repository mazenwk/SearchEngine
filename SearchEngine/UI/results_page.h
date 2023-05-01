#pragma once
#include <iostream>
#include <sstream>
#include <string>

#include "page.h"
#include "result_widget.h"

#include "../Models/result.h"
#include "../Models/web_graph.h"

#include "../Utilities/search_engine.h"

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
	void search(const std::string query) {
		clear_page();
		current_query = query;

		// Searches for actual results
		auto results = search_engine::search(current_query);

		// Creates a new result widget for each result found
		std::vector<result_widget> results_widgets;
		for (size_t i = 0; i < results.size(); i++)
		{
			results_widgets.push_back(result_widget(results[i]));
		}

		display(current_query, results_widgets);
	}

private:
	/// <summary>
	/// The current search query
	/// </summary>
	std::string current_query;

	/// <summary>
	/// The maximum number of results displayd per page
	/// </summary>
	int max_results_per_page = 5;

	/// <summary>
	/// Displays the results page
	/// </summary>
	/// <param name="query">The original search query</param>
	/// <param name="results">The list of results</param>
	void display(const std::string query, std::vector<result_widget> results)
	{
		display_logo();
		display_searchbar(query);
		display_toolbar(static_cast<int>(results.size()));

		// Extracts the keywords for highlighting the relevant keywords
		auto keywords = split_query(current_query);
		// TOOD: Split into pages after exceeding maximum
		for (size_t i = 0; i < results.size(); i++)
		{
			results[i].display(static_cast<int>(i + 1), keywords);
		}

		get_input();
	}

	/// <summary>
	/// Splits the query into a list of words
	/// </summary>
	/// <param name="query">The search query</param>
	/// <returns>A list of words in the search query</returns>
	std::vector<std::string> split_query(std::string query) {

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
	void display_logo()
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

		set_cursor_at_searchbar();
		std::cout << query;
	}

	/// <summary>
	/// Displays the toolbar for guiding the next input
	/// </summary>
	/// <param name="results_count">The number of results found</param>
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

	/// <summary>
	/// Gets the next input
	/// </summary>
	void get_input()
	{
		set_cursor_at_input();

		char c;
		std::cin >> c;

		switch (c)
		{
		case 's':
			set_cursor_at_searchbar();

			do {
				std::getline(std::cin, current_query);
			} while (current_query == "");

			search(current_query);
			break;
		case 'q':
			clear_page();
			exit(0);
			break;
		default:
			break;
		}
	}

	/// <summary>
	/// Sets the cursor at the search bar
	/// </summary>
	void set_cursor_at_searchbar() {
		set_cursor_pos(28, 3);
		std::cout << "                                                         ";
		set_cursor_pos(28, 3);
	}

	/// <summary>
	/// Sets the cursor at the input box
	/// </summary>
	void set_cursor_at_input() {
		set_cursor_pos(97, 7);
		std::cout << " ";
		set_cursor_pos(97, 7);
	}
};
