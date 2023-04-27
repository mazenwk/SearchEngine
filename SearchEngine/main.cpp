#include "models/webpage.h"
#include "models/web_graph.h"

#include "utilities/initializer.h"
#include "utilities/search_engine.h"

#include "ui/main_page.h"
#include "ui/results_page.h"


int main()
{
	// TOOD: Check files existence before launching
	/* TODO
	Consider adding support for different types of queries.
	For example, you could allow users to search for specific keywords, phrases, or even entire sentences.
	You could also allow users to filter results by various criteria such as date, relevance, or popularity.*/

	auto wps = initializer::initalize_webpages();
	auto wg = initializer::initialize_web_graph(wps);
	search_engine::set_web_graph(wg);

	auto mp = main_page();
	mp.display();
	auto query = mp.get_search();

	auto rp = results_page();
	rp.search(query);

	return 0;
}