#include <iostream>

#include "main_page.h"
#include "results_page.h"

int main()
{
	auto mp = main_page();
	mp.display();
	auto query = mp.get_search();

	auto rp = results_page(query);
	rp.display();
}
