#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "utils.h"

void producer(int write_fd) {
    FILE *file = fopen("logs/sample.log", "r");
    if (!file) {
        perror("Unable to open log file");
        exit(1);
    }

    char line[1024];
    fseek(file, 0, SEEK_END); // Start at end to read new entries

    while (1) {
        if (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = '\0'; // remove newline
            write_line(write_fd, line);
        } else {
            usleep(500000); // sleep 0.5 sec
        }
    }

    fclose(file);
}
