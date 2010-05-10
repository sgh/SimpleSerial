#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFERSIZE 256

#include "simpleserial.h"
SimpleSerial::SimpleSerial() {
	_fd = -1;
	buffer.data = new char[BUFFERSIZE];
}

int SimpleSerial::open(const char* device) {
	_fd = ::open(device,  O_RDWR|O_NOCTTY | O_NONBLOCK );
}

const binary_data* SimpleSerial::read(void) {
	int i = ::read(_fd, buffer.data, BUFFERSIZE);
	
	if (i>0) {
		buffer.size = i;
		buffer.data[i] = 0;
		printf("(%d) : %s\n", i, buffer.data);
	} else
		buffer.size = 0;

	return &buffer;
}

int SimpleSerial::write(char* buf, ssize_t size) {
  return ::write(_fd, buf, size);
}

int SimpleSerial::close() {
	return ::close(_fd);
}


#define TESTCODE
#ifdef TESTCODE
int main() {
	const binary_data* buffer;
	SimpleSerial serial;


	serial.open("/dev/ttyPS1");
	while (1) {
		buffer = serial.read();
		usleep(10000);
	}
	
}
#endif
