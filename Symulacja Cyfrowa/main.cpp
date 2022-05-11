#include <iostream>
#include "simulator.h"

using namespace std;

int main()
{
	Simulator simulation(10, 5, 20, 5, 200);
	simulation.RunSimulation(100000, false);
	return 0;
}