#include "user_end_of_service_event.h"

UserEndOfServiceEvent::UserEndOfServiceEvent(int event_time, Network* network, Client* user_to_remove) :Event(event_time, network), user_to_remove_(user_to_remove) {}

void UserEndOfServiceEvent::Execute() {
	spdlog::info("Time: " + network_->get_clock() + "ms" + " ##### U" + std::to_string(user_to_remove_->get_group()) + " is removed\n");
	network_->RemoveFromBandwidth(user_to_remove_);
	network_->BandwidthPrint();
	network_->BufferPrint();
}
