#pragma once
#include <windows.h>
#include <string>
#include <iostream>

class page
{
public:
	/// <summary>
	/// Outputs the input formatted to be centered in the console
	/// </summary>
	/// <param name="text">The text to output</param>
	/// <remarks> Referenced from: https://stackoverflow.com/a/66896669 </remarks>
	void cout_centered(std::string text);

	/// <summary>
	/// Outputs the input formatted to be bold in the console
	/// </summary>
	/// <param name="text">The text to output</param>
	/// <param name="do_endl">Whether or not to end the line. True by default</param>
	/// <remarks> Referenced from: https://stackoverflow.com/a/29997157 </remarks>
	void cout_bold(std::string text, bool do_endl = true);

	/// <summary>
	/// Outputs the input formatted to be colored in the console
	/// </summary>
	/// <param name="text">The text to output</param>
	/// <param name="color_code">The color to output the text in. White (15) by default</param>
	/// <param name="do_endl">Whether or not to end the line. True by default</param>
	/// <remarks> Referenced from: https://stackoverflow.com/a/4053879 </remarks>
	void cout_colored(std::string text, int color_code = 15, bool do_endl = true);

	/// <summary>
	/// Clears the page (console)
	/// </summary>
	/// <remarks> Referenced from: https://stackoverflow.com/a/6487534 </remarks>
	void clear_page();

	/// <summary>
	/// Sets the cursor position to the given coordinates
	/// </summary>
	/// <param name="x">Column number</param>
	/// <param name="y">Row number</param>
	/// <remarks> Referenced from: https://stackoverflow.com/a/6487534 </remarks>
	void set_cursor_pos(int x, int y);
};
