#ifndef CHANNEL_REQUEST_EVENT_H
#define CHANNEL_REQUEST_EVENT_H
#include"event.h"
class ChannelRequestEvent : public Event
{
public:
	ChannelRequestEvent(int event_time, Network* network, EventList* event_list);
	void Execute() override;
private:
	const int kRequestFrequency_ = 200;
	EventList* event_list_ = nullptr;
};
#endif
