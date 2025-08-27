// utils.c
#include <unistd.h>
#include <string.h>
#include "utils.h"

void write_line(int fd, char* line) {
    write(fd, line, strlen(line));
    write(fd, "\n", 1);
}

int read_line(int fd, char* buffer, int size) {
    int i = 0;
    char c;
    while (i < size - 1 && read(fd, &c, 1) > 0) {
        if (c == '\n') break;
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    return i;
}
