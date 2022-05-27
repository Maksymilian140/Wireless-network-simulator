#ifndef CLIENT_H
#define CLIENT_H

class Client
{
public:
	Client(int group, float service_time);
	int get_group(), get_service_time();
private:
	const int kGroup_;
	const float kServiceTime_;
};

#endif
