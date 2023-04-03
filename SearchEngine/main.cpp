#include <iostream>

#include "loading_page.h"

int main()
{
	auto lp = loading_page();
	lp.display();
	lp.read_input();
}
