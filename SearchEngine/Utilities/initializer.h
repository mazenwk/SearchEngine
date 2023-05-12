#pragma once
#include <vector>
#include <map>
#include <unordered_map>

#include "files_manager.h"

#include "../Models/webpage.h"
#include "../Models/web_graph.h"

/// <summary>
/// Initializer class. Intializes the webpages and webgraph.
/// </summary>
class initializer
{
public:
	/// <summary>
	/// Initalizes a webpages vector with web pages objects each with its URL, impressions, keywords, and links
	/// </summary>
	/// <returns>A vector of webpages</returns>
	static std::vector<webpage> initalize_webpages();

	/// <summary>
	/// Initializes a web graph based on the given wepages list. Creates a directed graph from each webpage to its links (redirects)
	/// </summary>
	/// <param name="webpages">The list of webpages</param>
	/// <returns>A directed webgraph from each webage to its links (redirects)</returns>
	static web_graph initialize_web_graph(const std::vector<webpage>& webpages);

	static void load_data(web_graph& wg);

	static void save_data(web_graph& wg);
private:
	/// <summary>
	/// Initializes the given webpages map with a pair consiting of the url and the webpage object
	/// </summary>
	/// <param name="webpages">The webpages map to initialize with urls</param>
	static void initialize_webpages_with_urls(std::map<std::string, webpage>& webpages);

	static std::string extract_name(const std::string& url);

	/// <summary>
	/// Assigns the impressions to each webpage in the map
	/// </summary>
	/// <param name="webpages">The webpages map to assign the impressions to</param>
	static void assign_impressions(std::map<std::string, webpage>& webpages);


	/// <summary>
	/// Assigns the keywords to each webpage in the map
	/// </summary>
	/// <param name="webpages">The webpages map to assign the keywords to</param>
	static void assign_keywords(std::map<std::string, webpage>& webpages);

	/// <summary>
	/// Assigns the links to each webpage in the map
	/// </summary>
	/// <param name="webpages">The webpages map to assign the links to</param>
	static void assign_links(std::map<std::string, webpage>& webpages);
};

