#include "event.h"
#include <chrono>

Event::Event(std::chrono::high_resolution_clock::time_point e_t, Network* n) : event_time(e_t), network(n) {}

std::chrono::high_resolution_clock::time_point Event::get_time() {
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