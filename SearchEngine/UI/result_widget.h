#pragma once
#include "page.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../Models/result.h"

class result_widget : public page
{
public:
	/// <summary>
	/// Default parameterized constructor. Creates a new result widget based on the given result. The result contains the page name, url, and keywords
	/// </summary>
	/// <param name="r"></param>
	result_widget(const result& r)
	{
		res = r;
	}

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
	result res;

	/// <summary>
	/// Displays the URl formatted
	/// <param name="index">The index number of the result</param>
	/// </summary>
	void display_title(int index)
	{
		std::cout << "[" + std::to_string(index) + "] " + res.name + " ";
		cout_colored('(' + res.url + ')', 9);
	}

	/// <summary>
	/// Displays the list of keywords, with the relevant ones formatted
	/// </summary>
	/// <param name="relevant_keywords"></param>
	void display_keywords(std::vector<std::string> relevant_keywords)
	{
		std::cout << " ";

		for (const auto keyword : res.relevant_keywords)
		{
			cout_colored(keyword + '\t', 2, false);
		}
		for (const auto keyword : res.irrelevant_keywords) {
			cout_colored(keyword + '\t', 8, false);
		}

		std::cout << std::endl;
	}
};
