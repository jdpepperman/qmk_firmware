// Mouse settings
#define MOUSEKEY_DELAY                              10
#define MOUSEKEY_INTERVAL                           16
#define MOUSEKEY_MAX_SPEED                          2
#define MOUSEKEY_TIME_TO_MAX                        30
#define MOUSEKEY_CURVE                              300
#define MOUSEKEY_WHEEL_DELAY                        50
#define MOUSEKEY_WHEEL_MAX_SPEED                    1
#define MOUSEKEY_WHEEL_MAX_TIME_TO_MAX              100

#define TAPPING_TOGGLE 2 // This makes TT only take 2 taps to activate the layer.

// Auto shift settings
#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define AUTO_SHIFT_TIMEOUT 145
// #define NO_AUTO_SHIFT_SPECIAL

#endif // CONFIG_USER_H

// This one feels pretty good.
// #define MOUSEKEY_DELAY                              10
// #define MOUSEKEY_INTERVAL                           16
// #define MOUSEKEY_MAX_SPEED                          2
// #define MOUSEKEY_TIME_TO_MAX                        30
// #define MOUSEKEY_CURVE                              300
// #define MOUSEKEY_WHEEL_MAX_SPEED                    8
// #define MOUSEKEY_WHEEL_MAX_TIME_TO_MAX              90

// This is close to good, too slow in the beginning.
// #define MOUSEKEY_DELAY                              100
// #define MOUSEKEY_INTERVAL                           16
// #define MOUSEKEY_MAX_SPEED                          2
// #define MOUSEKEY_TIME_TO_MAX                        100
// #define MOUSEKEY_WHEEL_MAX_SPEED                    8
// #define MOUSEKEY_WHEEL_MAX_TIME_TO_MAX              90
// #define MOUSEKEY_CURVE                              0

// Still way too fast.
// #define MOUSEKEY_DELAY                              100
// #define MOUSEKEY_INTERVAL                           16
// #define MOUSEKEY_MAX_SPEED                          5
// #define MOUSEKEY_TIME_TO_MAX                        50
// #define MOUSEKEY_WHEEL_MAX_SPEED                    8
// #define MOUSEKEY_WHEEL_MAX_TIME_TO_MAX              90

// This was too slow at max speed.
// #define MOUSEKEY_DELAY                              100
// #define MOUSEKEY_INTERVAL                           16
// #define MOUSEKEY_MAX_SPEED                          1
// #define MOUSEKEY_TIME_TO_MAX                        100
// #define MOUSEKEY_WHEEL_MAX_SPEED                    8
// #define MOUSEKEY_WHEEL_MAX_TIME_TO_MAX              90

// This was really fast after too short a time.
// #define MOUSEKEY_DELAY                              100
// #define MOUSEKEY_INTERVAL                           16
// #define MOUSEKEY_MAX_SPEED                          10
// #define MOUSEKEY_TIME_TO_MAX                        100
// #define MOUSEKEY_WHEEL_MAX_SPEED                    8
// #define MOUSEKEY_WHEEL_MAX_TIME_TO_MAX              90