#ifndef	RADAR_END_OF_SERVICE_EVENT_H
#define RADAR_END_OF_SERVICE_EVENT_H
#include"event.h"

class RadarEndOfServiceEvent : public Event
{
public:
	RadarEndOfServiceEvent(float event_time, Network* network);
	void execute() override;
};
#endif