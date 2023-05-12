#pragma once
#include <algorithm>
#include<vector>
#include <unordered_set>
#include<string>
#include <sstream>

/// <summary>
/// The webpage class. Contains the info of a webpage such as its URl and keywords
/// </summary>
class webpage
{
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	webpage() = default;

	/// <summary>
	/// Default parameterized constructor
	/// </summary>
	/// <param name="u">The webpage URL</param>
	explicit webpage(const std::string& u) : url_(u) {}

	/// <summary>
	/// Checks whether the given webpage is equal to the current one or not based on the URL
	/// </summary>
	/// <param name="page">The webpage to compare to</param>
	/// <returns>True if they are the same, false otherwise</returns>
	bool operator==(const webpage& page)
	{
		return url_ == page.url_;
	}

	/// <summary>
	/// Checks whether the given webpage is not equal to the current one or not based on the URL
	/// </summary>
	/// <param name="page">The webpage to compare to</param>
	/// <returns>True if they are the not same, false otherwise</returns>
	bool operator!=(const webpage& page) {
		return url_ != page.url_;
	}

	/// <summary>
	/// Gets the name of the webpage.
	/// </summary>
	/// <returns>A reference to the name string.</returns>
	const std::string& get_name() const { return name_; }

	/// <summary>
	/// Sets the name of the webpage.
	/// </summary>
	/// <param name="name">The new name for the webpage.</param>
	void set_name(const std::string& name) { name_ = name; }

	/// <summary>
	/// Gets the URL of the webpage.
	/// </summary>
	/// <returns>A reference to the URL string.</returns>
	const std::string& get_url() const { return url_; }

	/// <summary>
	/// Sets the URL of the webpage.
	/// </summary>
	/// <param name="url">The new URL for the webpage.</param>
	void set_url(const std::string& url) { url_ = url; }

	/// <summary>
	/// Gets the number of impressions of the webpage.
	/// </summary>
	/// <returns>The number of impressions.</returns>
	int get_impressions() const { return impressions_; }

	/// <summary>
	/// Sets the number of impressions of the webpage.
	/// </summary>
	/// <param name="impressions">The new number of impressions.</param>
	void set_impressions(int impressions) { impressions_ = impressions; }

	/// <summary>
	/// Gets a reference to the vector of keywords associated with the webpage.
	/// </summary>
	/// <returns>A reference to the vector of keywords.</returns>
	const std::vector<std::string>& get_keywords() const { return keywords_; }

	/// <summary>
	/// Adds a new keyword to the vector of keywords associated with the webpage.
	/// </summary>
	/// <param name="keyword">The new keyword to add.</param>
	void add_keyword(const std::string& keyword) { keywords_.push_back(keyword); }

	/// <summary>
	/// Sets the vector of keywords associated with the webpage.
	/// </summary>
	/// <param name="keywords">The vector of keywords to set.</param>
	void set_keywords(const std::vector<std::string>& keywords) { keywords_ = keywords; }

	/// <summary>
	/// Gets a reference to the vector of links contained in the webpage.
	/// </summary>
	/// <returns>A reference to the vector of links.</returns>
	const std::vector<std::string>& get_links() const { return links_; }

	/// <summary>
	/// Adds a new link to the vector of links contained in the webpage.
	/// </summary>
	/// <param name="link">The new link to add.</param>
	void add_link(const std::string& link) { links_.push_back(link); }

	/// <summary>
	/// Sets the vector of links contained in the webpage.
	/// </summary>
	/// <param name="links">The vector of links to set.</param>
	void set_links(const std::vector<std::string>& links) { links_ = links; }

	/// <summary>
	/// The webpage rank
	/// </summary>
	/// <returns>The webpage rank. Used for sorting</returns>
	int get_webpage_rank() { return page_rank_; }

	/// <summary>
	/// Sets the webpage page rank
	/// </summary>
	/// <param name="rank">The new page rank</param>
	void set_webpage_rank(int rank) { page_rank_ = rank; }

	/// <summary>
	/// The webpage score
	/// </summary>
	/// <returns>The webpage score. Used for sorting</returns>
	int get_webpage_score() {}

private:
	/// <summary>
	/// The webpage name
	/// </summary>
	std::string name_;

	/// <summary>
	/// The webpage URL
	/// </summary>
	std::string url_;

	/// <summary>
	/// The webpage impressions
	/// </summary>
	int impressions_ = 0;

	/// <summary>
	/// The webpage rank
	/// </summary>
	int page_rank_ = 0;

	/// <summary>
	/// The webpage keywords
	/// </summary>
	std::vector<std::string> keywords_ = {};

	/// <summary>
	/// The links inside the webpage
	/// </summary>
	std::vector<std::string> links_ = {};
};

