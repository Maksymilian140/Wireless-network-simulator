#include "event.h"

Event::Event(float e_t, Network* n) : event_time(e_t), network(n) {}

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