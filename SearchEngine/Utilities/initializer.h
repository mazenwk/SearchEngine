#pragma once
#include <vector>
#include <map>
#include <unordered_map>

#include "files_manager.h"

#include "../models/webpage.h"
#include "../models/web_graph.h"

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
	static std::vector<webpage> initalize_webpages() {
		// Start with a map for faster lookups within each function
		// Lookups are needed in case a website already exists and just needs a field to update
		std::map<std::string, webpage> webpage_map;

		// Initialize map with urls
		initialize_webpages_with_urls(webpage_map);

		// Initialize map with impressions
		assign_impressions(webpage_map);

		// Initialize map with keywords
		assign_keywords(webpage_map);

		// Initialize map with links
		assign_links(webpage_map);

		// Transform the map into a vector of webpages to return
		std::vector<webpage> webpages;
		for (const auto& pair : webpage_map) {
			webpages.push_back(pair.second);
		}

		return webpages;
	}

	/// <summary>
	/// Initializes a web graph based on the given wepages list. Creates a directed graph from each webpage to its links (redirects)
	/// </summary>
	/// <param name="webpages">The list of webpages</param>
	/// <returns>A directed webgraph from each webage to its links (redirects)</returns>
	static web_graph initialize_web_graph(const std::vector<webpage>& webpages) {
		web_graph wg;

		// Add a node for each webpage
		for (const auto& page : webpages) {
			wg.add_node(page);
		}

		// Adds a new edge between each webpage and its links (redirects)
		for (const auto& page : webpages) {
			for (const auto& link : page.links) {
				wg.add_edge(page.url, link);
			}
		}

		return wg;
	}

private:
	/// <summary>
	/// Initializes the given webpages map with a pair consiting of the url and the webpage object
	/// </summary>
	/// <param name="webpages">The webpages map to initialize with urls</param>
	static void initialize_webpages_with_urls(std::map<std::string, webpage>& webpages) {
		// If not empty return
		if (!webpages.empty()) {
			return;
		}

		// Get urls from the csv file
		auto websites = files_manager::read_csv_file("resources/urls.csv");

		// Populate map
		for (const auto& website : websites) {
			auto url = website[0];
			auto page = webpage(url);
			webpages.insert(std::make_pair(page.url, page));
		}
	}

	/// <summary>
	/// Assigns the impressions to each webpage in the map
	/// </summary>
	/// <param name="webpages">The webpages map to assign the impressions to</param>
	static void assign_impressions(std::map<std::string, webpage>& webpages) {
		// Get impressions from the csv file
		auto impressions = files_manager::read_csv_file("resources/impressions.csv");

		// Assign impressions
		for (auto& impression : impressions) {
			// Get url
			auto url = impression[0];
			impression.erase(impression.begin());

			// If found update, otherwise add
			if (webpages.find(url) != webpages.end()) {
				webpages[url].impressions = std::stoi(impression[0]);
			}
			else {
				auto page = webpage(url);
				webpages.insert(std::make_pair(page.url, page));
				webpages[url].impressions = std::stoi(impression[0]);
			}
		}
	}


	/// <summary>
	/// Assigns the keywords to each webpage in the map
	/// </summary>
	/// <param name="webpages">The webpages map to assign the keywords to</param>
	static void assign_keywords(std::map<std::string, webpage>& webpages) {
		// Get keywords from the csv file
		auto keywords_list = files_manager::read_csv_file("resources/keywords.csv");

		// Assign keywords
		for (auto& keywords : keywords_list) {
			// Get url
			auto url = keywords[0];
			keywords.erase(keywords.begin());

			// If found update, otherwise add
			if (webpages.find(keywords[0]) != webpages.end()) {
				webpages[url].keywords = keywords;
			}
			else {
				auto page = webpage(url);
				webpages.insert(std::make_pair(page.url, page));
				webpages[url].keywords = keywords;
			}
		}
	}

	/// <summary>
	/// Assigns the links to each webpage in the map
	/// </summary>
	/// <param name="webpages">The webpages map to assign the links to</param>
	static void assign_links(std::map<std::string, webpage>& webpages) {
		// Get links from the csv file
		auto links_list = files_manager::read_csv_file("resources/websites.csv");

		// Assign links
		for (auto& links : links_list) {
			// Get url
			auto url = links[0];
			links.erase(links.begin());

			// If found update, otherwise add
			if (webpages.find(url) != webpages.end()) {
				webpages[url].links.push_back(links[0]);
			}
			else {
				auto page = webpage(url);
				webpages.insert(std::make_pair(page.url, page));
				webpages[url].links = links;
			}
		}
	}
};

