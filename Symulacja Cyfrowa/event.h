#ifndef EVENT_H
#define EVENT_H
#include<functional>
#include<set>
#include<iostream>
#include"network.h"

class Event
{
public:
	Event(float event_time, Network* network);
	float get_time();
	void virtual execute() = 0;
	bool operator<(Event*);
	bool operator>(Event*);
	bool operator==(Event*);
	
	typedef std::multiset<Event*, std::function<bool(Event*, Event*)>> EventList;	
protected:
	float event_time;
	Network* network;
};

#endif