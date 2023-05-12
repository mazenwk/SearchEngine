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
	void display();

	/// <summary>
	/// Gets the search query from the search bar
	/// </summary>
	/// <returns>The search query</returns>
	std::string get_search_query();

private:
	/// <summary>
	/// Displays the search engine logo centered
	void display_logo();

	/// <summary>
	/// Displays the search engine search bar centered
	/// </summary>
	void display_searchbar();

	/// <summary>
	/// Displays warnings centered
	/// </summary>
	void display_warning();
};
