#pragma once
#include <string>
#include <vector>


/// <summary>
/// The result class. Represents a singular search result and holds the result's info.
/// </summary>
class result
{
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	result() = default;

	/// <summary>
	/// Parameterized constructor. Creates a result with the info given
	/// </summary>
	/// <param name="n">Result website name</param>
	/// <param name="u">Result website url</param>
	/// <param name="rk">Result website relevant keywords</param>
	/// <param name="irk">Result website irrelevant keywords</param>
	result(const std::string& n, const std::string& u, std::vector<std::string>&& rk, std::vector<std::string>&& irk);

	/// <summary>
	/// Returns the result website name
	/// </summary>
	std::string get_name() const;

	/// <summary>
	/// Sets the result website name
	/// </summary>
	/// <param name="n">The result website name to set</param>
	void set_name(const std::string& n);

	/// <summary>
	/// Returns the result website URL
	/// </summary>
	std::string get_url() const;

	/// <summary>
	/// Sets the result website URL
	/// </summary>
	/// <param name="u">The result website URL to set</param>
	void set_url(const std::string& u);

	/// <summary>
	/// Gets the result rank
	/// </summary>
	/// <returns>The result rank</returns>
	double get_score() const;

	/// <summary>
	/// Sets the result rank
	/// </summary>
	/// <param name="rank">The new result rank</param>
	void set_score(const double score);

	/// <summary>
	/// Returns the result website relevant keywords
	/// </summary>
	std::vector<std::string> get_relevant_keywords() const;

	/// <summary>
	/// Adds a relevant keyword to the result
	/// </summary>
	/// <param name="keyword">The relevant keyword to add</param>
	void add_relevant_keyword(const std::string& keyword);

	/// <summary>
	/// Sets the result website relevant keywords
	/// </summary>
	/// <param name="rk">The vector of relevant keywords to set</param>
	void set_relevant_keywords(std::vector<std::string>&& rk);

	/// <summary>
	/// Returns the result website irrelevant keywords
	/// </summary>
	std::vector<std::string> get_irrelevant_keywords() const;

	/// <summary>
	/// Adds an irrelevant keyword to the result
	/// </summary>
	/// <param name="keyword">The irrelevant keyword to add</param>
	void add_irrelevant_keyword(const std::string& keyword);

	/// <summary>
	/// Sets the result website irrelevant keywords
	/// </summary>
	/// <param name="irk">The vector of irrelevant keywords to set</param>
	void set_irrelevant_keywords(std::vector<std::string>&& irk);

private:
	/// <summary>
	/// The result website name
	/// </summary>
	std::string name_{};

	/// <summary>
	/// The result website URL
	/// </summary>
	std::string url_{};

	/// <summary>
	/// The result rank
	/// </summary>
	double score_ = -1.0;

	/// <summary>
	/// The result website relevant keywords
	/// </summary>
	std::vector<std::string> relevant_keywords_{};

	/// <summary>
	/// The result website irrelevant keywords
	/// </summary>
	std::vector<std::string> irrelevant_keywords_{};
};