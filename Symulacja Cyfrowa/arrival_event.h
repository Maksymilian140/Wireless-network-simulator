#ifndef ARRIVAL_EVENT_H
#define ARRIVAL_EVENT_H
#include"event.h"
class ArrivalEvent : public Event
{
public:
	ArrivalEvent(time_t t);
	void execute() override;
};
#endif
