#include "user_end_of_service_event.h"

UserEndOfServiceEvent::UserEndOfServiceEvent(float event_time, Network* network, Client* user_to_remove) :Event(event_time, network), user_to_remove(user_to_remove) {}

void UserEndOfServiceEvent::execute() {
	std::cout << "Time: " << network->clock << " || U" << user_to_remove->get_group() << " is removed" << std::endl;
	network->remove_from_bandwidth(user_to_remove);
}