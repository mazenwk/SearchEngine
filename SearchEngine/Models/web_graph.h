#pragma once
#include <algorithm>
#include <iostream>
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
	/// Gets the graph nodes. Each node represents a webpage
	/// </summary>
	/// <returns>The graph nodes</returns>
	const std::vector<web_graph_node>& nodes() const { return nodes_; }

	/// <summary>
	/// Sets the graph nodes. Each node represents a webpage
	/// </summary>
	/// <param name="nodes">The new graph nodes</param>
	void set_nodes(const std::vector<web_graph_node>& nodes) { nodes_ = nodes; }

	/// <summary>
	/// Adds a new webpage node to the graph
	/// </summary>
	/// <param name="page">The webpage to add</param>
	void add_webpage_node(const webpage page) {
		// If found update, otherwise add
		if (!does_webpage_node_exist(page)) {
			nodes_.push_back(web_graph_node(page));
		}
		else {
			for (auto& node : nodes_) {
				if (node.page() == page) {
					node = web_graph_node(page);
				}
			}
		}
	}

	/// <summary>
	/// Add a new webpage node to the graph. Not recommended to use this function, use the one with a webpage as a parameter
	/// </summary>
	/// <param name="u">The webpage url</param>
	void add_webpage_node(const std::string u) {
		if (!does_webpage_node_exist(u)) {
			nodes_.push_back(web_graph_node(u));
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
		if (!does_webpage_node_exist(v))
		{
			add_webpage_node(v);
		}

		int u_index = get_webpage_node_index(u);
		if (u_index != -1) {
			// If found update, otherwise add
			int v_index = get_webpage_node_index(v);
			if (v_index != -1) {
				nodes_[u_index].add_edge(nodes_[v_index]);
			}
			else {
				nodes_[u_index].add_edge(web_graph_node(v));
			}
		}
	}

	/// <summary>
	/// Prints the graph in a visual way
	/// </summary>
	void print_web_graph()
	{
		for (size_t i = 0; i < nodes_.size(); i++)
		{
			std::cout << nodes_[i].page().url() << ' ';

			for (auto node : nodes_[i].edges())
				std::cout << "-> " << node.page().url();
			std::cout << std::endl;
		}
	}

private:
	/// <summary>
	/// The graph nodes. Each node represents a webpage
	/// </summary>
	std::vector<web_graph_node> nodes_{};

	/// <summary>
	/// Checks if the webpage node already exists
	/// </summary>
	/// <param name="page">The webpage to look for</param>
	/// <returns>True if found, false otherwise</returns>
	bool does_webpage_node_exist(const webpage page) {
		for (auto& node : nodes_) {
			if (node.page() == page) {
				return true;
			}
		}

		return false;
	}

	/// <summary>
	/// Checks if the webpage node already exists
	/// </summary>
	/// <param name="page">The webpage URL to look for</param>
	/// <returns>True if found, false otherwise</returns>
	bool does_webpage_node_exist(const std::string& u) {
		for (auto& node : nodes_) {
			if (node.page().url() == u) {
				return true;
			}
		}

		return false;
	}

	/// <summary>
	/// Checks if an edge exists between two webpage nodes. Searched by URL
	/// </summary>
	/// <param name="u">Node 1 URl</param>
	/// <param name="v">Node 2 URL</param>
	/// <returns>True if an edge exists, false otherwise</returns>
	bool does_webpage_edge_exist(const std::string& u, const std::string& v) {
		bool exists = false;

		if (!does_webpage_node_exist(u) || !does_webpage_node_exist(v))
		{
			return false;
		}

		int u_index = get_webpage_node_index(u);
		if (u_index != -1) {
			auto u_edges = nodes_[u_index].edges();
			exists = std::find(u_edges.begin(), u_edges.end(), web_graph_node(v)) != u_edges.end();
		}

		return exists;
	}

	/// <summary>
	/// Gets the webpage node index from the webpage nodes list.
	/// </summary>
	/// <param name="u">The webpage URL to look for</param>
	/// <returns>The index of the webpage node if found, otherwise returns -1</returns>
	int get_webpage_node_index(const std::string& u) {
		int index = -1;

		auto it = std::find(nodes_.begin(), nodes_.end(), web_graph_node(u));
		if (it != nodes_.end())
		{
			index = static_cast<int>(it - nodes_.begin());
		}

		return index;
	}
};