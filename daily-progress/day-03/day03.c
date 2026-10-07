/* Day 3 — loops and sensor-style logic */

#include <stdio.h>
#include <stdbool.h>

/* E3 — electrical current loop */
void current_loop(void) {
    float voltage;
    float current;

    scanf("%f", &voltage);

    for (int i = 1; i < 6; i++) {
        float resistance = i * 10.0f;
        current = voltage / resistance;
        printf("R = %.1f ohm, V = %.1f V, I = %.3f A\n",
               resistance, voltage, current);
    }
}

/* F — continuous motor temperature monitor */
void motor_monitor(void) {
    int temp;

    while (true) {
        printf("Enter temperature: ");
        scanf("%d", &temp);

        if (temp < 60)
            printf("Normal\n");
        else if (temp < 70)
            printf("Warning\n");
        else {
            printf("Stop motor\n");
            break;
        }
    }
}

int main(void) {
    return 0;
}
