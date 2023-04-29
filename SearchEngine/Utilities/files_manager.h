#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace files_manager {
	/// <summary>
	/// Reads the given CSV file and returns its data formatted as a 2D vector
	/// </summary>
	/// <param name="file_name">The CSV file name to read</param>
	/// <returns>The data inside the CSV file formatted as a 2D vector where the first column is the first column in the CSV file</returns>
	static std::vector<std::vector<std::string>> read_csv_file(const std::string& file_name)
	{
		std::vector<std::vector<std::string>> data;

		std::ifstream file(file_name);
		if (!file.is_open())
		{
			// TODO: Custom exceptions
			std::cerr << "Cannot open file: " << file_name << '\n';
			return data;
		}

		std::string line;
		while (std::getline(file, line))
		{
			std::vector<std::string> current_row;
			std::stringstream str(line);
			std::string word;

			while (std::getline(str, word, ','))
			{
				current_row.emplace_back(word);
			}

			data.emplace_back(std::move(current_row));
		}

		return data;
	}
}

