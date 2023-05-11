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
		std::vector<std::vector<std::string>> stylized_word;
		for (const char letter : word) {
			stylized_word.push_back(get_stylized_letter(letter));
		}

		// Transpose the array
		std::vector<std::vector<std::string>> transposed_word;
		for (size_t col = 0; col < stylized_word[col].size(); ++col) {
			std::vector<std::string> column;
			for (size_t row = 0; row < stylized_word.size(); ++row) {
				column.push_back(stylized_word[row][col]);
			}
			transposed_word.push_back(column);
		}

		// Print each column
		for (const auto& column : transposed_word) {
			for (const auto& element : column) {
				std::cout << element << ' ';
			}
			std::cout << std::endl;
		}
	}

private:
	/// <summary>
	/// Gets the stylized equivalent of a letter
	/// </summary>
	/// <param name="c">The letter to get the stylized equivalent of</param>
	/// <returns></returns>
	std::vector<std::string> get_stylized_letter(const char& c) {
		std::vector<std::string> characters;

		switch (toupper(c)) {
		case 'A':
			characters = {
				"    _   ",
				"   /_\\  ",
				"  / _ \\ ",
				" /_/ \\_\\"
			};
			break;
		case 'B':
			characters = {
				"  ___ ",
				" | _ )",
				" | _ \\",
				" |___/",
			};
			break;
		case 'C':
			characters = {
				"   ___ ",
				"  / __|",
				" | (__ ",
				"  \\___|",
			};
			break;
		case 'D':
			characters = {
				"  ___  ",
				" |   \\ ",
				" | |) |",
				" |___/ ",
			};
			break;
		case 'E':
			characters = {
				"  ___  ",
				" | __| ",
				" | _|  ",
				" |___| ",
			};
			break;
		case 'F':
			characters = {
				"  ___ ",
				" | __|",
				" | _| ",
				" |_|  ",
			};
			break;
		case 'G':
			characters = {
				"    __ ",
				"  / __|",
				" | (_  ",
				"  \\___|",
			};
			break;
		case 'H':
			characters = {
				"  _  _ ",
				" | || |",
				" | __ |",
				" |_||_|",
			};
			break;
		case 'I':
			characters = {
				"  ___ ",
				" |_ _|",
				"  | | ",
				" |___|",
			};
			break;
		case 'J':
			characters = {
				"     _ ",
				"  _ | |",
				" | || |",
				"  \\__/ ",
			};
			break;
		case 'K':
			characters = {
				"  _  __",
				" | |/ /",
				" | ' < ",
				" |_|\\_\\",
			};
			break;
		case 'L':
			characters = {
				"  _    ",
				" | |   ",
				" | |__ ",
				" |____|",
			};
			break;
		case 'M':
			characters = {
				"  __  __ ",
				" |  \\/  |",
				" | |\\/| |",
				" |_|  |_|",
			};
			break;
		case 'N':
			characters = {
				"  _   _ ",
				" | \\ | |",
				" |  \\  |",
				" |_| \\_|",
			};
			break;
		case 'O':
			characters = {
				"   ___  ",
				"  / _ \\ ",
				" | (_) |",
				"  \\___/ ",
			};
			break;
		case 'P':
			characters = {
				"  ___ ",
				" | _ \\",
				" |  _/",
				" |_|  ",
			};
			break;
		case 'Q':
			characters = {
				"   ___  ",
				"  / _ \\ ",
				" | (_) |",
				"  \\__\\_\\",
			};
			break;
		case 'R':
			characters = {
				"  ___ ",
				" | _ \\",
				" |   /",
				" |_|_\\",
			};
			break;
		case 'S':
			characters = {
				"  ___ ",
				" / __|",
				" \\__ \\",
				" |___/",
			};
			break;
		case 'T':
			characters = {
				"  _____  ",
				" |_   _| ",
				"   | |   ",
				"   |_|   ",
			};
			break;
		case 'U':
			characters = {
				"  _   _ ",
				" | | | |",
				" | |_| |",
				"  \\___/ ",
			};
			break;
		case 'V':
			characters = {
				" _     _",
				" \\ \\ / /",
				"  \\ V / ",
				"   \\_/  ",
			};
			break;
		case 'W':
			characters = {
				"  _      __",
				" \\ \\    / /",
				"  \\ \\/\\/ / ",
				"   \\_/\\_/  ",
			};
			break;
		case 'X':
			characters = {
				" __  __",
				" \\ \\/ /",
				"  >  < ",
				" /_/\\_\\",
			};
			break;
		case 'Y':
			characters = {
				"  _   __",
				" \\ \\ / /",
				"  \\ V / ",
				"   |_|  ",
			};
			break;
		case 'Z':
			characters = {
				"  ___    ",
				" |_  /   ",
				"  / /    ",
				" /___|   "
			};
			break;
		case '1':
			characters = {
				"  _  ",
				" / | ",
				" | | ",
				" |_| "
			};
			break;
		case '2':
			characters = {
				"  ___  ",
				" |_  ) ",
				"  / /  ",
				" /___| "
			};
			break;
		case '3':
			characters = {
				"  ____ ",
				" |__ / ",
				"  |_ \\ ",
				" |___/ "
			};
			break;
		case '4':
			characters = {
				"  _ _   ",
				" | | |  ",
				" |_  _ |",
				"   |_|  "
			};
			break;
		case '5':
			characters = {
				"  ___  ",
				" | __| ",
				" |__ \\ ",
				" |___/ "
			};
			break;
		case '6':
			characters = {
				"   __  ",
				"  / /  ",
				" / _ \\ ",
				" \\___/ "
			};
			break;
		case '7':
			characters = {
				"  ____ ",
				" |__  |",
				"   / / ",
				"  /_/  "
			};
			break;
		case '8':
			characters = {
				"  ___  ",
				" ( _ ) ",
				" / _ \\ ",
				" \\___/ "
			};
			break;
		case '9':
			characters = {
				"  ___  ",
				" / _ \\ ",
				" \\_, / ",
				"  /_/  "
			};
			break;
		case '0':
			characters = {
				"   __  ",
				"  /  \\ ",
				" | () |",
				"  \\__/ "
			};
			break;
		case ' ':
			characters = {
				"  ",
				"  ",
				"  ",
				"  "
			};
			break;
		default:
			characters = {
				"????"
			};
		}

		return characters;
	}
};
