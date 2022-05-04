#include "user_end_of_service_event.h"

UserEndOfServiceEvent::UserEndOfServiceEvent(float e_t, Network* n, Client* u_t_r) :Event(e_t, n), user_to_remove(u_t_r) {}

void UserEndOfServiceEvent::execute() {
	network->remove_from_bandwidth(user_to_remove);
}
