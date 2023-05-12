#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

/// <summary>
/// Color codes for console
/// <remarks> Referenced from: https://stackoverflow.com/a/4053879</remarks>
/// </summary>
enum class color_code
{
	DARK_BLUE = 1,
	DARK_GREEN = 2,
	DARK_CYAN = 3,
	DARK_RED = 4,
	DARK_MAGENTA = 5,
	DARK_YELLOW = 6,
	DARK_WHITE = 7,
	DARK_GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	CYAN = 11,
	RED_ = 12,
	MAGENTA = 13,
	YELLOW = 14,
	WHITE = 15,
	BLACK = 16
};

/// <summary>
/// Abstract base page class
/// </summary>
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
	void cout_colored(std::string text, color_code code = color_code::WHITE, bool do_endl = true);

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
	void set_cursor_pos(short x, short y);

	/// <summary>
	/// Outputs a stylized word to the console with a custom font
	/// </summary>
	/// <param name="word">The word to output</param>
	void cout_stylized_word(const std::string& word);

private:
	/// <summary>
	/// Gets the stylized equivalent of a letter
	/// </summary>
	/// <param name="c">The letter to get the stylized equivalent of</param>
	/// <returns></returns>
	std::vector<std::string> get_stylized_letter(const char& c);
};
