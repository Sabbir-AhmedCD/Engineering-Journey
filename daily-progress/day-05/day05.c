/* Day 5 — temperature sensor data analyzer */

#include <stdio.h>

float calculateAverage(float sum, int size) {
    return sum / size;
}

float findMaximum(float temp[], int size) {
    float max = temp[0];

    for (int i = 1; i < size; i++) {
        if (temp[i] > max)
            max = temp[i];
    }

    return max;
}

float findMinimum(float temp[], int size) {
    float min = temp[0];

    for (int i = 1; i < size; i++) {
        if (temp[i] < min)
            min = temp[i];
    }

    return min;
}

int main(void) {
    float temp[10];
    float sum = 0.0f;
    int hasDanger = 0;
    int hasWarning = 0;
    int count60 = 0;
    int count70 = 0;

    for (int i = 0; i < 10; i++) {
        printf("Temperature %d: ", i + 1);
        scanf("%f", &temp[i]);
        sum += temp[i];
    }

    for (int i = 0; i < 10; i++) {
        if (temp[i] >= 70) {
            hasDanger = 1;
            count70++;
            count60++;
        } else if (temp[i] >= 60) {
            hasWarning = 1;
            count60++;
        }
    }

    printf("Average = %.2f\n", calculateAverage(sum, 10));
    printf("Maximum = %.2f\n", findMaximum(temp, 10));
    printf("Minimum = %.2f\n", findMinimum(temp, 10));
    printf("Readings >= 60C = %d\n", count60);
    printf("Readings >= 70C = %d\n", count70);

    if (hasDanger)
        printf("Final Status: Danger\n");
    else if (hasWarning)
        printf("Final Status: Warning\n");
    else
        printf("Final Status: Normal\n");

    return 0;
}
