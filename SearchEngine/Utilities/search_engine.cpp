#include <vector>
#include <string>

#include "../Models/result.h"
#include "../Models/web_graph.h"

#include "../UI/webpage_page.h"
#include "search_engine.h"

web_graph search_engine::webgraph;

/// <summary>
/// Sets the webgraph of the search engine
/// </summary>
/// <param name="wg"></param>

void search_engine::set_web_graph(const web_graph& wg) {
	webgraph = wg;
}

/// <summary>
/// Searches for results based on the given query
/// </summary>
/// <param name="query">The query to search based on</param>
/// <returns>The list of results found based on the query</returns>

std::vector<result> search_engine::search(const std::string& query) {
	std::vector<result> results;

	results = collect_results(query);
	rank_results(results);

	return results;
}

void search_engine::display_webpage(const std::string& url) {
	auto& page = webgraph.get_webpage_info(url);
	page.increment_click_throughs();
	webpage_page wbp(page);
	wbp.display();
}

web_graph& search_engine::get_web_graph() { return webgraph; }

/// <summary>
/// Collects the results by filtering through the webgraph
/// </summary>
/// <param name="query">The query to collect results based on</param>
/// <returns>The list of results fitlered based on the query</returns>

std::vector<result> search_engine::collect_results(const std::string& query) {
	std::vector<result> collected_results;

	for (auto kvp : webgraph.get_nodes_map()) {
		auto& node = kvp.second;
		auto& page = node.get_page();

		if (query != "*" && !is_webpage_relevant(page.get_keywords(), query)) {
			continue;
		}

		page.increment_impressions();

		result res;

		res.set_name(page.get_name());
		res.set_url(page.get_url());
		res.set_score(page.get_webpage_score());

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
}

void search_engine::rank_results(std::vector<result>& results) {
	std::sort(results.begin(), results.end(), [](const result& r1, const result& r2) { return r1.get_score() > r2.get_score(); });
}

/// <summary>
/// Whether or not the given keyword is relevant to the given query
/// </summary>
/// <param name="keyword">The keyword to evaluate</param>
/// <param name="query">The query to evaluate based on</param>
/// <returns>True if the keyword is relevant, false otherwise</returns>

bool search_engine::is_keyword_relevant(const std::string keyword, const std::string query) {
	// Search for the keyword in the query
	size_t pos = query.find(keyword);
	bool relevant = pos != std::string::npos;
	return relevant;
}

/// <summary>
/// Evaluates whether or not the webpage is relevant based on the query and keywords
/// </summary>
/// <param name="keywords">The page keywords</param>
/// <param name="query">The query to evaluate</param>
/// <returns>True if the webpage is relevant based on the query, false otherwise</returns>

bool search_engine::is_webpage_relevant(const std::vector<std::string>& keywords, std::string query) {
	// Split query into vector of words and convert to lowercase
	std::vector<std::string> words;
	std::istringstream iss(query);
	std::string word;
	while (iss >> word) {
		words.push_back(word);
	}

	// Convert keywords to a set for easier searching
	std::unordered_set<std::string> keywords_set(keywords.begin(), keywords.end());

	// Evaluate quoted words
	for (auto& word : words) {
		if (word.front() == '"' && word.back() == '"') {
			word.erase(std::remove(word.begin(), word.end(), '"'), word.end());
			bool evaluation = evaluate_bsearch(bsearch_type::QUOTE, keywords_set, { word });

			if (!evaluation) {
				return false;
			}
		}
	}

	// Convert words to lowercase
	for (auto& word : words) {
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	}

	// Remove "and" keywords and evaluate
	int and_index = find_string_index(words, "and");
	while (and_index != -1) {
		bool evaluation = evaluate_bsearch(bsearch_type::AND, keywords_set, { words[and_index - 1], words[and_index + 1] });

		if (!evaluation) {
			return false;
		}

		words.erase(words.begin() + and_index);
		and_index = find_string_index(words, "and");
	}

	// Evaluate remaining words with "or" logic
	bool or_evaluation = evaluate_bsearch(bsearch_type::OR, keywords_set, words);
	return or_evaluation;
}

/// <summary>
/// Evaluates a boolean search based on the given type (OR, AND, "")
/// </summary>
/// <param name="type">The type of the boolean search</param>
/// <param name="keywords">The list of keywords</param>
/// <param name="words">The words to evaluate based on the keywords</param>
/// <returns>True if the evaluation of the statement is true, false otherwise</returns>

bool search_engine::evaluate_bsearch(const bsearch_type type, const std::unordered_set<std::string>& keywords, const std::vector<std::string>& words) {
	switch (type) {
	case bsearch_type::AND: {
		for (const std::string& word : words) {
			if (keywords.find(word) == keywords.end()) {
				return false; // Some word is not found
			}
		}
		return true; // All words are found
	}
	case bsearch_type::OR: {
		for (const std::string& word : words) {
			if (keywords.find(word) != keywords.end()) {
				return true; // Some word is found
			}
		}
		return false; // No word was found
	}
	case bsearch_type::QUOTE: {
		return keywords.find(words[0]) != keywords.end();
	}
	}

	return false; // Invalid bsearch_type
}

/// <summary>
/// Gets the index of the target string in the given vector
/// </summary>
/// <param name="words">The wods to search through</param>
/// <param name="target_word">The string to search for</param>
/// <returns>The index of the string if found, -1 otherwise</returns>

int search_engine::find_string_index(const std::vector<std::string>& words, const std::string& target_word) {
	auto iter = std::find(words.begin(), words.end(), target_word);
	if (iter != words.end()) {
		return static_cast<int>(std::distance(words.begin(), iter));
	}
	return -1;
}

/// <summary>
/// Gets the index of the target string that contains the target character in the given vector
/// </summary>
/// <param name="words">The words to search through</param>
/// <param name="target_char">The target character to look for</param>
/// <returns>The index of the string that contains the character if found, -1 otherwise</returns>

int search_engine::find_string_index_with_char(const std::vector<std::string>& words, const char target_char) {
	for (size_t i = 0; i < words.size(); ++i) {
		if (words[i].find(target_char) != std::string::npos) {
			return static_cast<int>(i);
		}
	}
	return -1;
}
