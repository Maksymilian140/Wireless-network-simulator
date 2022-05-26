#include "radar_end_of_service_event.h"
#include "radar_activation_event.h"

RadarEndOfServiceEvent::RadarEndOfServiceEvent(float event_time, Network* network, EventList* event_list) : Event(event_time, network), event_list(event_list) {}

void RadarEndOfServiceEvent::execute() {
	spdlog::info("Time: " + std::to_string(network->clock) + " ##### U1 is deactivated\n");
	// releasing users in all radar specified channels
	network->bandwidth_clear_radar();
	// generating random time of next event in range of 1-5 ms
	float event_t = (rand() % 4000 + 1000) + network->clock;
	Event* activation_event = new RadarActivationEvent(event_t, network, event_list);
	event_list->insert(activation_event);
	network->bandwidth_print();
	network->buffer_print();
}