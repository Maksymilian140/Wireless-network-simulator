#ifndef RADAR_ACTIVATION_EVENT_H
#define RADAR_ACTIVATION_EVENT_H
#include"event.h"
class RadarActivationEvent : public Event{
public:
	RadarActivationEvent(std::chrono::high_resolution_clock::time_point t, Network* n);
	void execute() override;
};
#endif

