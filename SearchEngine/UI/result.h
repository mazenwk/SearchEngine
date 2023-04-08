#pragma once
#include "page.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class result : public page
{
public:
	/// <summary>
	/// The result URL
	/// </summary>
	std::string url;

	/// <summary>
	/// The result keywords
	/// </summary>
	std::vector<std::string> keywords;

	/// <summary>
	/// Default paramerized constructor. Creates a new result component with the URL and keywords
	/// </summary>
	/// <param name="url">The result URL</param>
	/// <param name="keywords">The result keywords</param>
	result(std::string url, std::vector<std::string> keywords);

	/// <summary>
	/// Displays the result with formatting
	/// </summary>
	/// <param name="index">The index number of the result</param>
	/// <param name="relevant_keywords">The list of relevant keywords, used to highlight them in the result</param>
	void display(int index, std::vector<std::string> relevant_keywords);

private:
	/// <summary>
	/// Displays the URl formatted
	/// <param name="index">The index number of the result</param>
	/// </summary>
	void display_url(int index);

	/// <summary>
	/// Displays the list of keywords, with the relevant ones formatted
	/// </summary>
	/// <param name="relevant_keywords"></param>
	void display_keywords(std::vector<std::string> relevant_keywords);
};
