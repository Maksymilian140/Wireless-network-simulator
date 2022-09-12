#include <iostream>
#include "simulator.h"
#include <spdlog/spdlog.h>
#include <fstream>

using namespace std;

int main()
{
	std::ofstream output_file;
	output_file.open("E_A.txt", std::ios::app);
	int mode, mean = 500, sim_end_time, phase_end_time;
	double lambda, E = 0, last_E = 0;
	std::cout << "Wybierz tryb:\n1) Tryb ciagly.\n2) Tryb krokowy (Debug)." << std::endl;
	std::cin >> mode;		// in debug mode press 'enter' key to continue simulation
	std::cout << "Prosze podac czas konca symulacji (w milisekundach): ";
	std::cin >> sim_end_time;
	std::cout << "Prosze podac dlugosc fazy poczatkowej (w milisekundach): ";
	std::cin >> phase_end_time;
	std::cout << std::endl;
	Simulator simulation(10, 5, 20, 5, 200);
	do {
		lambda = static_cast<double> (1) / mean;
		last_E = E;
		E = simulation.RunSimulation(sim_end_time, phase_end_time, mode, lambda, rand() % 1000 + 10);
		output_file << mean << " " << E << "\n";
		mean--;
	} while (E < 0.05);
	simulation.DisplayStatistics();
	spdlog::info("E=" + std::to_string(last_E) + " lambda = " + std::to_string(mean) + "\n");
	output_file.close();
	return 0;
}