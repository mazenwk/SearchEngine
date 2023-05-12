#include "models/webpage.h"
#include "models/web_graph.h"

#include "utilities/initializer.h"
#include "utilities/search_engine.h"

#include "ui/main_page.h"
#include "ui/results_page.h"
#include "ui/initialization_page.h"

int main()
{
	auto wps = initializer::initalize_webpages();
	auto wg = initializer::initialize_web_graph(wps);
	initializer::load_data(wg);
	wg.calculate_page_ranks(2);
	search_engine::set_web_graph(wg);

	auto ip = initialization_page();
	ip.display();


	auto mp = main_page();
	mp.display();
	auto query = mp.get_search_query();

	auto rp = results_page();
	rp.search(query);

	initializer::save_data(search_engine::get_web_graph());
	return EXIT_SUCCESS;
}
