#ifndef USER_ACTIVATION_EVENT_H
#define USER_ACTIVATION_EVENT_H
#include "event.h"
#include "generator.h"
class UserActivationEvent : public Event {
public:
	UserActivationEvent(int event_time, Network* network, EventList* event_list);
	void Execute() override;
private:
	EventList* event_list_ = nullptr;
};

#endif
