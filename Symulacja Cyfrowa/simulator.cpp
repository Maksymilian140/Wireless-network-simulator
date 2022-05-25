#include "simulator.h"
#include "radar_activation_event.h"
#include "user_activation_event.h"
#include <iostream>
#include <spdlog/spdlog.h>

Simulator::Simulator(int l_amount, int p_amount, int k_amount, int size, int try_time) {
	network = new Network(l_amount, p_amount, k_amount, size, try_time);
}

void Simulator::RunSimulation(int time, bool mode){
	network->clock = 0;
	network->initialize();
	if (!mode) spdlog::set_level(spdlog::level::debug);
	spdlog::debug("Debuging enabled");
	spdlog::info("##### Start of simulation #####");
	auto compare_events = [](Event* left, Event* right) { return left->get_time() < right->get_time(); };
	Event::EventList event_list(compare_events);
	Event* first_radar_event = new RadarActivationEvent(rand() % 4000 + 1000, network, &event_list);
	Event* first_user_event = new UserActivationEvent(rand() % 7000 + 1000, network, &event_list);
	event_list.insert(first_radar_event);
	event_list.insert(first_user_event);
	while (network->clock < time) {
		auto event_iterator = event_list.begin();
		Event* exc_event = event_iterator._Ptr->_Myval;
		event_list.erase(event_iterator);
		network->clock = exc_event->get_time();
		exc_event->execute();
		if (!mode) {
			while (true) {
				if (std::cin.get() == '\n') break;
			}
		}
		network->bandwidth_print();
		network->buffer_print();
	}
}