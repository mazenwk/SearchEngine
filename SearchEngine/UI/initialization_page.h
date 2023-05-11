#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "page.h";

class initialization_page : page
{
public:
	void display() {
		std::string warning = "Please ensure console width is at least 120 wide";
		int line_width = 120 - warning.size() - 2;

		display_vertical_spacing(14);
		std::cout << "|";
		display_horizontal_line(line_width / 2);
		std::cout << warning;
		display_horizontal_line(line_width / 2);
		std::cout << "|";
		std::cout << '\n';

		display_loading_bar();

		while (true) {
			set_cursor_pos(60, 17);
			char c = std::cin.get();  // Read a character from the input

			if (c == '\n') {
				// Enter key was pressed
				break;
			}
		}

		clear_page();
	}

private:
	void display_horizontal_line(int length) {
		for (size_t i = 0; i < length; i++)
		{
			std::cout << "-";
		}
	}

	void display_horizontal_spacing(int length) {
		for (size_t i = 0; i < length; i++)
		{
			std::cout << " ";
		}
	}

	void display_vertical_spacing(int length) {
		for (size_t i = 0; i < length; i++)
		{
			std::cout << "\n";
		}
	}

	void display_loading_bar() {
		cout_centered("Loading");
		std::cout << "[";
		for (int i = 0; i < 118; ++i) {
			std::cout << " ";
		}

		std::cout << "]";

		for (int i = 1; i <= 118; ++i) {
			set_cursor_pos(i, 16);
			std::cout << "=";
			std::this_thread::sleep_for(std::chrono::milliseconds(25));
		}
	}
};

