#ifndef SIMULATOR_H
#define	SIMULATOR_H	
#include"network.h"
#include<chrono>
class Simulator
{
public:
	Simulator(int l_amount, int p_amount, int k_amount, int size, int try_time);
	void RunSimulation(int time, int mode);
private:
	Network* network_;
};

#endif