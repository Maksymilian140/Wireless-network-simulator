#include "buffer.h"
#include <iostream>
#include <spdlog/spdlog.h>

Buffer::Buffer(int size, float try_time) : kSize_(size), kTryTime_(try_time) {}

void Buffer::Add(Client* client) {
	if (queue_of_clients_.size() < kSize_) {
		queue_of_clients_.push(client);
	}
	else {
		std::cout << "Queue is full" << std::endl;
	}
}

Client* Buffer::Pop() {
	if (queue_of_clients_.empty()) {
		return nullptr;
	}
	else {
		Client* c = queue_of_clients_.front();
		queue_of_clients_.pop();
		return c;
	}
}

Client* Buffer::get_first() {
	if (queue_of_clients_.empty()) {
		return nullptr;
	}
	else {
		return queue_of_clients_.front();
	}
}

bool Buffer::is_occupied() {
	if (queue_of_clients_.size() == kSize_) return true;
	else return false;
}

void Buffer::Clear() {
	while (!queue_of_clients_.empty()) {
		queue_of_clients_.pop();
	}
}

void Buffer::Print() {
	std::string bottom_line = "#      #      #      #      #      #\n";
	std::string top_line = "###############BUFFER###############\n";
	top_line += "#      #      #      #      #      #\n";
	bottom_line += "####################################\n";
	std::string printed_buffer = "";
	char group = '0';
	std::queue<Client*> temp_queue = queue_of_clients_;
	for (int i = 0; i < kSize_; i++) {
		if (temp_queue.size() != 0) {
			group = static_cast<char>(temp_queue.front()->get_group() + 48);
			printed_buffer += "#  U";
			printed_buffer += group;
			printed_buffer += "  ";
			temp_queue.pop();
		}
		else {
			for (int j = i; j < kSize_; j++)
				printed_buffer += "#      ";
			break;
		}
	}
	printed_buffer += "#\n";
	spdlog::info('\n' + top_line + printed_buffer + bottom_line);
}
