// By default the sensor is tuned for a thin vinyl surface, to adjust for a 3mm acrylic surface set the following
// #define MXT_SURFACE_TYPE ACRYLIC

// Hardware smoothing: Low-pass filter coefficient (0-15, higher = more smoothing, default: 0 = 5)
// Increase this value to reduce jumpiness, especially with multiple layers of vinyl
#define MXT_LOW_PASS_FILTER_COEFFICIENT 10

// Software smoothing: Sensitivity divisor (higher = less sensitive, default: 1)
// Divide mouse movement by this value to reduce sensitivity
#ifndef POINTING_DEVICE_SENSITIVITY_DIVISOR
#define POINTING_DEVICE_SENSITIVITY_DIVISOR 2
#endif

// Software smoothing: Exponential moving average alpha (0-255, higher = less smoothing, default: 128 = 50%)
// Lower values = more smoothing but more lag
#ifndef POINTING_DEVICE_SMOOTHING_ALPHA
#define POINTING_DEVICE_SMOOTHING_ALPHA 192  // ~75% new, 25% old (less smoothing, more responsive)
#endif

// Movement threshold: Minimum accumulated movement before reporting (higher = less jitter, but more lag for tiny movements)
// This filters out sensor noise when finger is stationary
#ifndef POINTING_DEVICE_MOVEMENT_THRESHOLD
#define POINTING_DEVICE_MOVEMENT_THRESHOLD 2  // pixels (after sensitivity divisor)
#endif

// macOS trackpad mode configuration
// Timeout before resetting scan_time after inactivity (Microsoft PTP requirement)
#define DIGITIZER_INACTIVITY_TIMEOUT_MS 1000
// Multiplier to convert timer ticks to 100us units (Microsoft PTP requires scan_time in 100us ticks)
#define DIGITIZER_SCAN_TIME_MULTIPLIER 10
