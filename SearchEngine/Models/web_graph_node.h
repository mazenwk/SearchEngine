#pragma once
#include "webpage.h"
#include <string>
#include <vector>

class web_graph_node
{
public:
	webpage page;
	// TODO: turn into pointer
	std::vector<web_graph_node> edges;

	web_graph_node(std::string& n) {
		page.url = n;
	}

	web_graph_node(webpage wp) {
		page = wp;
	}

	bool operator==(web_graph_node const node) {
		return page.url == node.page.url;
	}

	bool operator!=(web_graph_node const node) {
		return page.url != node.page.url;
	}
};

