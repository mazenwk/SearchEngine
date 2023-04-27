#include "models/webpage.h"
#include "models/web_graph.h"

#include "utilities/initializer.h"

#include "ui/main_page.h"
#include "ui/results_page.h"


int main()
{
	// TOOD: Check files existence before launching

	auto wps = initializer::initalize_webpages();
	auto wg = initializer::initialize_web_graph(wps);

	auto mp = main_page();
	mp.display();
	auto query = mp.get_search();

	auto rp = results_page(wg);
	rp.search(query);

	return 0;
}