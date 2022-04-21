#ifndef USER_ACTIVATION_EVENT_H
#define USER_ACTIVATION_EVENT_H
#include "event.h"
class UserActivationEvent : public Event {
public:
	UserActivationEvent(std::chrono::high_resolution_clock::time_point t, Network* n);
	void execute() override;
};

#endif
