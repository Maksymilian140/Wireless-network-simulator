#ifndef RADAR_ACTIVATION_EVENT_H
#define RADAR_ACTIVATION_EVENT_H
#include"event.h"
class RadarActivationEvent : public Event{
public:
	RadarActivationEvent(int event_time, Network* network, EventList* event_list);
	void Execute() override;
private:
	EventList* event_list_ = nullptr;
};
#endif

