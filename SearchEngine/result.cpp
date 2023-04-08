#include "result.h"

result::result(std::string url, std::vector<std::string> keywords)
{
	this->url = url;
	this->keywords = keywords;
}

void result::display(int index, std::vector<std::string> relevant_keywords)
{
	display_url(index);
	display_keywords(relevant_keywords);
	std::cout << std::endl;
}

void result::display_url(int index)
{
	std::string indexed_url = "[" + std::to_string(index) + "] " + url;
	cout_colored(indexed_url, 9);
}

void result::display_keywords(std::vector<std::string> relevant_keywords)
{
	std::cout << " ";

	std::string remaining_keywords = "";

	for (auto keyword : keywords)
	{
		bool is_relevant = std::find(relevant_keywords.begin(), relevant_keywords.end(), keyword) != relevant_keywords.end();
		if (is_relevant)
		{
			cout_colored(keyword, 2, false);
			std::cout << '\t';
		}
		else
		{
			remaining_keywords += keyword;
			remaining_keywords += "\t";
		}
	}
	cout_colored(remaining_keywords, 8);
}
