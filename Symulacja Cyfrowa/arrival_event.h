#ifndef ARRIVAL_EVENT_H
#define ARRIVAL_EVENT_H
#include"event.h"
class ArrivalEvent : public Event
{
public:
	void execute() override;
	ArrivalEvent(time_t t);
};
#endif
