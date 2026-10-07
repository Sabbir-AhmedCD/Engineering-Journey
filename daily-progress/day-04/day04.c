/* Day 4 — functions and modular electrical analysis */

#include <stdio.h>

float calculateCurrent(float voltage, float resistance) {
    return voltage / resistance;
}

float calculatePower(float voltage, float current) {
    return voltage * current;
}

int isSafeVoltage(float voltage) {
    if (voltage <= 12)
        return 1;
    return 0;
}

int checkTemperature(float temp) {
    if (temp < 60)
        return 2;   /* normal */
    else if (temp < 70)
        return 1;   /* warning */
    return 0;       /* danger */
}

int main(void) {
    float voltage, resistance, current, power, temp;
    int voltage_status, temperature_status;

    printf("Voltage: ");
    scanf("%f", &voltage);

    printf("Resistance: ");
    scanf("%f", &resistance);

    printf("Temperature: ");
    scanf("%f", &temp);

    current = calculateCurrent(voltage, resistance);
    power = calculatePower(voltage, current);
    voltage_status = isSafeVoltage(voltage);
    temperature_status = checkTemperature(temp);

    printf("Voltage = %.3f V\n", voltage);
    printf("Resistance = %.3f ohm\n", resistance);
    printf("Current = %.3f A\n", current);
    printf("Power = %.3f W\n", power);

    return 0;
}
