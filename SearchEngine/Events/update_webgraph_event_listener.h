#pragma once

#include <fstream>

#include "observer.h"

class update_webgraph_event_listener : public observer
{
	void update() override {
		std::ofstream ofs("test.txt", std::ios_base::app);
		ofs << "File was written to at " << time(0) << std::endl;
		ofs.close();
	}
};

