#ifndef SIMULATOR_H
#define	SIMULATOR_H	
#include"network.h"
#include<chrono>
class Simulator
{
public:
	Simulator(int l_a, int p_a, int k_a, int s, float t_t);
	void RunSimulation(float time);
private:
	Network* network;
};

#endif