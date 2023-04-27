#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

namespace files_manager {
	/// <summary>
	/// Reads the given CSV file and returns its data formatted as a 2D vector
	/// </summary>
	/// <param name="file_name">The CSV file name to read</param>
	/// <returns>The data inside the CSV file formatted as a 2D vector where the first column is the first column in the CSV file</returns>
	static std::vector<std::vector<std::string>> read_csv_file(std::string file_name)
	{
		std::vector<std::vector<std::string>> data;

		std::fstream file(file_name, std::ios::in);
		if (file.is_open())
		{
			std::string line;
			std::vector<std::string> current_row;

			while (std::getline(file, line))
			{
				current_row.clear();

				std::stringstream str(line);

				std::string word;
				while (std::getline(str, word, ','))
					current_row.push_back(word);

				data.push_back(current_row);
			}
		}

		return data;
	}
}

