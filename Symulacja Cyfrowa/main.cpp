#include <iostream>
#include "simulator.h"
#include <spdlog/spdlog.h>

using namespace std;

int main()
{
	spdlog::info("Welcome to spdlog!");
	Simulator simulation(10, 5, 20, 5, 200);
	simulation.RunSimulation(100000, false);
	return 0;
}