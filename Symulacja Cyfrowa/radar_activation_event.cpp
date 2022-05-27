#include "radar_activation_event.h"
#include "radar_end_of_service_event.h"

RadarActivationEvent::RadarActivationEvent(float event_time, Network* network, EventList* event_list) :Event(event_time, network), event_list_(event_list) {}

void RadarActivationEvent::Execute() {
	// generate new radar user and add him to the channels
	spdlog::info("Time: " + std::to_string(network_->clock_) + " ##### U1 is activated\n");
	Client* radar = network_->GenerateClient(1);
	network_->AddToBandwidth(radar);
	// plan end of service event for radar add it to eventlist
	float event_t = 10000 + network_->clock_;
	Event* next_request_event = new RadarEndOfServiceEvent(event_t, network_, event_list_);
	event_list_->insert(next_request_event);
	network_->BandwidthPrint();
	network_->BufferPrint();
}