#include "radar_end_of_service_event.h"
#include "radar_activation_event.h"

RadarEndOfServiceEvent::RadarEndOfServiceEvent(float event_time, Network* network) : Event(event_time, network) {}

void RadarEndOfServiceEvent::execute() {
	std::cout << "Time: " << network->clock << " || U1 " << " is deactivated" << std::endl;
	// releasing users in all radar specified channels
	network->bandwidth_clear_radar();
	// generating random time of next event in range of 1-5 ms
	float event_t = (rand() % 5000 + 1000) + network->clock;
	Event* activation_event = new RadarActivationEvent(event_t, network);
	event_list.insert(activation_event);
}