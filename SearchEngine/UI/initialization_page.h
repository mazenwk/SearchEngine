#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "page.h"

class initialization_page : page
{
public:
	/// <summary>
	/// Displays the initialization page
	/// </summary>
	void display();

private:
	/// <summary>
	/// Displays the horizontal line
	/// </summary>
	/// <param name="length">Line length</param>
	void display_horizontal_line(int length);

	/// <summary>
	/// Displays horizontal spacing
	/// </summary>
	/// <param name="length">Spacing length</param>
	void display_horizontal_spacing(int length);

	/// <summary>
	/// Displays vertical spacing
	/// </summary>
	/// <param name="length">Spacing length</param>
	void display_vertical_spacing(int length);

	/// <summary>
	/// Displays loadin bar
	/// </summary>
	void display_loading_bar();

	/// <summary>
	/// Displays warnings centered
	/// </summary>
	void display_warning();
};

