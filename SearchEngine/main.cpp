#include "models/webpage.h"
#include "models/web_graph.h"

#include "utilities/initializer.h"
#include "utilities/search_engine.h"

#include "ui/main_page.h"
#include "ui/results_page.h"
#include "ui/initialization_page.h"

#include "events/event.h"
#include "events/update_webgraph_event_listener.h"

#include <iostream>
void test() {
	auto a = webpage("a");
	auto b = webpage("b");
	auto c = webpage("c");
	auto d = webpage("d");

	web_graph wg = web_graph();

	wg.add_webpage_node(a);
	wg.add_webpage_node(b);
	wg.add_webpage_node(c);
	wg.add_webpage_node(d);

	wg.add_webpage_edge(a.get_url(), b.get_url());
	wg.add_webpage_edge(a.get_url(), c.get_url());

	wg.add_webpage_edge(c.get_url(), a.get_url());
	wg.add_webpage_edge(c.get_url(), b.get_url());
	wg.add_webpage_edge(c.get_url(), d.get_url());

	wg.add_webpage_edge(b.get_url(), d.get_url());

	wg.add_webpage_edge(d.get_url(), c.get_url());

	wg.calculate_page_ranks(2);

	for (const auto& kvp : wg.get_nodes_map()) {
		auto node = kvp.second;
		auto page = node.get_page();

		std::cout << page.get_url() << ":" << page.get_webpage_rank() << '\n';
	}
}

void run();

int main()
{
	//test();

	run();
	return EXIT_SUCCESS;
}

void run() {
	// I don't remember why i implemented an events class. I had an idea and next day i forgot about it
	//event update_webgrapgh_event;
	//update_webgraph_event_listener update_listener;
	//update_webgrapgh_event.attach(&update_listener);
	//update_webgrapgh_event.trigger();

	// TOOD: Check files existence before launching

	auto wps = initializer::initalize_webpages();
	auto wg = initializer::initialize_web_graph(wps);
	wg.calculate_page_ranks(2);
	wg.print_web_graph();
	search_engine::set_web_graph(wg);

	auto ip = initialization_page();
	ip.display();


	auto mp = main_page();
	mp.display();
	auto query = mp.get_search_query();

	auto rp = results_page();
	rp.search(query);
}