#pragma once
#include "page.h"
#include "result.h"
#include "../models/web_graph.h"
#include <iostream>
#include <string>
#include <sstream>

class results_page : public page
{
public:
	results_page(web_graph wg)
	{
		current_wg = wg;
	}

	void search(const std::string query) {
		clear_page();
		current_query = query;

		auto rs = { result("Result 1", { "word 1", "kw 1" }), result("Result 2", { "kw 2", "word 2" }) };

		std::vector<result> results;

		for (size_t i = 0; i < current_wg.nodes.size(); i++)
		{
			auto page = current_wg.nodes[i].page;
			results.push_back(result(page.url, page.keywords));
		}

		auto keywords = split_query(current_query);

		display(current_query, results, keywords);
	}

	void display(const std::string query, std::vector<result> results, std::vector<std::string> keywords)
	{
		display_logo();
		display_searchbar(query);
		display_toolbar(5);

		for (size_t i = 0; i < results.size(); i++)
		{
			results[i].display(i + 1, keywords);
		}

		get_input();
	}

private:
	web_graph current_wg;
	std::string current_query;

	std::vector<std::string> split_query(std::string query) {

		std::vector<std::string> split_query;
		std::stringstream ss(query);
		std::string s;

		while (std::getline(ss, s, ' ')) {
			split_query.push_back(s);
		}

		return split_query;
	}

	void display_logo()
	{
		std::cout << ("   __________  ____\n");
		std::cout << ("  / ____/ __ \\/ __ )\n");
		std::cout << (" / / __/ / / / __  |\n");
		std::cout << ("/ /_/ / /_/ / /_/ /\n");
		std::cout << ("\\____/\\____/_____/\n");
		std::cout << ("google  on  budget  \n");
	}

	void display_searchbar(std::string query = " ")
	{
		set_cursor_pos(25, 1);

		std::cout << (" _______________________________________________________________________________");

		set_cursor_pos(25, 2);
		std::cout << ("/                                                                               \\");

		set_cursor_pos(25, 3);
		std::cout << ("|                                                                               |");

		set_cursor_pos(25, 4);
		std::cout << ("\\_______________________________________________________________________________/");

		set_cursor_at_searchbar();
		std::cout << query;
	}

	void display_toolbar(int results_count = 0)
	{
		set_cursor_pos(0, 6);

		std::cout << ("-------------------------------------------------------------------------------------------------------------\n");
		if (results_count > 0)
		{
			std::cout << "[1-" << results_count << "] Select Result \t";
		}
		else
		{
			std::cout << "[0-0] Select Result \t";
		}

		std::cout << "[s] Search \t[n] Next Page\t[p] Previous Page\t[q] Quit\t[ ]\n";
		std::cout << ("-------------------------------------------------------------------------------------------------------------\n");
	}

	void get_input()
	{
		set_cursor_at_input();

		char c;
		std::cin >> c;

		switch (c)
		{
		case 's':
			set_cursor_at_searchbar();

			do {
				std::getline(std::cin, current_query);
			} while (current_query == "");

			search(current_query);
			break;
		case 'q':
			clear_page();
			exit(0);
			break;
		default:
			break;
		}
	}

	void set_cursor_at_searchbar() {
		set_cursor_pos(28, 3);
		std::cout << "                                                         ";
		set_cursor_pos(28, 3);
	}

	void set_cursor_at_input() {
		set_cursor_pos(97, 7);
		std::cout << " ";
		set_cursor_pos(97, 7);
	}
};
