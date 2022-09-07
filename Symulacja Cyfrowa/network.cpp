#include "network.h"
#include "event.h"
#include <fstream>

Network::Network(int l_amount, int p_amount, int k_amount, int size, int try_time) {
	bandwidth_ = new Bandwidth(l_amount, p_amount, k_amount);
	buffer_ = new Buffer(size, try_time);
}

Client* Network::GenerateClient(int group) {
	int service_time = 0;
	if (group == 1) service_time = 10000;
	else service_time = rand() % 5000 + 1000;
	Client* new_client = new Client(group, service_time);
	return new_client;
}

Client* Network::GetFirstFromBuffer() {
	return buffer_->GetFirst();
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

bool Network::IsBufferOccupied() {
	return buffer_->IsOccupied();
}

void Network::AddToBuffer(Client* c) {
	buffer_->Add(c);
}

void Network::RemoveFromBandwidth(Client* c) {
	bandwidth_->RemoveUser(c);
	delete c;
}

void Network::Initialize(double lambda) {
	bandwidth_->Clear();
	buffer_->Clear();
	u2_total_ = u3_total_ = u2_lost_ = u3_lost_ = u2_serviced_sum_ = u3_serviced_sum_ = stat_counter_ = all_users_ = 0;
	bandwidth_usage_counter_ = 0;
	lambda_ = lambda;
}

void Network::BandwidthPrint() {
	bandwidth_->Print();
}

void Network::BufferPrint() {
	buffer_->Print();
}

void Network::UpdateUserStat(int group) {
	if (group == 2) u2_total_++;
	else u3_total_++;
}

void Network::UpdateUserLostStat(int group) {
	if (group == 2) u2_lost_++;
	else u3_lost_++;
}

int Network::GetRatio() {
	if (u2_total_ == 0 and u3_total_ == 0)
		return 0;
	else
		return static_cast<int>((static_cast<double>(u2_total_) / (u2_total_ + u3_total_)) * 100);
}

std::string Network::GetClock() {
	std::string time = std::to_string(static_cast<double>(clock_) / 1000);
	time.resize(time.size() - 3);
	return time;
}

double Network::GetLambda() {
	return lambda_;
}

int Network::GetRadarChannelAmount() {
	return bandwidth_->GetRadarBandwidthSize();
}

void Network::SaveBlockProbStat() {
	std::ofstream output_file;
	output_file.open("./Block_Probability_Statistics.txt", std::ios_base::app);
	output_file << "lambda=" + std::to_string(lambda_) + ", E_U2=" + std::to_string(static_cast<double> (u2_lost_ + bandwidth_->GetKickedStat().first) / u2_total_) + ", E_U3=" + std::to_string(static_cast<double> (u3_lost_ + bandwidth_->GetKickedStat().second) / u3_total_) + "\n";
	output_file.close();
}

void Network::UpdateBandwidthStat() {
	bandwidth_usage_counter_ += bandwidth_->GetUsage() / bandwidth_->GetSize();
}

void Network::UpdateServicedUsersStat() {
	u2_serviced_sum_ += bandwidth_->CountServicedUsers(2);
	u3_serviced_sum_ += bandwidth_->CountServicedUsers(3);
	stat_counter_++;
}

void Network::UpdateAllUsersStat() {
	all_users_++;
}

void Network::DisplayServicedUsersStat() {
	std::string u2_avg = std::to_string(static_cast<double>(u2_serviced_sum_) / stat_counter_);
	std::string u3_avg = std::to_string(static_cast<double>(u3_serviced_sum_) / stat_counter_);
	u2_avg.resize(u2_avg.size() - 4);
	u3_avg.resize(u3_avg.size() - 4);
	spdlog::info("Average U2's serviced: " + u2_avg + "\n");
	spdlog::info("Average U3's serviced: " + u3_avg + "\n");
}

void Network::DisplayBlockProbability() {
	std::string u2_E = std::to_string(static_cast<double> (u2_lost_ + bandwidth_->GetKickedStat().first) / u2_total_);
	std::string u3_E = std::to_string(static_cast<double> (u3_lost_ + bandwidth_->GetKickedStat().second) / u3_total_);
	//u2_E.resize(u2_E.size() - 6);
	//u3_E.resize(u3_E.size() - 6);
	spdlog::info("U2: E = " + u2_E + "\n");
	spdlog::info("U3: E = " + u3_E + "\n");
}

void Network::DisplayBandwidthStat() {
	std::string b_usage = std::to_string((bandwidth_usage_counter_ / stat_counter_) * 100);
	b_usage.resize(b_usage.size() - 4);
	spdlog::info("Average bandwidth usage: " + b_usage + "%\n");
	spdlog::info("Total users amount: " + std::to_string(all_users_) + "\n");
}

double Network::ReturnBlockProbability() {
	return static_cast<double> (u2_lost_ + bandwidth_->GetKickedStat().first + u3_lost_ + bandwidth_->GetKickedStat().second) / all_users_;
}
