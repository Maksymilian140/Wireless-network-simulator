#ifndef USER_ACTIVATION_EVENT_H
#define USER_ACTIVATION_EVENT_H
#include "event.h"
class UserActivationEvent : public Event {
public:
	UserActivationEvent(float event_time, Network* network, EventList* event_list);
	void execute() override;
private:
	EventList* event_list = nullptr;
};

#endif
