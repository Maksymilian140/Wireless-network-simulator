#ifndef USER_END_OF_SERVICE_EVENT_H
#define USER_END_OF_SERVICE_EVENT_H
#include"event.h"
class UserEndOfServiceEvent : public Event {
public:
	UserEndOfServiceEvent(float event_time, Network* network, Client* user_to_remove);
	void execute() override;
private:
	Client* user_to_remove;
};
#endif
