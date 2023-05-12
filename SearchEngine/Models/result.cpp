#include <string>
#include <vector>

#include "result.h"

/// <summary>
/// Parameterized constructor. Creates a result with the info given
/// </summary>
/// <param name="n">Result website name</param>
/// <param name="u">Result website url</param>
/// <param name="rk">Result website relevant keywords</param>
/// <param name="irk">Result website irrelevant keywords</param>

 result::result(const std::string& n, const std::string& u, std::vector<std::string>&& rk, std::vector<std::string>&& irk)
	: name_(n), url_(u), relevant_keywords_(std::move(rk)), irrelevant_keywords_(std::move(irk))
{
}

/// <summary>
/// Returns the result website name
/// </summary>

 std::string result::get_name() const { return name_; }

/// <summary>
/// Sets the result website name
/// </summary>
/// <param name="n">The result website name to set</param>

 void result::set_name(const std::string& n) { name_ = n; }

/// <summary>
/// Returns the result website URL
/// </summary>

 std::string result::get_url() const { return url_; }

/// <summary>
/// Sets the result website URL
/// </summary>
/// <param name="u">The result website URL to set</param>

 void result::set_url(const std::string& u) { url_ = u; }

/// <summary>
/// Gets the result rank
/// </summary>
/// <returns>The result rank</returns>

 double result::get_score() const { return score_; }

/// <summary>
/// Sets the result rank
/// </summary>
/// <param name="rank">The new result rank</param>

 void result::set_score(const double score) { score_ = score; }

/// <summary>
/// Returns the result website relevant keywords
/// </summary>

 std::vector<std::string> result::get_relevant_keywords() const { return relevant_keywords_; }

/// <summary>
/// Adds a relevant keyword to the result
/// </summary>
/// <param name="keyword">The relevant keyword to add</param>

 void result::add_relevant_keyword(const std::string& keyword) { relevant_keywords_.push_back(keyword); }

/// <summary>
/// Sets the result website relevant keywords
/// </summary>
/// <param name="rk">The vector of relevant keywords to set</param>

 void result::set_relevant_keywords(std::vector<std::string>&& rk) { relevant_keywords_ = std::move(rk); }

/// <summary>
/// Returns the result website irrelevant keywords
/// </summary>

 std::vector<std::string> result::get_irrelevant_keywords() const { return irrelevant_keywords_; }

/// <summary>
/// Adds an irrelevant keyword to the result
/// </summary>
/// <param name="keyword">The irrelevant keyword to add</param>

 void result::add_irrelevant_keyword(const std::string& keyword) { irrelevant_keywords_.push_back(keyword); }

/// <summary>
/// Sets the result website irrelevant keywords
/// </summary>
/// <param name="irk">The vector of irrelevant keywords to set</param>

 void result::set_irrelevant_keywords(std::vector<std::string>&& irk) { irrelevant_keywords_ = std::move(irk); }
