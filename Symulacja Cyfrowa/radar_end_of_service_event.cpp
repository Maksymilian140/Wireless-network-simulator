#include "radar_end_of_service_event.h"
#include "radar_activation_event.h"

RadarEndOfServiceEvent::RadarEndOfServiceEvent(int event_time, Network* network, EventList* event_list) : Event(event_time, network), event_list_(event_list) {}

void RadarEndOfServiceEvent::Execute() {
	spdlog::info("Time: " + network_->GetClock() + "ms" + " ##### U1 is deactivated\n");
	// releasing users in all radar specified channels
	network_->BandwidthClearRadar();
	// generating random time of next event in range of 1-5 ms
	int event_t = radar_time_generator_.RangeRand(1000, 5000) + network_->clock_;
	Event* activation_event = new RadarActivationEvent(event_t, network_, event_list_);
	event_list_->insert(activation_event);
	network_->BandwidthPrint();
	network_->BufferPrint();
}