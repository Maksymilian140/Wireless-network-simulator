#include "event.h"

Event::Event(int event_time, Network* network) : event_time_(event_time), network_(network) {}

int Event::GetTime() {
	return event_time_;
}