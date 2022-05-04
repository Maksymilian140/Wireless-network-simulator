#include "radar_activation_event.h"
#include "radar_end_of_service_event.h"

RadarActivationEvent::RadarActivationEvent(float e_t, Network* n) :Event(e_t, n) {}

void RadarActivationEvent::execute() {
	// generate new radar user and add him to the channels
	Client* radar = network->generate_client(1);
	network->add_to_bandwidth(radar);
	// plan end of service event for radar add it to eventlist
	float event_t = 10000;
	Event* next_request_event = new RadarEndOfServiceEvent(event_t, network);
	event_list.insert(next_request_event);
}