#ifndef RADAR_ACTIVATION_EVENT_H
#define RADAR_ACTIVATION_EVENT_H
#include"event.h"
class RadarActivationEvent : public Event{
public:
	RadarActivationEvent(float event_time, Network* network, EventList* event_list);
	void execute() override;
private:
	EventList* event_list = nullptr;
};
#endif

