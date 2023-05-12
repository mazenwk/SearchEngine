#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

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
		for (auto node : nodes) {
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

	webpage get_webpage_info(const std::string& url) {
		return nodes_map_[url].get_page();
	}

	void calculate_page_ranks(int iterations) {
		const auto nodes_count = nodes_map_.size();
		std::unordered_map<std::string, double> previous_ranks;

		const double initial_rank = 1.0 / nodes_count;

		for (auto kvp : nodes_map_) {
			previous_ranks[kvp.first] = initial_rank;
		}

		std::unordered_map<std::string, double> current_ranks;

		for (auto kvp : nodes_map_) {
			current_ranks[kvp.first] = 0;
		}

		for (size_t i = 0; i < iterations; i++) {
			for (auto& kvp : nodes_map_) {
				auto& current_node = kvp.second;
				std::vector<web_graph_node> redirecting_nodes;

				for (auto& kvp2 : nodes_map_) {
					auto& node = kvp2.second;
					if (current_node == node) {
						continue;
					}

					auto edges = node.get_edges();
					auto it = std::find(edges.begin(), edges.end(), current_node);

					if (it != edges.end()) {
						redirecting_nodes.push_back(node);
					}
				}

				double new_rank = 0.0;
				for (auto& node : redirecting_nodes) {
					int outgoing_links = static_cast<int>(node.get_edges().size());
					double previous_rank = previous_ranks[node.get_page().get_url()];
					new_rank += previous_rank / outgoing_links;
				}

				current_ranks[current_node.get_page().get_url()] = new_rank;
			}

			previous_ranks = current_ranks;
		}

		std::multimap<double, std::string> swapped_ranks_map;

		// Swap keys and values
		for (const auto& kvp : current_ranks) {
			swapped_ranks_map.insert(std::make_pair(kvp.second, kvp.first));
		}

		int final_rank = 1;
		for (const auto& kvp : swapped_ranks_map) {
			auto& page = nodes_map_[kvp.second].get_page();
			page.set_webpage_rank(final_rank++);
		}
	}


	/// <summary>
	/// Prints the graph in a visual way
	/// </summary>
	void print_web_graph()
	{
		for (const auto kvp : nodes_map_) {
			auto node = kvp.second;
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