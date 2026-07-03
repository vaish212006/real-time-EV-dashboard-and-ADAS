#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

#include "stm32f1xx_hal.h"

/* ══════════════════════════════════════════════════════════════════
   BLUE PILL (STM32F103C8T6) PIN CONFIGURATION
   System Clock: 72 MHz (HSE 8 MHz × PLL 9)
   ══════════════════════════════════════════════════════════════════ */

/* ─── UART CONFIGURATION ──────────────────────────────────────────── */
#define UART_PORT           USART1
#define UART_TX_PORT        GPIOA
#define UART_TX_PIN         GPIO_PIN_9
#define UART_RX_PORT        GPIOA
#define UART_RX_PIN         GPIO_PIN_10
#define UART_BAUDRATE       115200
#define UART_WORDLENGTH     UART_WORDLENGTH_8B
#define UART_STOPBITS       UART_STOPBITS_1
#define UART_PARITY         UART_PARITY_NONE
#define UART_HWCONTROL      UART_HWCONTROL_NONE
#define UART_OVERSAMPLING   UART_OVERSAMPLING_16

/* ─── ULTRASONIC SENSOR CONFIGURATION ─────────────────────────────── */
/* HC-SR04 Sensors: TRIG (output) and ECHO (input) */

/* Sensor 1 (Front Center) */
#define SENSOR1_TRIG_PORT   GPIOA
#define SENSOR1_TRIG_PIN    GPIO_PIN_0
#define SENSOR1_ECHO_PORT   GPIOA
#define SENSOR1_ECHO_PIN    GPIO_PIN_1
#define SENSOR1_NAME        "Front Center"

/* Sensor 2 (Right Side) */
#define SENSOR2_TRIG_PORT   GPIOA
#define SENSOR2_TRIG_PIN    GPIO_PIN_2
#define SENSOR2_ECHO_PORT   GPIOA
#define SENSOR2_ECHO_PIN    GPIO_PIN_3
#define SENSOR2_NAME        "Right Side"

/* Sensor 3 (Left Side) */
#define SENSOR3_TRIG_PORT   GPIOA
#define SENSOR3_TRIG_PIN    GPIO_PIN_4
#define SENSOR3_ECHO_PORT   GPIOA
#define SENSOR3_ECHO_PIN    GPIO_PIN_5
#define SENSOR3_NAME        "Left Side"

#define NUM_ULTRASONIC_SENSORS  3

/* ─── TIMER CONFIGURATION ──────────────────────────────────────────── */
/* TIM2: Used for microsecond-precision delay and pulse measurement */
#define MICROSECOND_TIMER   TIM2
#define TIMER_PRESCALER     71        /* 72 MHz / 72 = 1 MHz (1 µs/tick) */
#define TIMER_PERIOD        0xFFFF    /* 65535 µs max (~65 ms) */

/* ─── TIMING CONSTANTS ──────────────────────────────────────────────── */
#define HCSR04_TRIG_PULSE_US    10      /* 10 µs trigger pulse */
#define HCSR04_TIMEOUT_US       30000   /* 30 ms timeout (~5 m max) */
#define SENSOR_READ_DELAY_MS    60      /* Delay between sensor reads (avoid crosstalk) */
#define SCAN_CYCLE_DELAY_MS     500     /* Delay between full scan cycles */

/* ─── DISTANCE THRESHOLDS FOR ADAS ──────────────────────────────────── */
#define COLLISION_WARNING_THRESHOLD_CM      50      /* 50 cm - immediate danger */
#define OBSTACLE_CAUTION_THRESHOLD_CM       100     /* 100 cm - caution zone */
#define BLIND_SPOT_MONITOR_THRESHOLD_CM     150     /* 150 cm - blind spot alert */
#define MAX_MEASUREMENT_RANGE_CM            400     /* Maximum reliable range */

/* ─── FUTURE EXPANSIONS ────────────────────────────────────────────── */
/* Reserved for future pins: Battery monitoring (ADC), CAN bus, I2C display, etc. */

/* Battery Voltage Monitor (ADC1_IN0) */
#define BATT_MONITOR_PORT   GPIOA
#define BATT_MONITOR_PIN    GPIO_PIN_0      /* ADC1 Channel 0 */
#define BATT_ADC_CHANNEL    ADC_CHANNEL_0

/* CAN Bus (Future) */
#define CAN_RX_PORT         GPIOA
#define CAN_RX_PIN          GPIO_PIN_11
#define CAN_TX_PORT         GPIOA
#define CAN_TX_PIN          GPIO_PIN_12

/* I2C Display (SSD1306 128x64 OLED) */
#define I2C_PORT            I2C1
#define I2C_SDA_PORT        GPIOB
#define I2C_SDA_PIN         GPIO_PIN_7
#define I2C_SCL_PORT        GPIOB
#define I2C_SCL_PIN         GPIO_PIN_6

#endif /* PIN_CONFIG_H */
