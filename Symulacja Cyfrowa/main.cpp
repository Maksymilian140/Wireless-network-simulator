#include <iostream>
#include "simulator.h"
#include <spdlog/spdlog.h>
#include <fstream>

using namespace std;

int main()
{
	std::ofstream output_file;
	output_file.open("E_A.txt", std::ios::app);
	int mode, intensity = 1000;
	double lambda, E = 0, last_E = 0;
	std::cout << "Wybierz tryb:\n1) Tryb ciagly.\n2) Tryb krokowy (Debug)." << std::endl;
	std::cin >> mode;
	Simulator simulation(10, 5, 20, 5, 200);
	do {
		lambda = static_cast<double> (1) / intensity;
		last_E = E;
		E = simulation.RunSimulation(100000, mode, lambda);
		output_file << intensity << " " << E << "\n";
		intensity++;
	} while (E < 0.05);

	spdlog::info("E=" + std::to_string(last_E) + " lambda = " + std::to_string(intensity) + "\n");
	output_file.close();
	return 0;
}