#pragma once
#include <string>
#include <vector>
class result
{
public:
	std::string name;
	std::string url;
	std::vector<std::string> relevant_keywords;
	std::vector<std::string> irrelevant_keywords;

	result() = default;

	result(const std::string& n, const std::string& u, const std::vector<std::string>& rk, const std::vector<std::string>& irk)
	{
		name = n;
		url = u;
		relevant_keywords = rk;
		irrelevant_keywords = irk;
	}
};

