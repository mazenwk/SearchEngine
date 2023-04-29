#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "page.h"

#include "../Models/result.h"

/// <summary>
/// Result widget. Displays a single result as a widget/component
/// </summary>
class result_widget : public page
{
public:
	/// <summary>
	/// Default parameterized constructor. Creates a new result widget based on the given result. The result contains the page name, url, and keywords
	/// </summary>
	/// <param name="r"></param>
	result_widget(const result& r) : res_(r) {}

	/// <summary>
	/// Displays the result with formatting
	/// </summary>
	/// <param name="index">The index number of the result</param>
	/// <param name="relevant_keywords">The list of relevant keywords, used to highlight them in the result</param>
	void display(int index, std::vector<std::string> relevant_keywords)
	{
		display_title(index);
		display_keywords(relevant_keywords);
		std::cout << std::endl;
	}

private:
	/// <summary>
	/// The result info
	/// </summary>
	result res_;

	/// <summary>
	/// Displays the URl formatted
	/// <param name="index">The index number of the result</param>
	/// </summary>
	void display_title(int index)
	{
		std::cout << "[" + std::to_string(index) + "] " + res_.name() + " ";
		cout_colored('(' + res_.url() + ')', color_code::BLUE);
	}

	/// <summary>
	/// Displays the list of keywords, with the relevant ones formatted
	/// </summary>
	/// <param name="relevant_keywords"></param>
	void display_keywords(std::vector<std::string> relevant_keywords)
	{
		std::cout << " ";

		for (const auto keyword : res_.relevant_keywords())
		{
			cout_colored(keyword + '\t', color_code::DARK_GREEN, false);
		}
		for (const auto keyword : res_.irrelevant_keywords()) {
			cout_colored(keyword + '\t', color_code::DARK_GRAY, false);
		}

		std::cout << std::endl;
	}
};
