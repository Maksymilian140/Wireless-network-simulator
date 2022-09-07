#include <iostream>
#include "simulator.h"
#include <spdlog/spdlog.h>
#include <fstream>

using namespace std;

int main()
{
	std::ofstream output_file;
	output_file.open("E_A0.txt", std::ios::app);
	int mode, mean = 150;
	double lambda, E = 0, last_E = 0;
	std::cout << "Wybierz tryb:\n1) Tryb ciagly.\n2) Tryb krokowy (Debug)." << std::endl;
	std::cin >> mode;
	Simulator simulation(10, 5, 20, 5, 200);
	do {
		lambda = static_cast<double>(1) / mean;
		last_E = E;
		E = simulation.RunSimulation(100000, mode, lambda);
		output_file << static_cast<double>(mean) / 1000 << " " << E << "\n";
		mean-=25;
	} while (E < 0.05);
	spdlog::info("E=" + std::to_string(last_E) + " lambda = " + std::to_string(static_cast<double>(mean) / 1000) + "\n");
	output_file.close();
	return 0;
}