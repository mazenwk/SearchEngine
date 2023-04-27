#pragma once
#include "web_graph_node.h"
#include <vector>
#include <algorithm>
#include <iostream>

class web_graph
{
public:
	std::vector<web_graph_node> nodes;

	void add_node(webpage page) {
		if (!does_node_exist(page)) {
			nodes.push_back(web_graph_node(page));
		}
		else {
			for (auto& node : nodes) {
				if (node.page == page) {
					node.page = page;
				}
			}
		}
	}

	void add_node(std::string u) {
		if (!does_node_exist(u)) {
			nodes.push_back(web_graph_node(u));
		}
	}

	void add_edge(std::string u, std::string v) {
		if (does_edge_exist(u, v)) {
			return;
		}
		if (!does_node_exist(u))
		{
			add_node(u);
		}
		if (!does_node_exist(v))
		{
			add_node(v);
		}

		int u_index = get_node_index(u);
		if (u_index != -1) {
			int v_index = get_node_index(v);
			if (v_index != -1) {
				nodes[u_index].edges.push_back(nodes[v_index]);
			}
			else {
				nodes[u_index].edges.push_back(web_graph_node(v));
			}
		}
	}

	void print_graph()
	{
		for (size_t i = 0; i < nodes.size(); i++)
		{
			std::cout << nodes[i].page.url << ' ';

			for (auto node : nodes[i].edges)
				std::cout << "-> " << node.page.url;
			std::cout << std::endl;
		}
	}

private:
	bool does_node_exist(webpage page) {
		for (auto& node : nodes) {
			if (node.page == page) {
				return true;
			}
		}

		return false;
	}

	bool does_node_exist(std::string& n) {
		for (auto& node : nodes) {
			if (node.page.url == n) {
				return true;
			}
		}

		return false;
	}

	bool does_edge_exist(std::string& u, std::string& v) {
		bool exists = false;

		if (!does_node_exist(u) || !does_node_exist(v))
		{
			return false;
		}

		int u_index = get_node_index(u);
		if (u_index != -1) {
			auto u_edges = nodes[u_index].edges;
			exists = std::find(u_edges.begin(), u_edges.end(), web_graph_node(v)) != u_edges.end();
		}

		return exists;
	}

	int get_node_index(std::string& u) {
		int index = -1;

		auto it = std::find(nodes.begin(), nodes.end(), web_graph_node(u));
		if (it != nodes.end())
		{
			index = it - nodes.begin();
		}

		return index;
	}
};
