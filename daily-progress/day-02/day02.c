/* Day 2 — decision logic snapshot */

#include <stdio.h>

/* Largest + smallest revision */
void largest_smallest(void) {
    int a, b, c;
    int largest, smallest;

    scanf("%d %d %d", &a, &b, &c);

    largest = a;
    smallest = a;

    if (b > largest) largest = b;
    if (c > largest) largest = c;

    if (b < smallest) smallest = b;
    if (c < smallest) smallest = c;

    printf("largest = %d\n", largest);
    printf("smallest = %d\n", smallest);
}

/* Overvoltage experiment */
void overvoltage(void) {
    int voltage;
    scanf("%d", &voltage);

    if (voltage < 5)
        printf("Normal\n");
    else if (voltage < 12)
        printf("High\n");
    else
        printf("Danger\n");
}

/* Motor safety experiment */
void motor_safety(void) {
    int voltage, temperature;
    scanf("%d", &voltage);
    scanf("%d", &temperature);

    if (voltage <= 12 && temperature < 70)
        printf("SAFE TO RUN\n");
    else
        printf("STOP MOTOR\n");
}

int main(void) {
    return 0;
}
