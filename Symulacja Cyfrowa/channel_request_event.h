#ifndef CHANNEL_REQUEST_EVENT_H
#define CHANNEL_REQUEST_EVENT_H
#include"event.h"
class ChannelRequestEvent : public Event
{
public:
	ChannelRequestEvent(float event_time, Network* network);
	void execute() override;
private:
	const int request_frequency = 200;
};
#endif
