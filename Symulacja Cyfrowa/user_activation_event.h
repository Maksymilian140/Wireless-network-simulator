#ifndef USER_ACTIVATION_EVENT_H
#define USER_ACTIVATION_EVENT_H
#include "event.h"
class UserActivationEvent : public Event {
public:
	UserActivationEvent(float t, Network* n);
	void execute() override;
};

#endif
