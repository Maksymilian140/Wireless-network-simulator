#ifndef SIMULATOR_H
#define	SIMULATOR_H	
#include "network.h"
class Simulator
{
public:
	Simulator(int l_amount, int p_amount, int k_amount, int size, int try_time);
	double RunSimulation(int time, int mode, double lambda, int seed);
private:
	Network* network_;
};

#endif