#pragma once
#include <vector>
#include <string>

#include "../Models/result.h"
#include "../Models/web_graph.h"

/// <summary>
/// The actual search engine class
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

		for (const auto kvp : webgraph.get_nodes_map()) {
			auto node = kvp.second;
			auto page = node.get_page();

			if (!page.get_webpage_relevancy(query)) {
				continue;
			}

			result res;

			res.set_name(page.get_name());
			res.set_url(page.get_url());

			for (auto keyword : page.get_keywords()) {
				if (is_keyword_relevant(keyword, query)) {
					res.add_relevant_keyword(keyword);
				}
				else {
					res.add_irrelevant_keyword(keyword);
				}
			}

			collected_results.push_back(res);
		}

		return collected_results;
	};

	static bool is_keyword_relevant(const std::string keyword, const std::string query) {
		// Search for the keyword in the query
		size_t pos = query.find(keyword);
		bool relevant = pos != std::string::npos;
		return relevant;
	}

	static void rank_results(std::vector<result>& results) {

	}
};