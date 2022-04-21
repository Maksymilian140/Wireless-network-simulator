#ifndef	RADAR_END_OF_SERVICE_EVENT_H
#define RADAR_END_OF_SERVICE_EVENT_H
#include"event.h"

class RadarEndOfServiceEvent : public Event
{
public:
	RadarEndOfServiceEvent(std::chrono::high_resolution_clock::time_point t, Network* n);
	void execute() override;
};
#endif