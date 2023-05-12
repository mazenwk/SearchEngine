#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "page.h"
#include "initialization_page.h"

/// <summary>
/// Displays the initialization page
/// </summary>

 void initialization_page::display() {
	std::string warning = "Please ensure console width is at least 120 wide";
	int line_width = 120 - static_cast<int>(warning.size()) - 2;

	display_vertical_spacing(14);
	std::cout << "|";
	display_horizontal_line(line_width / 2);
	std::cout << warning;
	display_horizontal_line(line_width / 2);
	std::cout << "|";
	std::cout << '\n';

	//display_loading_bar();
	display_warning();
	std::cout << "\n";

	cout_centered("Press enter to continue");
	while (true) {
		set_cursor_pos(60, 18);
		char c = std::cin.get();  // Read a character from the input

		if (c == '\n') {
			// Enter key was pressed
			break;
		}
	}

	clear_page();
}

/// <summary>
/// Displays the horizontal line
/// </summary>
/// <param name="length">Line length</param>

 void initialization_page::display_horizontal_line(int length) {
	for (size_t i = 0; i < length; i++)
	{
		std::cout << "-";
	}
}

/// <summary>
/// Displays horizontal spacing
/// </summary>
/// <param name="length">Spacing length</param>

 void initialization_page::display_horizontal_spacing(int length) {
	for (size_t i = 0; i < length; i++)
	{
		std::cout << " ";
	}
}

/// <summary>
/// Displays vertical spacing
/// </summary>
/// <param name="length">Spacing length</param>

 void initialization_page::display_vertical_spacing(int length) {
	for (size_t i = 0; i < length; i++)
	{
		std::cout << "\n";
	}
}

/// <summary>
/// Displays loadin bar
/// </summary>

 void initialization_page::display_loading_bar() {
	//cout_centered("Loading");
	std::cout << "[";
	for (int i = 0; i < 118; ++i) {
		std::cout << " ";
	}

	std::cout << "]";

	for (int i = 1; i <= 118; ++i) {
		set_cursor_pos(i, 15);
		std::cout << "=";
		std::this_thread::sleep_for(std::chrono::milliseconds(15));
	}
}

/// <summary>
/// Displays warnings centered
/// </summary>

 void initialization_page::display_warning()
{
	// todo: fix to work on *inuxes
	cout_centered("WARNING: THIS APP ONLY WORKS ON WINDOWS");
}
