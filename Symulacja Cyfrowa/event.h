#ifndef EVENT_H
#define EVENT_H
#include<functional>
#include<set>

class Event
{
public:
	Event(int e_t);
	time_t get_time();
	void virtual execute() = 0;
	bool operator<(Event*);
	bool operator>(Event*);
	bool operator==(Event*);
	
	typedef std::multiset<Event*> event_list;	
protected:
	time_t event_time;
};

#endif