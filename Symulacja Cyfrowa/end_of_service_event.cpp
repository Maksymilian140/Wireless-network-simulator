#include "end_of_service_event.h"

EndOfServiceEvent::EndOfServiceEvent(std::chrono::high_resolution_clock::time_point t, Network* n) : Event(t, n) {
	
}

void EndOfServiceEvent::execute() {
	
}