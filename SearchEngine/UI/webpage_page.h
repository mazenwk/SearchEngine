#pragma once
#include "../Models/webpage.h"

#include "page.h"

class webpage_page : page
{
public:
	webpage_page(const webpage& page) : page_(page) { }

	void display() {
		clear_page();
		auto name = page_.get_name();
		cout_stylized_word(name);

		std::cout << "\n\n\nType b and press enter to go back\n";
	}

private:
	webpage page_;
};

