#ifndef RADAR_ACTIVATION_EVENT_H
#define RADAR_ACTIVATION_EVENT_H
#include"event.h"
class RadarActivationEvent : public Event{
public:
	RadarActivationEvent(float event_time, Network* network);
	void execute() override;
};
#endif

