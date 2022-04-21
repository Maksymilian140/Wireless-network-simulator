#ifndef CHANNEL_REQUEST_EVENT_H
#define CHANNEL_REQUEST_EVENT_H
#include"event.h"
class ChannelRequestEvent : public Event
{
public:
	ChannelRequestEvent(std::chrono::high_resolution_clock::time_point e_t, Network* n, Buffer* bu, Bandwidth* ba);
	void execute() override;
private:
	Buffer* buffer;
	Bandwidth* bandwidth;
	const int request_frequency = 200;
};
#endif
