/*
 * clock.h
 *
 *  Created on: 26 sep. 2020
 *      Author: kcdia
 */

#ifndef SINGLETON_CLOCK_H_
#define SINGLETON_CLOCK_H_

#include <stdint.h>
#include "fsl_debug_console.h"

typedef struct {
    uint8_t seconds;
    uint8_t minutes;
} my_time_t;

void set_time(my_time_t time_to_set);
void ten_ms_handler(void);
void increment_seconds(void);
void increment_minutes(void);
void incremnet_hours(void);

uint8_t get_seconds(void);
uint8_t get_minutes(void);
void set_seconds(uint8_t sec);
void set_minutes(uint8_t min);

#endif /* SINGLETON_CLOCK_H_ */
