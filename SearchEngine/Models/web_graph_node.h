#pragma once
#include <vector>
#include <string>

#include "webpage.h"

/// <summary>
/// Web grapgh node class. Acts as a webpage node in the graph
/// </summary>
class web_graph_node
{
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	web_graph_node() = default;

	/// <summary>
	/// Creates a webpage node with the given webpage
	/// </summary>
	/// <param name="wp">The webpage info</param>
	web_graph_node(const webpage& wp);

	/// <summary>
	/// Creates a webpage node with the given webpage url
	/// </summary>
	/// <param name="wp">The webpage url</param>
	web_graph_node(const std::string& u);

	/// <summary>
	/// Checks whether the given node is equal to the current one or not using the URL
	/// </summary>
	/// <param name="node">The webpage node to compare to</param>
	/// <returns>True if they are equal, false otherwise</returns>
	bool operator==(const web_graph_node& node) const {
		return page_.get_url() == node.page_.get_url();
	}

	/// <summary>
	/// Checks whether the given node is not equal to the current one or not using the URL
	/// </summary>
	/// <param name="node">The webpage node to compare to</param>
	/// <returns>True if they are not equal, false otherwise</returns>
	bool operator!=(const web_graph_node& node) const {
		return page_.get_url() != node.page_.get_url();
	}

	/// <summary>
	/// Gets the webpage info
	/// </summary>
	/// <returns>The webpage info</returns>
	webpage& get_page();

	/// <summary>
	/// Sets the webpage info
	/// </summary>
	/// <param name="page">The webpage info</param>
	void set_page(const webpage& page);

	/// <summary>
	/// Gets the list of nodes connected to this node
	/// </summary>
	/// <returns>The list of connected nodes</returns>
	std::vector<web_graph_node> get_edges();

	/// <summary>
	/// Adds an edge to the list of nodes connected to this node.
	/// </summary>
	/// <param name="node">The node to add as an edge.</param>
	void add_edge(const web_graph_node& node);

	/// <summary>
	/// Sets the list of nodes connected to this node
	/// </summary>
	/// <param name="edges">The list of connected nodes</param>
	void set_edges(const std::vector<web_graph_node>& edges);

private:
	/// <summary>
	/// The webpage info
	/// </summary>
	webpage page_;

	/// <summary>
	/// The connected to this node
	/// </summary>
	std::vector<web_graph_node> edges_{};
};

