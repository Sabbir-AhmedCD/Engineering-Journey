#include <stdio.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    char name[30];
    int water;
    int soak;
    int temp;
    int spin_rpm;
    int rinse;
    int dry_time;
    int timer_sec;
} WashMode;

WashMode modes[] = {
    {"Normal",     10, 25, 30, 350, 2, 30, 25},
    {"Aqua Wash",  10, 25, 30, 350, 2, 30, 34},
    {"Blanket",    10, 30, 30, 750, 4, 40, 65},
    {"Wool Wash",   8, 30, 30, 400, 4, 35, 65},
    {"Rinse & Spin",0,  0,  0, 750, 4,  0, 31},
    {"Tub Wash",   10, 25, 30, 350, 2, 30, 34},
    {"Standard",   10, 25, 30, 350, 2, 30, 34},
    {"Quick Wash", 10, 25, 30, 350, 2, 30, 34},
    {"Jeans",      10, 25, 30, 350, 2, 30, 34},
    {"Spin Only",   0,  0,  0, 400, 0,  0, 30},
    {"Air Dry",     0,  0,  0,   0, 0, 30, 30}
};

void run_timer(int total_seconds) {
    printf("------The Wash Start------\n");
    time_t start_time = time(NULL);
    int seconds_elapsed = 0;

    while (seconds_elapsed < total_seconds) {
        time_t current_time = time(NULL);

        if (current_time - start_time > seconds_elapsed) {
            seconds_elapsed++;
            printf("\rWash will be complete in: %d second(s)",
                   total_seconds - seconds_elapsed);
            fflush(stdout);
        }
    }

    printf("\rWash will be complete in: 0 seconds\n");
    printf("Wash Complete!\n\n");
}

int get_valid_input(const char *prompt, int min, int max) {
    int val;

    while (1) {
        printf("%s", prompt);
        scanf("%d", &val);

        if (val >= min && val <= max)
            return val;

        printf("Invalid input! Please enter a value between %d and %d.\n",
               min, max);
    }
}

void run_mode(int mode_idx) {
    WashMode current = modes[mode_idx];
    int change;

    printf("\n----- %s Mode -----\n", current.name);
    printf("1. Water    : %dL\n", current.water);
    printf("2. Soak     : %dmin\n", current.soak);
    printf("3. Wash temp: %d°C\n", current.temp);
    printf("4. Spin speed: %d RPM\n", current.spin_rpm);
    printf("5. Rinse    : %d times\n", current.rinse);
    printf("6. Dry time : %d min\n", current.dry_time);

    printf("\nWanna Change anything?\nType Option Num (1-6) to edit, or '0' to start: ");
    scanf("%d", &change);

    switch (change) {
        case 0: break;
        case 1:
            current.water = get_valid_input("Water (1-10L): ", 1, 10);
            break;
        case 2:
            current.soak = get_valid_input("Soak (0-60min): ", 0, 60);
            break;
        case 3:
            current.temp = get_valid_input("Wash Temp (10-90°C): ", 10, 90);
            break;
        case 4:
            current.spin_rpm = get_valid_input("Spin (100-800 RPM): ", 100, 800);
            break;
        case 5:
            current.rinse = get_valid_input("Rinse (1-4 times): ", 1, 4);
            break;
        case 6:
            current.dry_time = get_valid_input("Dry time (10-90min): ", 10, 90);
            break;
        default:
            printf("Starting default wash settings...\n");
            break;
    }

    run_timer(current.timer_sec);
}

int main(void) {
    int choice;
    int mode_choice;
    int num_modes = sizeof(modes) / sizeof(modes[0]);

    printf("------ Washing Machine ------\n");

    while (true) {
        printf("\nChoose an option:\n 1. Off\n 2. Quick Normal Wash\n 3. Wash Modes Selection\nType: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Turning Off...\n----- Tu Tu Tu -----\n");
            break;
        }
        else if (choice == 2) {
            run_mode(0);
        }
        else if (choice == 3) {
            printf("\n------ Wash Modes ------\n");

            for (int i = 0; i < num_modes; i++) {
                printf("%2d. %s\n", i + 1, modes[i].name);
            }

            mode_choice = get_valid_input("Select Mode: ", 1, num_modes);
            run_mode(mode_choice - 1);
        }
    }

    return 0;
}
