#include "simulator.h"
#include "radar_activation_event.h"

Simulator::Simulator(int l_a, int p_a, int k_a, int s, float t_t) {
	network = new Network(l_a, p_a, k_a, s, t_t);
}

void Simulator::RunSimulation(){
	clock = std::chrono::high_resolution_clock::now();
	Event* first_radar_event = new RadarActivationEvent(clock, network);
	while (true) {
		
	}
	
}