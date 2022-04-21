#include "arrival_event.h"

ArrivalEvent::ArrivalEvent(time_t t, Network* n) : Event(t, n) {}

void ArrivalEvent::execute() {
	network->GeneratePacket();
	if ()
}
