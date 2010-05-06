#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "simpleserial.h"

SimpleSerial::SimpleSerial() {
	_fd = -1;
}

int SimpleSerial::open(const char* device) {
	_fd = ::open(device,  O_RDWR|O_NOCTTY | O_NONBLOCK );
}

int SimpleSerial::read(char* buf, ssize_t size) {
	return ::read(_fd,buf, size);
}

int SimpleSerial::write(char* buf, ssize_t size) {
  return ::write(_fd, buf, size);
}

int SimpleSerial::close() {
	return ::close(_fd);
}


// #define TESTCODE
#ifdef TESTCODE
int main() {
	char buf[32];
	SimpleSerial serial;


	serial.open("/dev/ttyS0");
	while (1) {
		printf("read %d bytes\n", serial.read(buf,sizeof(buf)));
		usleep(100000);
	}
	
}
#endif