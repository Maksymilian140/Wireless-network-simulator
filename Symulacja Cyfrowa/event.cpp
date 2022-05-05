#include "event.h"

Event::Event(float event_time, Network* network) : event_time(event_time), network(network) {}

float Event::get_time() {
	return event_time;
}

bool Event::operator<(Event* e) {
	if (event_time < e->get_time()) return true;
	else return false;
}

bool Event::operator>(Event* e) {
	if (event_time > e->get_time()) return true;
	else return false;
}

bool Event::operator==(Event* e) {
	if (event_time == e->get_time()) return true;
	else return false;
}