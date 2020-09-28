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

typedef enum {FALSE, TRUE} bool_t;

typedef struct {
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
} my_time_t;

typedef struct {
	bool_t sec_alarm;
	bool_t min_alarm;
	bool_t hour_alarm;
} alarm_flag_t;

void set_time(my_time_t time_to_set);
void set_alarm (my_time_t time_to_set);
void ten_ms_handler(void);
void increment_seconds(void);
void increment_minutes(void);
void increment_hours(void);

uint8_t get_seconds(void);
uint8_t get_minutes(void);
uint8_t get_hours(void);

void set_seconds(uint8_t sec);
void set_minutes(uint8_t min);
void set_hours(uint8_t hour);

bool_t check_alarm(void);
void print_time(void);

#endif /* SINGLETON_CLOCK_H_ */
