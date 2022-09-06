#include <iostream>
#include "simulator.h"
#include <spdlog/spdlog.h>
#include <fstream>

using namespace std;

int main()
{
	std::ofstream output_file;
	output_file.open("E_A0.txt", std::ios::app);
	int mode;
	double lambda = 0.001, E = 0, last_E = 0;
	std::cout << "Wybierz tryb:\n1) Tryb ciagly.\n2) Tryb krokowy (Debug)." << std::endl;
	std::cin >> mode;
	Simulator simulation(10, 5, 20, 5, 200);
	do {
		last_E = E;
		E = simulation.RunSimulation(100000, mode, lambda);
		lambda += 0.000001;
		output_file << lambda << " " << E << "\n";
	} while (E < 0.05);
	spdlog::info("E=" + std::to_string(last_E) + " lambda = " + std::to_string(lambda) + "\n");
	output_file.close();
	return 0;
}