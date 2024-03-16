#include <stdio.h>
#include <time.h>

int main() {
    struct timespec req, rem;

    // Define the time to sleep (2 seconds and 500 milliseconds)
    req.tv_sec = 2;
    req.tv_nsec = 500000000;

    printf("Sleeping for 2 seconds and 500 milliseconds...\n");

    // Call nanosleep() with the defined time
    int result = nanosleep(&req, &rem);

    // Check if nanosleep() encountered an error
    if (result == -1) {
        printf("nanosleep() failed.\n");
        return 1;
    }

    // If nanosleep() was interrupted, print remaining time
    if (result == 0 && rem.tv_sec > 0) {
        printf("Sleep interrupted. Remaining time: %ld seconds %ld nanoseconds.\n", rem.tv_sec, rem.tv_nsec);
    } else {
        printf("Sleep completed.\n");
    }

    return 0;
}
