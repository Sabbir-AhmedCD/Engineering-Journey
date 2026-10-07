# Washing Machine Controller

A C programming project that evolved through two architectural approaches.

## Model 1 — procedural version

The first version used a separate function for each wash mode and shared integer
configuration storage.

Main lessons:
- loops
- input validation
- functions
- arrays used as shared state
- repeated code and the cost of duplication

## Model 2 — data-driven version

The second version introduced:

- `struct`
- array of `WashMode` structures
- one reusable `run_mode()` handler
- reusable input validation
- automatic mode listing
- timer function

This was the first time I deliberately changed the architecture instead of just
adding more code.

## Example data model

```c
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
```

## Known next improvements

- Allow multiple settings to be changed before starting.
- Make total cycle time depend on the selected settings instead of a fixed timer.
- Handle non-numeric `scanf()` input safely.
- Replace busy-wait timing with a more appropriate timing design.
- Separate machine state from user configuration.
- Eventually model the cycle as explicit states: fill → soak → wash → rinse → spin → dry.
