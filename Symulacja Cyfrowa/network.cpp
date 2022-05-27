#include "network.h"
#include "event.h"

Network::Network(int l_amount, int p_amount, int k_amount, int size, int try_time) {
	bandwidth_ = new Bandwidth(l_amount, p_amount, k_amount);
	buffer_ = new Buffer(size, try_time);
}

Client* Network::GenerateClient(int group) {
	float service_time = 0;
	if (group == 1) service_time = 0.01;
	else service_time = rand() % 5 + 1;
	Client* new_client = new Client(group, service_time);
	return new_client;
}

Client* Network::get_first_from_buffer() {
	return buffer_->get_first();
}

bool Network::AddToBandwidth(Client* client) {
	return bandwidth_->AddToChannel(client);
}

Client* Network::BufferPop() {
	return buffer_->Pop();
}

void Network::BandwidthClearRadar() {
	bandwidth_->ClearRadar();
}

bool Network::is_buffer_occupied() {
	return buffer_->is_occupied();
}

void Network::AddToBuffer(Client* c) {
	buffer_->Add(c);
}

void Network::RemoveFromBandwidth(Client* c) {
	bandwidth_->RemoveUser(c);
	delete c;
}

void Network::Initialize() {
	bandwidth_->Clear();
	buffer_->Clear();
}

void Network::BandwidthPrint() {
	bandwidth_->Print();
}

void Network::BufferPrint() {
	buffer_->Print();
}