#pragma once
/// <summary>
/// Observer interface. Calls update() when a subject raises an event
/// </summary>
class observer {
public:
	virtual ~observer() {}
	virtual void update() = 0;
};

