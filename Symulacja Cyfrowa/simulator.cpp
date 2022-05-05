#include "simulator.h"
#include "radar_activation_event.h"
#include "user_activation_event.h"
#include <iostream>

Simulator::Simulator(int l_amount, int p_amount, int k_amount, int size, float try_time) {
	network = new Network(l_amount, p_amount, k_amount, size, try_time);
}

void Simulator::RunSimulation(float time){
	network->clock = 0;
	network->initialize();
	std::cout << "Start of simulation: " << std::endl;
	Event* first_radar_event = new RadarActivationEvent(network->clock, network);
	Event* first_user_event = new UserActivationEvent(network->clock, network);
	while (network->clock < time) {
		auto iterator = Event::event_list.begin();
		Event* exc_event = iterator._Ptr->_Myval;
		Event::event_list.erase(iterator);
		network->clock = exc_event->get_time();
		std::cout << "Simulation time: " << clock << std::endl;
		exc_event->execute();
	}
}