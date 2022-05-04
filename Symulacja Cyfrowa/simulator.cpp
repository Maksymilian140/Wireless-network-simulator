#include "simulator.h"
#include "radar_activation_event.h"
#include "user_activation_event.h"
#include <iostream>

Simulator::Simulator(int l_a, int p_a, int k_a, int s, float t_t) {
	network = new Network(l_a, p_a, k_a, s, t_t);
}

void Simulator::RunSimulation(float time){
	float clock = 0;
	network->initialize();
	std::cout << "Start of simulation: " << std::endl;
	Event* first_radar_event = new RadarActivationEvent(clock, network);
	Event* first_user_event = new UserActivationEvent(clock, network);
	while (clock < time) {
		auto iterator = Event::event_list.begin();
		Event* exc_event = iterator._Ptr->_Myval;
		Event::event_list.erase(iterator);
		clock = exc_event->get_time();
		std::cout << "Simulation time: " << clock << std::endl;
		exc_event->execute();
	}
}