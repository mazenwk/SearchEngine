#include "main_page.h"
#include "files_manager.h"
#include "results_page.h"
#include "web_graph.h"
#include <iostream>

void printGraph(web_graph graph)
{
	for (size_t i = 0; i < graph.nodes.size(); i++)
	{
		std::cout << "\n Adjacency list of vertex " << i << "\n" << graph.nodes[i].value << ' ';

		for (auto x : graph.nodes[i].edges)
			std::cout << "-> " << x.value;
		std::cout << std::endl;
	}
}

int main()
{
	web_graph wg;

	auto data = files_manager::read_csv_file("websites.csv");

	for (size_t i = 0; i < data.size(); i++)
	{
		wg.add_edge(data[i][0], data[i][1]);
	}

	printGraph(wg);

	return 0;

	auto mp = main_page();
	mp.display();
	auto query = mp.get_search();

	auto rp = results_page(query);
	rp.display();

	return 0;
}