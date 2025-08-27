#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "utils.h"

void consumer(int read_fd) {
    char buffer[1024];
    int error_count = 0;

    while (1) {
        if (read_line(read_fd, buffer, sizeof(buffer)) > 0) {
            error_count++;
            printf("[Consumer] ERROR: %s | Total ERRORs: %d\n", buffer, error_count);
        }
    }
}
