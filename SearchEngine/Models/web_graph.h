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

	/// <summary>
	/// Gets the webpage info
	/// </summary>
	/// <param name="url">The webpage url</param>
	/// <returns>The webpage info (page object)</returns>
	webpage get_webpage_info(const std::string& url) {
		return nodes_map_[url].get_page();
	}

	/// <summary>
	/// Calculates the page ranks a number of times based on the given iterations
	/// </summary>
	/// <param name="iterations">The number of iterations to go through while calculating the page ranks</param>
	void calculate_page_ranks(int iterations) {
		const auto nodes_count = nodes_map_.size();

		// Store the previous ranks of web pages
		std::unordered_map<std::string, double> previous_ranks;
		previous_ranks.reserve(nodes_count);

		// Calculate the initial rank for each web page
		const double initial_rank = 1.0 / nodes_count;

		// Initialize previous ranks for each web page
		for (const auto& kvp : nodes_map_) {
			previous_ranks.insert({ kvp.first, initial_rank });
		}

		// Store the current ranks of web pages
		std::unordered_map<std::string, double> current_ranks;
		current_ranks.reserve(nodes_count);

		// Initialize current ranks to 0.0 for each web page
		for (const auto& kvp : nodes_map_) {
			current_ranks.insert({ kvp.first, 0.0 });
		}

		// Iterate over the specified number of iterations
		for (size_t i = 0; i < iterations; i++) {
			// Calculate the new rank for each web page
			for (auto it = nodes_map_.begin(); it != nodes_map_.end(); ++it) {
				auto& current_node = it->second;
				std::vector<web_graph_node> redirecting_nodes;
				const auto& current_node_edges = current_node.get_edges();

				// Find the web pages that redirect to the current web page
				for (auto it2 = nodes_map_.begin(); it2 != nodes_map_.end(); ++it2) {
					if (it != it2) {
						auto& node = it2->second;
						const auto& edges = node.get_edges();
						if (std::find(edges.begin(), edges.end(), current_node) != edges.end()) {
							redirecting_nodes.push_back(node);
						}
					}
				}

				double new_rank = 0.0;
				for (auto& node : redirecting_nodes) {
					const auto outgoing_links = static_cast<int>(node.get_edges().size());
					const double previous_rank = previous_ranks[node.get_page().get_url()];

					// Update the new rank based on each redirecting web page
					new_rank += previous_rank / outgoing_links;
				}

				// Update the current rank for the current web page
				current_ranks[it->first] = new_rank;
			}

			// Update the previous ranks with the current ranks for the next iteration
			std::swap(previous_ranks, current_ranks);
		}

		// Create a multimap to swap keys and values (rank and URL)
		// Multimap to allow for duplicates in case 2 have the same order
		std::multimap<double, std::string> swapped_ranks_map;

		// Swap keys and values by inserting the previous ranks into the multimap
		for (const auto& kvp : previous_ranks) {
			swapped_ranks_map.insert({ kvp.second, kvp.first });
		}

		// Assign the final ranks to the web pages based on the multimap order
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