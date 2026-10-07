#include <stdio.h>
#include <time.h>
#include <stdbool.h>

/* Historical Model 1:
   Mode-specific functions + shared int function[] state. */

void run_timer(int total_seconds) {
    printf("------The Wash Start------\n");
    time_t start_time = time(NULL);
    int seconds_elapsed = 0;

    while (seconds_elapsed < total_seconds) {
        time_t current_time = time(NULL);

        if (current_time - start_time > seconds_elapsed) {
            seconds_elapsed++;
            int seconds_remaining = total_seconds - seconds_elapsed;
            printf("\rWash will be complete in: %d second(s)", seconds_remaining);
            fflush(stdout);
        }
    }

    printf("\rWash will be complete in: 0 seconds\n");
    printf("Wash Complete!\n\n");
}

/*
 * The original Model 1 contained separate functions for modes such as:
 * blancket(), woolwash(), rinse_spin(), tubwash(), standard(),
 * quickwash(), jeans(), spin(), airdry(), aquawash(), normal().
 *
 * The complete historical source is preserved separately in the conversation
 * attachment that this project was derived from.
 */
int main(void) {
    printf("Historical Model 1 — see source attachment for the complete original.\n");
    return 0;
}
