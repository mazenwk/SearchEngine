#pragma once
#include "page.h"
#include <iostream>
#include <string>


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
	std::string get_search();

private:
	/// <summary>
	/// Displays the search engine logo centered
	/// </summary>
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
