#ifndef	RADAR_END_OF_SERVICE_EVENT_H
#define RADAR_END_OF_SERVICE_EVENT_H
#include"event.h"

class RadarEndOfServiceEvent : public Event
{
public:
	RadarEndOfServiceEvent(float t, Network* n);
	void execute() override;
};
#endif