#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

void env(int size, int interval, char* env_name) {
    int result = 1;
    int status;
    int pid = fork();
    for (int i = 0; i < 10000000; i++) {
        if (i % 1000000 == 0) {
        	if (pid == 0) {
        		printf("%s %d/%d completed.\n", env_name, i, 10000000);
        	}
        }
        if (i % interval == 0) {
            result = result * size;
        }
    }
    while (wait(&status) > 0);
}

void env_large() {
    env(10000000, 10000000, "env_large");
}

void env_freq() {
    env(100, 100, "env_freq");
}

int main(int argc, char *argv[])
{
    env_large();
    env_freq();
    print_stats();   
    exit(0);
}