#include "radar_activation_event.h"
#include "radar_end_of_service_event.h"

RadarActivationEvent::RadarActivationEvent(int event_time, Network* network, EventList* event_list) :Event(event_time, network), event_list_(event_list) {}

void RadarActivationEvent::Execute() {
	// generate new radar user and add him to the channels
	spdlog::info("Time: " + network_->GetClock() + "ms" + " ##### U1 is activated\n");
	Client* radar = network_->GenerateClient(1);
	network_->AddToBandwidth(radar);
	// plan end of service event for radar add it to eventlist
	int event_t = 10000 + network_->clock_;
	Event* end_event = new RadarEndOfServiceEvent(event_t, network_, event_list_);
	event_list_->insert(end_event);
	network_->BandwidthPrint();
	network_->BufferPrint();
}