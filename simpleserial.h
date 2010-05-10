#ifndef SIMPLESERIAL_H
#define SIMPLESERIAL_H

typedef struct {
	int size;
	char* data;
} binary_data;

class SimpleSerial {
	int _fd;
	binary_data buffer;

	public:
	SimpleSerial();

	int open(const char* device);

	const binary_data* read(void);

	int write(char* buf, ssize_t size);

	int close();
};

#endif
