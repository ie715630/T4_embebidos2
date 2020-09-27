/*
 * clock.c
 *
 *  Created on: 26 sep. 2020
 *      Author: kcdia
 */

#include <singleton_clock.h>

my_time_t g_time = {0, 0};

void set_time(my_time_t time_to_set) {
    set_seconds(time_to_set.seconds);
    set_minutes(time_to_set.minutes);
}

void ten_ms_handler(void) {
	static uint8_t tens_of_ms = 0;

	tens_of_ms++;

	if (100 == tens_of_ms) {
		tens_of_ms= 0;
        increment_seconds();
        PRINTF("\e[1;1H\e[2J");
        PRINTF("Hour %d:%d\r\n", g_time.minutes,  g_time.seconds);
    }
}

void increment_seconds(void) {
    uint8_t current_seconds = get_seconds() + 1;
    set_seconds(current_seconds);

    if(0 == get_seconds()) {
        increment_minutes();
    }
}

void increment_minutes(void) {
    uint8_t current_minutes = get_minutes() + 1;
    set_minutes(current_minutes);
}

uint8_t get_seconds(void) {
    return g_time.seconds;
}

uint8_t get_minutes(void) {
    return g_time.minutes;
}

void set_seconds(uint8_t sec) {
    if (60 > sec) {
        g_time.seconds = sec;
    } else {
        g_time.seconds = 0;
    }
}

void set_minutes(uint8_t min) {
    if (60 > min) {
        g_time.minutes = min;
    } else {
        g_time.minutes = 0;
    }
}
