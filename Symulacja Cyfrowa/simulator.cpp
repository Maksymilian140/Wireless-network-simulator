#include "simulator.h"
#include "radar_activation_event.h"
#include "user_activation_event.h"
#include "channel_request_event.h"
#include "gather_statistics_event.h"
#include <iostream>
#include <spdlog/spdlog.h>

Simulator::Simulator(int l_amount, int p_amount, int k_amount, int size, int try_time, double lambda) {
	network_ = new Network(l_amount, p_amount, k_amount, size, try_time, lambda);
}

void Simulator::RunSimulation(int time, int mode){
	network_->clock_ = 0;
	network_->Initialize();
	if (mode == 2) spdlog::set_level(spdlog::level::debug);
	spdlog::debug("Debuging enabled");
	spdlog::info("##### Start of simulation #####\n");
	auto compare_events = [](Event* left, Event* right) { return left->get_time() < right->get_time(); };
	Event::EventList event_list(compare_events);
	Event* first_radar_event = new RadarActivationEvent(0, network_, &event_list);
	Event* first_user_event = new UserActivationEvent(0, network_, &event_list);
	Event* channel_request_start_event = new ChannelRequestEvent(200, network_, &event_list);
	Event* gather_statistics_event = new GatherStatisticsEvent(1000, network_, &event_list);
	event_list.insert(first_radar_event);
	event_list.insert(first_user_event);
	event_list.insert(channel_request_start_event);
	event_list.insert(gather_statistics_event);
	while (network_->clock_ < time) {
		auto event_iterator = event_list.begin();
		Event* exc_event = event_iterator._Ptr->_Myval;
		if (mode == 2 && typeid(*exc_event).name() != typeid(*channel_request_start_event).name()) {
			while (true) {
				if (std::cin.get() == '\n') break;
			}
		}
		event_list.erase(event_iterator);
		network_->clock_ = exc_event->get_time();
		exc_event->Execute();
	}
	network_->DisplayBlockProbability();
	network_->DisplayServicedUsersStat();
	network_->DisplayBandwidthStat();
}