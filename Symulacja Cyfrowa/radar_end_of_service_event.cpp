#include "radar_end_of_service_event.h"
#include "radar_activation_event.h"

RadarEndOfServiceEvent::RadarEndOfServiceEvent(std::chrono::high_resolution_clock::time_point t, Network* n) : Event(t, n) {}

void RadarEndOfServiceEvent::execute() {
	// releasing users in all radar specified channels
	network->bandwidth_clear_radar();
	// generating random time of next event in range of 1-5 ms
	auto event_t = std::chrono::high_resolution_clock::now();
	int next_activation = rand() % 5000 + 1000;
	event_t += std::chrono::microseconds(next_activation);
	Event* activation_event = new RadarActivationEvent(event_t, network);
	event_list.insert(activation_event);
}