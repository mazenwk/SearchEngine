#include "page.h"

// https://stackoverflow.com/a/66896669

void page::cout_centered(std::string text)
{
	// This function will only center the text if it is less than the length of the console!
	// Otherwise it will just display it on the console without centering it.

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);													 // Get the console handle.
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);													 // Saves the console screen info into the lpScreenInfo pointer.
	COORD NewSBSize = lpScreenInfo->dwSize;																			 // Gets the size of the screen
	if (NewSBSize.X > text.size())
	{
		int newpos = ((NewSBSize.X - text.size()) / 2); // Calculate the number of spaces to center the specific text.
		for (int i = 0; i < newpos; i++)
			std::cout << " "; // Prints the spaces
	}
	std::cout << text << std::endl; // Prints the text centered :]
}

// https://stackoverflow.com/a/29997157

void page::cout_bold(std::string text, bool do_endl)
{
	char esc_char = 27; // the decimal code for escape character is 27
	std::cout << esc_char << "[1m" << text << esc_char << "[0m" << (do_endl ? "\n" : "");
}

// https://stackoverflow.com/a/4053879

void page::cout_colored(std::string text, int color_code, bool do_endl)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// pick the colorattribute k you want
	SetConsoleTextAttribute(hConsole, color_code);
	std::cout << text << (do_endl ? "\n" : "");

	// Reset the color
	SetConsoleTextAttribute(hConsole, 15);
}

// https://stackoverflow.com/a/6487534

void page::clear_page()
{
	COORD topLeft = {0, 0};
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

// https://stackoverflow.com/a/6487534

void page::set_cursor_pos(int x, int y)
{
	COORD pos = {x, y};
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}
