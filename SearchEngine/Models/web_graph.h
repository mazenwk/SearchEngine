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
	std::unordered_map<std::string, web_graph_node>& get_nodes_map();

	/// <summary>
	/// Sets the graph nodes in the nodes map. Each node represents a webpage
	/// </summary>
	/// <param name="nodes">The new graph nodes</param>
	void set_nodes(const std::vector<web_graph_node>& nodes);

	/// <summary>
	/// Adds a new webpage node to the graph map
	/// </summary>
	/// <param name="page">The webpage to add</param>
	void add_webpage_node(const webpage page);

	/// <summary>
	/// Add a new webpage node to the graph map. Not recommended to use this function, use the one with a webpage as a parameter
	/// </summary>
	/// <param name="u">The webpage url</param>
	void add_webpage_node(const std::string u);

	/// <summary>
	/// Adds an edge between two webpage nodes. Searched by URL
	/// </summary>
	/// <param name="u">Node 1 URL</param>
	/// <param name="v">Node 2 URL</param>
	void add_webpage_edge(const std::string u, const std::string v);

	/// <summary>
	/// Gets the webpage info
	/// </summary>
	/// <param name="url">The webpage url</param>
	/// <returns>The webpage info (page object)</returns>
	webpage& get_webpage_info(const std::string& url);

	/// <summary>
	/// Calculates the page ranks a number of times based on the given iterations
	/// </summary>
	/// <param name="iterations">The number of iterations to go through while calculating the page ranks</param>
	void calculate_page_ranks(int iterations);

	/// <summary>
	/// Prints the graph in a visual way
	/// </summary>
	void print_web_graph();

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
	bool does_webpage_node_exist(std::string u);

	/// <summary>
	/// Checks if an edge exists between two webpage nodes. Searched by URL
	/// </summary>
	/// <param name="u">Node 1 URl</param>
	/// <param name="v">Node 2 URL</param>
	/// <returns>True if an edge exists, false otherwise</returns>
	bool does_webpage_edge_exist(const std::string& u, const std::string& v);
};