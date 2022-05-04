#ifndef SIMULATOR_H
#define	SIMULATOR_H	
#include"network.h"
#include<chrono>
class Simulator
{
public:
	Simulator(int l_a, int p_a, int k_a, int s, float t_t);
	void RunSimulation();
private:
	std::chrono::high_resolution_clock::time_point clock;
	Network* network;
};

#endif