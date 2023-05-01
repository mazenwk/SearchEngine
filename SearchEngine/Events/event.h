#pragma once

#include <vector>

#include "subject.h"
#include "observer.h"

class event : public subject {
private:
	std::vector<observer*> observers;

public:
	void attach(observer* observer) override {
		observers.push_back(observer);
	}

	void detach(observer* observer) override {
		observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
	}

	void notify() override {
		for (observer* observer : observers) {
			observer->update();
		}
	}

	// Trigger the event
	void trigger() {
		notify();
	}
};

