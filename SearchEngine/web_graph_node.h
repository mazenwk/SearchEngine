#pragma once
#include <string>
#include <vector>

class web_graph_node
{
public:
	std::string value;
	std::vector<web_graph_node> edges;

	web_graph_node(std::string& v) {
		value = v;
	}

	bool operator==(web_graph_node const node) {
		return value == node.value;
	}

	bool operator!=(web_graph_node const node) {
		return value != node.value;
	}
};

