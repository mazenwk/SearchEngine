#include <algorithm>
#include<vector>
#include <unordered_set>
#include<string>
#include <sstream>

#include "webpage.h"

/// <summary>
/// Default parameterized constructor
/// </summary>
/// <param name="u">The webpage URL</param>

webpage::webpage(const std::string& u) : url_(u) {}

/// <summary>
/// Gets the name of the webpage.
/// </summary>
/// <returns>A reference to the name string.</returns>

const std::string& webpage::get_name() const { return name_; }

/// <summary>
/// Sets the name of the webpage.
/// </summary>
/// <param name="name">The new name for the webpage.</param>

void webpage::set_name(const std::string& name) { name_ = name; }

/// <summary>
/// Gets the URL of the webpage.
/// </summary>
/// <returns>A reference to the URL string.</returns>

const std::string& webpage::get_url() const { return url_; }

/// <summary>
/// Sets the URL of the webpage.
/// </summary>
/// <param name="url">The new URL for the webpage.</param>

void webpage::set_url(const std::string& url) { url_ = url; }

/// <summary>
/// Gets the number of impressions of the webpage.
/// </summary>
/// <returns>The number of impressions.</returns>

int webpage::get_impressions() const { return impressions_; }

/// <summary>
/// Sets the number of impressions of the webpage.
/// </summary>
/// <param name="impressions">The new number of impressions.</param>

void webpage::set_impressions(int impressions) { impressions_ = impressions; }

/// <summary>
/// Incremenets the number of impressions of the webpage.
/// </summary>

void webpage::increment_impressions() { impressions_++; }

/// <summary>
/// Gets the number of click throughs of the webpage.
/// </summary>
/// <returns>The number of click throughs.</returns>

int webpage::get_click_throughs() const { return click_throughs_; }

/// <summary>
/// Sets the number of click throughs of the webpage.
/// </summary>
/// <param name="impressions">The new number of click throughs.</param>

void webpage::set_click_throughs(int click_throughs) { click_throughs_ = click_throughs; }

/// <summary>
/// Incremenets the number of click throughs of the webpage.
/// </summary>

void webpage::increment_click_throughs() { click_throughs_++; }

/// <summary>
/// The webpage rank
/// </summary>
/// <returns>The webpage rank. Used for sorting</returns>

int webpage::get_webpage_rank() { return page_rank_; }

/// <summary>
/// Sets the webpage page rank
/// </summary>
/// <param name="rank">The new page rank</param>

void webpage::set_webpage_rank(int rank) { page_rank_ = rank; }

double webpage::get_CTR() {
	return (click_throughs_ / impressions_) * 100;
}

/// <summary>
/// The webpage score
/// </summary>
/// <returns>The webpage score. Used for sorting</returns>

double webpage::get_webpage_score() {
	return (0.4 * page_rank_ + (((1 - ((0.1 * impressions_) / (1 + (0.1 * impressions_)))) * page_rank_) + (((0.1 * impressions_) / (1 + (0.1 * impressions_))) * get_CTR())) * 0.6);
}

/// <summary>
/// Gets a reference to the vector of keywords associated with the webpage.
/// </summary>
/// <returns>A reference to the vector of keywords.</returns>

const std::vector<std::string>& webpage::get_keywords() const { return keywords_; }

/// <summary>
/// Adds a new keyword to the vector of keywords associated with the webpage.
/// </summary>
/// <param name="keyword">The new keyword to add.</param>

void webpage::add_keyword(const std::string& keyword) { keywords_.push_back(keyword); }

/// <summary>
/// Sets the vector of keywords associated with the webpage.
/// </summary>
/// <param name="keywords">The vector of keywords to set.</param>

void webpage::set_keywords(const std::vector<std::string>& keywords) { keywords_ = keywords; }

/// <summary>
/// Gets a reference to the vector of links contained in the webpage.
/// </summary>
/// <returns>A reference to the vector of links.</returns>

const std::vector<std::string>& webpage::get_links() const { return links_; }

/// <summary>
/// Adds a new link to the vector of links contained in the webpage.
/// </summary>
/// <param name="link">The new link to add.</param>

void webpage::add_link(const std::string& link) { links_.push_back(link); }

/// <summary>
/// Sets the vector of links contained in the webpage.
/// </summary>
/// <param name="links">The vector of links to set.</param>

void webpage::set_links(const std::vector<std::string>& links) { links_ = links; }
