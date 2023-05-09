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
	void cout_centered(std::string text)
	{
		// This function will only center the text if it is less than the length of the console!
		// Otherwise it will just display it on the console without centering it.

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);													 // Get the console handle.
		PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
		GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);													 // Saves the console screen info into the lpScreenInfo pointer.
		COORD NewSBSize = lpScreenInfo->dwSize;																			 // Gets the size of the screen
		if (NewSBSize.X > text.size())
		{
			int newpos = static_cast<int>((NewSBSize.X - text.size()) / 2); // Calculate the number of spaces to center the specific text.
			for (int i = 0; i < newpos; i++)
				std::cout << " "; // Prints the spaces
		}
		std::cout << text << std::endl; // Prints the text centered :]
	}

	/// <summary>
	/// Outputs the input formatted to be bold in the console
	/// </summary>
	/// <param name="text">The text to output</param>
	/// <param name="do_endl">Whether or not to end the line. True by default</param>
	/// <remarks> Referenced from: https://stackoverflow.com/a/29997157 </remarks>
	void cout_bold(std::string text, bool do_endl = true)
	{
		char esc_char = 27; // the decimal code for escape character is 27
		std::cout << esc_char << "[1m" << text << esc_char << "[0m" << (do_endl ? "\n" : "");
	}

	/// <summary>
	/// Outputs the input formatted to be colored in the console
	/// </summary>
	/// <param name="text">The text to output</param>
	/// <param name="color_code">The color to output the text in. White (15) by default</param>
	/// <param name="do_endl">Whether or not to end the line. True by default</param>
	/// <remarks> Referenced from: https://stackoverflow.com/a/4053879 </remarks>
	void cout_colored(std::string text, color_code code = color_code::WHITE, bool do_endl = true)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		// pick the colorattribute k you want
		SetConsoleTextAttribute(hConsole, (short)code);
		std::cout << text << (do_endl ? "\n" : "");

		// Reset the color
		SetConsoleTextAttribute(hConsole, 15);
	}

	/// <summary>
	/// Clears the page (console)
	/// </summary>
	/// <remarks> Referenced from: https://stackoverflow.com/a/6487534 </remarks>
	void clear_page()
	{
		COORD topLeft = { 0, 0 };
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;

		GetConsoleScreenBufferInfo(console, &screen);
		FillConsoleOutputCharacterA(
			console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
		FillConsoleOutputAttribute(
			console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
			screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
		SetConsoleCursorPosition(console, topLeft);
	}

	/// <summary>
	/// Sets the cursor position to the given coordinates
	/// </summary>
	/// <param name="x">Column number</param>
	/// <param name="y">Row number</param>
	/// <remarks> Referenced from: https://stackoverflow.com/a/6487534 </remarks>
	void set_cursor_pos(short x, short y)
	{
		COORD pos = { x, y };
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);
	}

	/// <summary>
	/// Outputs a stylized word to the console with a custom font
	/// </summary>
	/// <param name="word">The word to output</param>
	void cout_stylized_word(const std::string& word) {
		for (const char letter : word) {
			auto stylized_letter = get_stylized_letter(letter);
			for (const auto line : stylized_letter) {
				std::cout << line << '\n';
			}
		}
	}

private:
	/// <summary>
	/// Gets the stylized equivalent of a letter
	/// </summary>
	/// <param name="c">The letter to get the stylized equivalent of</param>
	/// <returns></returns>
	std::vector<std::string> get_stylized_letter(const char& c) {
		std::vector<std::string> letters;

		switch (toupper(c)) {
		case 'A':
			letters = {
				"    _      ",
				"   /_\\     ",
				"  / _ \\    ",
				" /_/ \\_\\   "
			};
			break;
		case 'B':
			break;
		case 'C':
			break;
		case 'D':
			break;
		case 'E':
			break;
		case 'F':
			break;
		case 'G':
			break;
		case 'H':
			break;
		case 'I':
			break;
		case 'J':
			break;
		case 'K':
			break;
		case 'L':
			break;
		case 'M':
			break;
		case 'N':
			break;
		case 'O':
			break;
		case 'P':
			break;
		case 'Q':
			break;
		case 'R':
			break;
		case 'S':
			break;
		case 'T':
			break;
		case 'U':
			break;
		case 'V':
			break;
		case 'W':
			break;
		case 'X':
			break;
		case 'Y':
			break;
		case 'Z':
			break;
		}

		return letters;
	}
};
