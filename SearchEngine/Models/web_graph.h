#pragma once
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "web_graph_node.h"

/// <summary>
/// The web graph class. Used to represent webpage and the links within them as a directed graph
/// </summary>
class web_graph
{
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	web_graph() = default;

	/// <summary>
	/// Gets the graph nodes map. Each node represents a key value pair of {url,webpage}
	/// </summary>
	/// <returns>The graph nodes map</returns>
	const std::unordered_map<std::string, web_graph_node>& get_nodes_map() const { return nodes_map_; }

	/// <summary>
	/// Sets the graph nodes in the nodes map. Each node represents a webpage
	/// </summary>
	/// <param name="nodes">The new graph nodes</param>
	void set_nodes(const std::vector<web_graph_node>& nodes) {
		for (const auto node : nodes) {
			nodes_map_[node.get_page().get_url()] = node;
		}
	}

	/// <summary>
	/// Adds a new webpage node to the graph map
	/// </summary>
	/// <param name="page">The webpage to add</param>
	void add_webpage_node(const webpage page) {
		// TODO update all to getX()
		nodes_map_[page.get_url()] = web_graph_node(page);
	}

	/// <summary>
	/// Add a new webpage node to the graph map. Not recommended to use this function, use the one with a webpage as a parameter
	/// </summary>
	/// <param name="u">The webpage url</param>
	void add_webpage_node(const std::string u) {
		if (!does_webpage_node_exist(u)) {
			nodes_map_[u] = web_graph_node(u);
		}
	}

	/// <summary>
	/// Adds an edge between two webpage nodes. Searched by URL
	/// </summary>
	/// <param name="u">Node 1 URL</param>
	/// <param name="v">Node 2 URL</param>
	void add_webpage_edge(const std::string u, const std::string v) {
		if (does_webpage_edge_exist(u, v)) {
			return;
		}

		// If found update, otherwise add
		if (!does_webpage_node_exist(u))
		{
			add_webpage_node(u);
		}
		if (does_webpage_node_exist(v)) {
			nodes_map_[u].add_edge(nodes_map_[v]);
		}
		else {
			nodes_map_[u].add_edge(web_graph_node(v));
		}
	}

	/// <summary>
	/// Prints the graph in a visual way
	/// </summary>
	void print_web_graph()
	{
		for (const auto kvp : nodes_map_) {
			const auto node = kvp.second;
			std::cout << node.get_page().get_url() << ' ';

			for (auto edge : node.get_edges())
				std::cout << "-> " << edge.get_page().get_url();
			std::cout << std::endl;
		}
	}

private:
	/// <summary>
	/// The graph nodes map. Each node represents a key value pair of a url and a webpage
	/// </summary>
	std::unordered_map<std::string, web_graph_node> nodes_map_{};

	/// <summary>
	/// Checks whetehr or not a webpage node exists
	/// </summary>
	/// <param name="u">The webpage URL, acts as a key</param>
	/// <returns>True if the node exists, false otherwise</returns>
	bool does_webpage_node_exist(std::string u) {
		return !(nodes_map_.find(u) == nodes_map_.end());
	}

	/// <summary>
	/// Checks if an edge exists between two webpage nodes. Searched by URL
	/// </summary>
	/// <param name="u">Node 1 URl</param>
	/// <param name="v">Node 2 URL</param>
	/// <returns>True if an edge exists, false otherwise</returns>
	bool does_webpage_edge_exist(const std::string& u, const std::string& v) {
		bool exists = false;

		if (does_webpage_node_exist(u) && does_webpage_node_exist(v)) {
			auto u_edges = nodes_map_[u].get_edges();
			exists = std::find(u_edges.begin(), u_edges.end(), web_graph_node(v)) != u_edges.end();
		}

		return exists;
	}
};