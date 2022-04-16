#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void example_pause_system(int interval, int pause_seconds, int loop_size) {
    // int n_forks = 2;
    // for (int i = 0; i < n_forks; i++) {
    // 	fork();
    // }
    fork();
    for (int i = 0; i < loop_size; i++) {
        if (i % interval == 0) {
            printf("pause system %d/%d completed.\n", i, loop_size);
        }
        if (i == (loop_size / 2)){
            pause_system(pause_seconds);
        }
    }
    printf("\n");
}

void example_kill_system(int interval, int loop_size) {
    int n_forks = 2;
    for (int i = 0; i < n_forks; i++) {
    	fork();
    }
    for (int i = 0; i < loop_size; i++) {
        if (i % interval == 0) {
            printf("kill system %d/%d completed.\n", i, loop_size);
        }
        if (i == (loop_size / 2)){
            kill_system();
        }
    }
    printf("\n");
}

int
main(int argc, char *argv[])
{
  printf("going to pause everyone\n");
  example_pause_system(1, 10, 10);
//   example_kill_system(1, 10);
  exit(0);
}