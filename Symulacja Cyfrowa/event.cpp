#include "event.h"

Event::Event(float event_time, Network* network) : event_time_(event_time), network_(network) {}

float Event::get_time() {
	return event_time_;
}