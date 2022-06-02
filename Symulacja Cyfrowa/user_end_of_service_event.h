#ifndef USER_END_OF_SERVICE_EVENT_H
#define USER_END_OF_SERVICE_EVENT_H
#include"event.h"
class UserEndOfServiceEvent : public Event {
public:
	UserEndOfServiceEvent(int event_time, Network* network, Client* client_to_remove);
	void Execute() override;
private:
	Client* user_to_remove_;
};
#endif
