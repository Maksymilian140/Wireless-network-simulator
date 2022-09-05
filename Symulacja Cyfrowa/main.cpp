#include <iostream>
#include "simulator.h"
#include <spdlog/spdlog.h>
#include <chrono>

using namespace std;

int main()
{
	int mode;
	std::cout << "Wybierz tryb:\n1) Tryb ciagly.\n2) Tryb krokowy (Debug)." << std::endl;
	std::cin >> mode;
	Simulator simulation(10, 5, 20, 5, 200, 0.007);
	simulation.RunSimulation(100000, mode);
	return 0;
}