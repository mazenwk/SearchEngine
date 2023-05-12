#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "files_manager.h"

/// <summary>
/// Reads the given CSV file and returns its data formatted as a 2D vector
/// </summary>
/// <param name="file_name">The CSV file name to read</param>
/// <returns>The data inside the CSV file formatted as a 2D vector where the first column is the first column in the CSV file</returns>

 std::vector<std::vector<std::string>> files_manager::read_csv_file(const std::string& file_name) {
	std::vector<std::vector<std::string>> data;

	std::ifstream file(file_name);
	if (!file.is_open())
	{
		// TODO: Custom exceptions
		if (file_name != "resources/data.csv") {
			std::cerr << "Cannot open file: " << file_name << '\n';
		}
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

 void files_manager::save_to_csv(std::string file_name, std::string data) {
	std::ofstream file(file_name);

	if (file.is_open()) {
		file << data;
		file.close();
	}
	else {
		std::cerr << "Failed to open the file.\n";
	}
}
