#include "gather_statistics_event.h"

GatherStatisticsEvent::GatherStatisticsEvent(int event_time, Network* network, EventList* event_list) :Event(event_time, network), event_list_(event_list) {}

void GatherStatisticsEvent::Execute() {
	network_->UpdateBandwidthStat();
	network_->UpdateServicedUsersStat();
	int event_t = 1000 + network_->clock_;
	Event* next_stat_event = new GatherStatisticsEvent(event_t, network_, event_list_);
	event_list_->insert(next_stat_event);
}