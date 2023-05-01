#pragma once
#include "observer.h"

/// <summary>
/// Subject interface. Notifies observers of a change by raising an event
/// </summary>
class subject {
public:
	virtual ~subject() {}
	virtual void attach(observer* observer) = 0;
	virtual void detach(observer* observer) = 0;
	virtual void notify() = 0;
};

