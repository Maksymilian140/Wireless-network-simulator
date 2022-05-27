#ifndef	RADAR_END_OF_SERVICE_EVENT_H
#define RADAR_END_OF_SERVICE_EVENT_H
#include"event.h"

class RadarEndOfServiceEvent : public Event
{
public:
	RadarEndOfServiceEvent(float event_time, Network* network, EventList* event_list);
	void Execute() override;
private:
	EventList* event_list_ = nullptr;
};
#endif