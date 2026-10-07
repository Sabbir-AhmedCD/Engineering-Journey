/* Day 1 — C practice snapshot */

#include <stdio.h>

/* 1. Ohm's Law */
void ohms_law(void) {
    char choice;
    float v, i, r;

    printf("what do you want to find? v, i, or r: ");
    scanf(" %c", &choice);

    if (choice == 'v') {
        printf("enter i: ");
        scanf("%f", &i);
        printf("enter r: ");
        scanf("%f", &r);
        printf("voltage is: %f\n", i * r);
    }
    if (choice == 'i') {
        printf("enter v: ");
        scanf("%f", &v);
        printf("enter r: ");
        scanf("%f", &r);
        printf("current is: %f\n", v / r);
    }
    if (choice == 'r') {
        printf("enter v: ");
        scanf("%f", &v);
        printf("enter i: ");
        scanf("%f", &i);
        printf("resistance is: %f\n", v / i);
    }
}

/* 2. Electrical Power */
void power_calculator(void) {
    int type;
    float v, i, r, p;

    printf("1 for v and i\n2 for i and r\n3 for v and r\n");
    printf("enter choice: ");
    scanf("%d", &type);

    if (type == 1) {
        scanf("%f", &v);
        scanf("%f", &i);
        p = v * i;
        printf("power is: %f\n", p);
    }
    if (type == 2) {
        scanf("%f", &i);
        scanf("%f", &r);
        p = i * i * r;
        printf("power is: %f\n", p);
    }
    if (type == 3) {
        scanf("%f", &v);
        scanf("%f", &r);
        p = (v * v) / r;
        printf("power is: %f\n", p);
    }
}

/* 3. Temperature conversion */
void temperature_converter(void) {
    char unit;
    float temp, ans;

    printf("press c for celsius or f for fahrenheit: ");
    scanf(" %c", &unit);

    if (unit == 'c') {
        scanf("%f", &temp);
        ans = (temp * 9.0 / 5.0) + 32.0;
        printf("temperature in fahrenheit: %f\n", ans);
    }
    if (unit == 'f') {
        scanf("%f", &temp);
        ans = (temp - 32.0) * 5.0 / 9.0;
        printf("temperature in celsius: %f\n", ans);
    }
}

/* 4. Even / odd */
void even_odd(void) {
    int x;
    printf("enter a number: ");
    scanf("%d", &x);

    if (x % 2 == 0)
        printf("this number is even\n");
    else
        printf("this number is odd\n");
}

/* 5. Largest of three */
void largest_three(void) {
    int a, b, c;

    printf("enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a > b) {
        if (a > c) printf("largest is %d\n", a);
    }
    if (b > a) {
        if (b > c) printf("largest is %d\n", b);
    }
    if (c > a) {
        if (c > b) printf("largest is %d\n", c);
    }
}

int main(void) {
    printf("Run these functions one at a time while learning.\n");
    return 0;
}
