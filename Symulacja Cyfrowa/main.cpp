#include <iostream>
#include "simulator.h"
#include <spdlog/spdlog.h>
#include <chrono>

using namespace std;

int main()
{
	int mode;
	double lambda = 0.001, E = 0, last_E = 0;
	std::cout << "Wybierz tryb:\n1) Tryb ciagly.\n2) Tryb krokowy (Debug)." << std::endl;
	std::cin >> mode;
	Simulator simulation(10, 5, 20, 5, 200);
	do {
		last_E = E;
		E = simulation.RunSimulation(100000, mode, lambda);
		lambda += 0.000001;
	} while (E < 0.05);
	spdlog::info("E=" + std::to_string(last_E) + " lambda = " + std::to_string(lambda) + "\n");

	return 0;
}