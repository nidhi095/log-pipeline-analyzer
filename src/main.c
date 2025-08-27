#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


void producer(int write_fd);
void processor(int read_fd, int write_fd);
void consumer(int read_fd);

int main() {
    int pipe1[2], pipe2[2];
    pipe(pipe1); // producer -> processor
    pipe(pipe2); // processor -> consumer

    pid_t pid1 = fork();
    if (pid1 == 0) { // Producer
        close(pipe1[0]); // close read end
        producer(pipe1[1]);
        exit(0);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) { // Processor
        close(pipe1[1]);
        close(pipe2[0]);
        processor(pipe1[0], pipe2[1]);
        exit(0);
    }

    pid_t pid3 = fork();
    if (pid3 == 0) { // Consumer
        close(pipe2[1]);
        consumer(pipe2[0]);
        exit(0);
    }

    // Parent: close all pipes and wait for children
    close(pipe1[0]); close(pipe1[1]);
    close(pipe2[0]); close(pipe2[1]);

    signal(SIGINT, SIG_IGN); // ignore Ctrl+C in parent
    wait(NULL); wait(NULL); wait(NULL);

    return 0;
}
