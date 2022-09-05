#ifndef GATHER_STATISTICS_EVENT_H
#define GATHER_STATISTICS_EVENT_H
#include"event.h"
class GatherStatisticsEvent : public Event {
public:
	GatherStatisticsEvent(int event_time, Network* network, EventList* event_list);
	void Execute() override;
private:
	EventList* event_list_ = nullptr;
};
#endif
