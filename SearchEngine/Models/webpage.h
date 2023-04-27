#pragma once
#include<string>
#include<vector>

class webpage
{
public:
	std::string name;
	std::string url = "";
	int impressions = 0;
	std::vector<std::string> keywords = {};
	std::vector<std::string> links = {};

	webpage()
	{

	}

	webpage(const std::string& u)
	{
		url = u;
	}

	int page_rank() {

	}

	int score() {

	}

	bool operator==(const webpage& page)
	{
		return url == page.url;
	}
};

