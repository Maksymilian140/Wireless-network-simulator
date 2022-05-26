#include "buffer.h"
#include <iostream>
#include <spdlog/spdlog.h>

Buffer::Buffer(int size, float try_time) : size(size), try_time(try_time) {}

void Buffer::add(Client* c) {
	if (queue_of_clients.size() < size) {
		queue_of_clients.push(c);
	}
	else {
		std::cout << "Queue is full" << std::endl;
	}
}

Client* Buffer::pop() {
	if (queue_of_clients.empty()) {
		return nullptr;
	}
	else {
		Client* c = queue_of_clients.front();
		queue_of_clients.pop();
		return c;
	}
}

Client* Buffer::get_first() {
	if (queue_of_clients.empty()) {
		return nullptr;
	}
	else {
		return queue_of_clients.front();
	}
}

bool Buffer::is_occupied() {
	if (queue_of_clients.size() == size) return true;
	else return false;
}

void Buffer::clear() {
	while (!queue_of_clients.empty()) {
		queue_of_clients.pop();
	}
}

void Buffer::print() {
	std::string bottom_line = "#      #      #      #      #      #\n";
	std::string top_line = "###############BUFFER###############\n";
	top_line += "#      #      #      #      #      #\n";
	bottom_line += "####################################\n";
	std::string printed_buffer = "";
	char group = '0';
	std::queue<Client*> temp_queue = queue_of_clients;
	for (int i = 0; i < size; i++) {
		if (temp_queue.size() != 0) {
			group = static_cast<char>(temp_queue.front()->get_group() + 48);
			printed_buffer += "#  U";
			printed_buffer += group;
			printed_buffer += "  ";
			temp_queue.pop();
		}
		else {
			for (int j = i; j < size; j++)
				printed_buffer += "#      ";
			break;
		}
	}
	printed_buffer += "#\n";
	spdlog::info('\n' + top_line + printed_buffer + bottom_line);
}
