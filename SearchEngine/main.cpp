#include "models/webpage.h"
#include "models/web_graph.h"

#include "utilities/initializer.h"
#include "utilities/search_engine.h"

#include "ui/main_page.h"
#include "ui/results_page.h"
#include "ui/initialization_page.h"

#include "events/event.h"
#include "events/update_webgraph_event_listener.h"

int main()
{
	//auto m = main_page();
	//m.cout_stylized_word("ab");
	//return EXIT_SUCCESS;

	// I don't remember why i implemented an events class. I had an idea and next day i forgot about it
	//event update_webgrapgh_event;
	//update_webgraph_event_listener update_listener;

	//update_webgrapgh_event.attach(&update_listener);

	//update_webgrapgh_event.trigger();

	//return 0;

	// TOOD: Check files existence before launching
	/* TODO
	Consider adding support for different types of queries.
	For example, you could allow users to search for specific keywords, phrases, or even entire sentences.
	You could also allow users to filter results by various criteria such as date, relevance, or popularity.*/

	auto ip = initialization_page();
	ip.display();

	auto wps = initializer::initalize_webpages();
	auto wg = initializer::initialize_web_graph(wps);
	//wg.print_web_graph();
	search_engine::set_web_graph(wg);

	auto mp = main_page();
	mp.display();
	auto query = mp.get_search_query();

	auto rp = results_page();
	rp.search(query);

	return 0;
}