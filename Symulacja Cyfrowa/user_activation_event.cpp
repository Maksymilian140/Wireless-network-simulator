#include "user_activation_event.h"
#include "user_end_of_service_event.h"

UserActivationEvent::UserActivationEvent(int event_time, Network* network, EventList* event_list) :Event(event_time, network), event_list_(event_list) {}

void UserActivationEvent::Execute() {
	// draw group number and generate new user and add him to bandwidth
	int group;
	if (network_->GetRatio() == 60 or network_->GetRatio() == 0) group = rand() % 2 + 2;
	if (network_->GetRatio() < 60) group = 2;
	else group = 3;
	spdlog::info("Time: " + network_->GetClock() + "ms" + " ##### U" + std::to_string(group) + " is generated\n");
	Client* client = network_->GenerateClient(group);
	bool is_added = network_->AddToBandwidth(client);
	// if user succesfuly was added to the channel then plan end of service event for him
	if (is_added) {
		spdlog::info("Time: " + network_->GetClock() + "ms" + " ##### U" + std::to_string(client->GetGroup()) + " is added to channel\n");
		int event_t = (rand() % 6000) + network_->clock_;
		Event* next_request_event = new UserEndOfServiceEvent(event_t, network_, client);
		event_list_->insert(next_request_event);
	}
	else {
		// if buffer is occupied then drop the user else add him to the buffer
		if (network_->IsBufferOccupied()) delete client;
		else {
			spdlog::info("Time: " + network_->GetClock() + "ms" + " ##### U" + std::to_string(group) + " is added to buffer\n");
			network_->AddToBuffer(client);
		}
	}
	network_->BandwidthPrint();
	network_->BufferPrint();
	network_->UpdateUserStat(group);
	// plan next user activation event
	int event_t = (rand() % 500) + network_->clock_;
	Event* next_request_event = new UserActivationEvent(event_t, network_, event_list_);
	event_list_->insert(next_request_event);
}