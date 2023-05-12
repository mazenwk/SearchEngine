#include <vector>
#include <string>

#include "webpage.h"
#include "web_graph_node.h"

/// <summary>
/// Creates a webpage node with the given webpage
/// </summary>
/// <param name="wp">The webpage info</param>

 web_graph_node::web_graph_node(const webpage& wp) : page_(wp) {}

/// <summary>
/// Creates a webpage node with the given webpage url
/// </summary>
/// <param name="wp">The webpage url</param>

 web_graph_node::web_graph_node(const std::string& u) : page_(webpage(u)) {}

/// <summary>
/// Gets the webpage info
/// </summary>
/// <returns>The webpage info</returns>

 webpage& web_graph_node::get_page() { return page_; }

/// <summary>
/// Sets the webpage info
/// </summary>
/// <param name="page">The webpage info</param>

 void web_graph_node::set_page(const webpage& page) { page_ = page; }

/// <summary>
/// Gets the list of nodes connected to this node
/// </summary>
/// <returns>The list of connected nodes</returns>

 std::vector<web_graph_node> web_graph_node::get_edges() { return edges_; }

/// <summary>
/// Adds an edge to the list of nodes connected to this node.
/// </summary>
/// <param name="node">The node to add as an edge.</param>

 void web_graph_node::add_edge(const web_graph_node& node) {
	edges_.push_back(node);
}

/// <summary>
/// Sets the list of nodes connected to this node
/// </summary>
/// <param name="edges">The list of connected nodes</param>

 void web_graph_node::set_edges(const std::vector<web_graph_node>& edges) { edges_ = edges; }
