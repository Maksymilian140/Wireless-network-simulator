#include "simulator.h"

Simulator::Simulator(int l_a, int p_a, int k_a, int s, float t_t) {
	network = new Network(l_a, p_a, k_a, s, t_t);
}

void Simulator::RunSimulation(){
	clock = 0;
	
}