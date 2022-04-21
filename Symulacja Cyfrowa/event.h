#ifndef EVENT_H
#define EVENT_H
#include<functional>
#include<set>
#include<chrono>
#include"network.h"

class Event
{
public:
	Event(std::chrono::high_resolution_clock::time_point e_t, Network* n);
	std::chrono::high_resolution_clock::time_point get_time();
	void virtual execute() = 0;
	bool operator<(Event*);
	bool operator>(Event*);
	bool operator==(Event*);
	
	std::multiset<Event*> event_list;	
protected:
	std::chrono::high_resolution_clock::time_point event_time;
	Network* network;
};

#endif