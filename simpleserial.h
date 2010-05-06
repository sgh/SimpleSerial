#ifndef SIMPLESERIAL_H
#define SIMPLESERIAL_H

class SimpleSerial {
	int _fd;

	public:
	SimpleSerial();

	int open(const char* device);

	int read(char* buf, ssize_t size);

	int write(char* buf, ssize_t size);

	int close();
};

#endif
