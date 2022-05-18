#include "buffer.h"
#include<iostream>

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

}
