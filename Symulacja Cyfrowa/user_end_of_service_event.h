#ifndef USER_END_OF_SERVICE_EVENT_H
#define USER_END_OF_SERVICE_EVENT_H
#include"event.h"
class UserEndOfServiceEvent : public Event {
public:
	UserEndOfServiceEvent(std::chrono::high_resolution_clock::time_point t, Network* n, Client* u_t_r);
	void execute() override;
private:
	Client* user_to_remove;
};
#endif
