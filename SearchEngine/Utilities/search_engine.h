#pragma once
#include <vector>
#include <string>

#include "../Models/result.h"
#include "../Models/web_graph.h"

#include "../UI/webpage_page.h"

/// <summary>
/// Boolean Search Types
/// </summary>
enum bsearch_type {
	AND,
	OR,
	QUOTE
};

/// <summary>
/// The actual search engine class
/// </summary>
class search_engine
{
public:
	/// <summary>
	/// Sets the webgraph of the search engine
	/// </summary>
	/// <param name="wg"></param>
	static void set_web_graph(const web_graph& wg);

	/// <summary>
	/// Searches for results based on the given query
	/// </summary>
	/// <param name="query">The query to search based on</param>
	/// <returns>The list of results found based on the query</returns>
	static std::vector<result> search(const std::string& query);

	static void display_webpage(const std::string& url);

	static web_graph& get_web_graph();

private:
	/// <summary>
	/// The search engine webgraph
	/// </summary>
	static web_graph webgraph;

	/// <summary>
	/// Collects the results by filtering through the webgraph
	/// </summary>
	/// <param name="query">The query to collect results based on</param>
	/// <returns>The list of results fitlered based on the query</returns>
	static std::vector<result> collect_results(const std::string& query);;

	/// <summary>
	/// Ranks the results based on their score
	/// </summary>
	/// <param name="results">The results to rank</param>
	static void rank_results(std::vector<result>& results);

	/// <summary>
	/// Whether or not the given keyword is relevant to the given query
	/// </summary>
	/// <param name="keyword">The keyword to evaluate</param>
	/// <param name="query">The query to evaluate based on</param>
	/// <returns>True if the keyword is relevant, false otherwise</returns>
	static bool is_keyword_relevant(const std::string keyword, const std::string query);

	/// <summary>
	/// Evaluates whether or not the webpage is relevant based on the query and keywords
	/// </summary>
	/// <param name="keywords">The page keywords</param>
	/// <param name="query">The query to evaluate</param>
	/// <returns>True if the webpage is relevant based on the query, false otherwise</returns>
	static bool is_webpage_relevant(const std::vector<std::string>& keywords, std::string query);

	/// <summary>
	/// Evaluates a boolean search based on the given type (OR, AND, "")
	/// </summary>
	/// <param name="type">The type of the boolean search</param>
	/// <param name="keywords">The list of keywords</param>
	/// <param name="words">The words to evaluate based on the keywords</param>
	/// <returns>True if the evaluation of the statement is true, false otherwise</returns>
	static bool evaluate_bsearch(const bsearch_type type, const std::unordered_set<std::string>& keywords, const std::vector<std::string>& words);

	/// <summary>
	/// Gets the index of the target string in the given vector
	/// <param name="words">The wods to search through</param>
	/// <param name="target_word">The string to search for</param>
	/// <returns>The index of the string if found, -1 otherwise</returns>
	static int find_string_index(const std::vector<std::string>& words, const std::string& target_word);

	/// <summary>
	/// Gets the index of the target string that contains the target character in the given vector
	/// </summary>
	/// <param name="words">The words to search through</param>
	/// <param name="target_char">The target character to look for</param>
	/// <returns>The index of the string that contains the character if found, -1 otherwise</returns>
	static int find_string_index_with_char(const std::vector<std::string>& words, const char target_char);
};