#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

namespace files_manager
{
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
