#ifndef EVENT_H
#define EVENT_H
#include <functional>
#include <set>
#include <iostream>
#include "network.h"
#include <spdlog/spdlog.h>
#include <string>

class Event
{
public:
	Event(int event_time, Network* network);
	int get_time();
	void virtual Execute() = 0;

	typedef std::multiset<Event*, std::function<bool(Event*, Event*)>> EventList;	
protected:
	int event_time_;
	Network* network_;
};

#endif