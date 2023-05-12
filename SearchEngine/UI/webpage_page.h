#pragma once
#include "../Models/webpage.h"

#include "page.h"

class webpage_page : page
{
public:
	webpage_page(const webpage& page);

	void display();

private:
	webpage page_;
};

