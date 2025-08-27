#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

void processor(int read_fd, int write_fd) {
    char buffer[1024];

    while (1) {
        if (read_line(read_fd, buffer, sizeof(buffer)) > 0) {
            if (strstr(buffer, "ERROR")) {  // filter ERROR logs
                write_line(write_fd, buffer);
            }
        }
    }
}
