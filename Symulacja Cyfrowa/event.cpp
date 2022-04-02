#include "event.h"

Event::Event(int e_t) : event_time(e_t) {}

time_t Event::get_time() {
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