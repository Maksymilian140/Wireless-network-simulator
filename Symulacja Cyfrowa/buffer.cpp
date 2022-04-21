#include "buffer.h"
#include<iostream>

Buffer::Buffer(int s, float t_t) : size(s), try_time(t_t) {}

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
		std::cout << "Queue is empty" << std::endl;
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
		std::cout << "Queue is empty" << std::endl;
		return nullptr;
	}
	else {
		return queue_of_clients.front();
	}
}