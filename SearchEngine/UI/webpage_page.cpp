#include "../Models/webpage.h"

#include "page.h"
#include "webpage_page.h"

 webpage_page::webpage_page(const webpage& page) : page_(page) { }

 void webpage_page::display() {
	clear_page();
	cout_stylized_word(page_.get_name());
	std::cout << "_________________________________________________________________________________________________________________\n";

	std::string keywords = "";
	for (const auto& keyword : page_.get_keywords()) {
		keywords += keyword + "\t";
	}
	std::cout << keywords;

	std::cout << "\n\nType b and press enter to go back";
	std::cout << "\n";
}
