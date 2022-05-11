#ifndef CHANNEL_REQUEST_EVENT_H
#define CHANNEL_REQUEST_EVENT_H
#include"event.h"
class ChannelRequestEvent : public Event
{
public:
	ChannelRequestEvent(float event_time, Network* network, EventList* event_list);
	void execute() override;
private:
	const int request_frequency = 200;
	EventList* event_list = nullptr;
};
#endif
