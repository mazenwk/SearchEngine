#pragma once
#include <vector>
#include <string>
#include "../Models/result.h"
#include "../Models/web_graph.h"

/// <summary>
/// The actual search engine manager class
/// </summary>
class search_engine
{
public:
	static void set_web_graph(const web_graph& wg) {
		webgraph = wg;
	}

	static std::vector<result> search(const std::string& query) {
		std::vector<result> results;

		results = collect_results(query);
		rank_results(results);

		return results;
	}

private:
	static web_graph webgraph;

	static std::vector<result> collect_results(const std::string& query) {
		std::vector<result> collected_results;

		for (const auto node : webgraph.nodes) {
			auto page = node.page;
			result res;

			// TODO: Add name property
			res.name = page.name;
			res.url = page.url;

			for (auto keyword : page.keywords) {
				if (is_keyword_relevant(query, keyword)) {
					res.relevant_keywords.push_back(keyword);
				}
				else {
					res.irrelevant_keywords.push_back(keyword);
				}
			}

			if (res.relevant_keywords.size() != 0) {
				collected_results.push_back(res);
			}
		}

		return collected_results;
	};

	static bool is_keyword_relevant(const std::string query, const std::string keyword) {
		// Search for the keyword in the query
		size_t pos = query.find(keyword);
		bool relevant = pos != std::string::npos;
		return relevant;
	}

	static void rank_results(std::vector<result>& results) {

	}
};