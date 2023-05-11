#pragma once
#include "../Models/webpage.h"

#include "page.h"

class webpage_page : page
{
public:
	webpage_page(const webpage& page) : page_(page) { }

	void display() {
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

private:
	webpage page_;
};

