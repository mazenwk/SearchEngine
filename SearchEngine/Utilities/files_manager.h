#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class files_manager {
public:
	/// <summary>
	/// Reads the given CSV file and returns its data formatted as a 2D vector
	/// </summary>
	/// <param name="file_name">The CSV file name to read</param>
	/// <returns>The data inside the CSV file formatted as a 2D vector where the first column is the first column in the CSV file</returns>
	static std::vector<std::vector<std::string>> read_csv_file(const std::string& file_name);

	static void save_to_csv(std::string file_name, std::string data);
};