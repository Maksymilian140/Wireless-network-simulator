#ifndef	RADAR_END_OF_SERVICE_EVENT_H
#define RADAR_END_OF_SERVICE_EVENT_H
#include "event.h"
#include "generator.h"
class RadarEndOfServiceEvent : public Event
{
public:
	RadarEndOfServiceEvent(int event_time, Network* network, EventList* event_list);
	void Execute() override;
private:
	EventList* event_list_ = nullptr;
	UniformGenerator radar_time_generator_ = UniformGenerator(44);
};
#endif