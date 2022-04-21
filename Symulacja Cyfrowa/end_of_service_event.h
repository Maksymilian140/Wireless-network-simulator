#ifndef	END_OF_SERVICE_EVENT_H
#define END_OF_SERVICE_EVENT_H
#include"event.h"

class EndOfServiceEvent : public Event
{
public:
	EndOfServiceEvent(std::chrono::high_resolution_clock::time_point t, Network* n);
	void execute() override;
};
#endif