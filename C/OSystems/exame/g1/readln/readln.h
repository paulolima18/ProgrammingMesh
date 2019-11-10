#ifndef READLN_H_
#define READLN_H_
#include <unistd.h>
#include <fcntl.h>

ssize_t readln(int fildes, char *buf, size_t nbyte);

#endif
