#include <vector>
#include <map>
#include <unordered_map>

#include "files_manager.h"

#include "../Models/webpage.h"
#include "../Models/web_graph.h"
#include "initializer.h"

/// <summary>
/// Initalizes a webpages vector with web pages objects each with its URL, impressions, keywords, and links
/// </summary>
/// <returns>A vector of webpages</returns>

std::vector<webpage> initializer::initalize_webpages() {
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

web_graph initializer::initialize_web_graph(const std::vector<webpage>& webpages) {
	web_graph wg;

	// Add a node for each webpage
	for (const auto& page : webpages) {
		wg.add_webpage_node(page);
	}

	// Adds a new edge between each webpage and its links (redirects)
	for (const auto& page : webpages) {
		for (const auto& link : page.get_links()) {
			wg.add_webpage_edge(page.get_url(), link);
		}
	}

	return wg;
}

void initializer::load_data(web_graph& wg) {
	auto data = files_manager::read_csv_file("resources/data.csv");

	if (data.empty()) {
		return;
	}

	auto& nodes = wg.get_nodes_map();

	for (auto& website : data) {
		auto& page = nodes[website[0]].get_page();
		page.set_impressions(std::stoi(website[1]));
		page.set_click_throughs(std::stoi(website[2]));
		page.set_webpage_rank(std::stoi(website[3]));
	}

	for (auto& kvp : wg.get_nodes_map()) {
		auto node = kvp.second;
		auto page = node.get_page();
	}
}

void initializer::save_data(web_graph& wg) {
	std::string data;

	for (auto& kvp : wg.get_nodes_map()) {
		auto node = kvp.second;
		auto page = node.get_page();

		data += page.get_url() + ',';
		data += std::to_string(page.get_impressions()) + ',';
		data += std::to_string(page.get_click_throughs()) + ',';
		data += std::to_string(page.get_webpage_rank()) + ',';

		data += '\n';
	}

	files_manager::save_to_csv("resources/data.csv", data);
}

/// <summary>
/// Initializes the given webpages map with a pair consiting of the url and the webpage object
/// </summary>
/// <param name="webpages">The webpages map to initialize with urls</param>

void initializer::initialize_webpages_with_urls(std::map<std::string, webpage>& webpages) {
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
		auto name = extract_name(url);
		name[0] = std::toupper(name[0]);
		page.set_name(name);
		webpages.insert(std::make_pair(page.get_url(), page));
	}
}

std::string initializer::extract_name(const std::string& url) {
	// Find the beginning of the domain name.
	size_t domain_start = url.find("www.") + 4;

	// Find the end of the domain name.
	size_t domain_end = url.find("/", domain_start);

	// Extract the domain name.
	std::string domain = url.substr(domain_start, domain_end - domain_start);

	// Remove the .com/.net/.org from the domain name.
	domain = domain.substr(0, domain.size() - 4);

	return domain;
}

/// <summary>
/// Assigns the impressions to each webpage in the map
/// </summary>
/// <param name="webpages">The webpages map to assign the impressions to</param>

void initializer::assign_impressions(std::map<std::string, webpage>& webpages) {
	// Get impressions from the csv file
	auto impressions = files_manager::read_csv_file("resources/impressions.csv");

	// Assign impressions
	for (auto& impression : impressions) {
		// Get url
		auto url = impression[0];
		impression.erase(impression.begin());

		// If found update, otherwise add
		if (webpages.find(url) != webpages.end()) {
			webpages[url].set_impressions(std::stoi(impression[0]));
		}
		else {
			auto page = webpage(url);
			webpages.insert(std::make_pair(page.get_url(), page));
			webpages[url].set_impressions(std::stoi(impression[0]));
		}
	}
}

/// <summary>
/// Assigns the keywords to each webpage in the map
/// </summary>
/// <param name="webpages">The webpages map to assign the keywords to</param>

void initializer::assign_keywords(std::map<std::string, webpage>& webpages) {
	// Get keywords from the csv file
	auto keywords_list = files_manager::read_csv_file("resources/keywords.csv");

	// Assign keywords
	for (auto& keywords : keywords_list) {
		// Get url
		auto url = keywords[0];
		keywords.erase(keywords.begin());

		// If found update, otherwise add
		if (webpages.find(keywords[0]) != webpages.end()) {
			webpages[url].set_keywords(keywords);
		}
		else {
			auto page = webpage(url);
			webpages.insert(std::make_pair(page.get_url(), page));
			webpages[url].set_keywords(keywords);
		}
	}
}

/// <summary>
/// Assigns the links to each webpage in the map
/// </summary>
/// <param name="webpages">The webpages map to assign the links to</param>

void initializer::assign_links(std::map<std::string, webpage>& webpages) {
	// Get links from the csv file
	auto links_list = files_manager::read_csv_file("resources/websites.csv");

	// Assign links
	for (auto& links : links_list) {
		// Get url
		auto url = links[0];
		links.erase(links.begin());

		// If found update, otherwise add
		if (webpages.find(url) != webpages.end()) {
			webpages[url].add_link(links[0]);
		}
		else {
			auto page = webpage(url);
			webpages.insert(std::make_pair(page.get_url(), page));
			webpages[url].set_links(links);
		}
	}
}
