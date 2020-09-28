/*
 * clock.c
 *
 *  Created on: 26 sep. 2020
 *      Author: kcdia
 */

#include <singleton_clock.h>

my_time_t g_time = {0, 0, 0};
my_time_t g_alarm = {0, 0, 0};
alarm_flag_t g_alarm_flags = {FALSE, FALSE, FALSE};

void set_time(my_time_t time_to_set)
{
    set_seconds(time_to_set.seconds);
    set_minutes(time_to_set.minutes);
    set_hours(time_to_set.hours);
}

void set_alarm(my_time_t time_to_set)
{
	g_alarm.seconds = time_to_set.seconds;
	g_alarm.minutes = time_to_set.minutes;
	g_alarm.hours = time_to_set.hours;
}

void ten_ms_handler(void)
{
	static uint8_t tens_of_ms = 0;

	tens_of_ms++;

	if (100 == tens_of_ms) {
		tens_of_ms= 0;
        increment_seconds();
        PRINTF("\e[1;1H\e[2J");
        PRINTF("Hour %d:%d\r\n", g_time.minutes,  g_time.seconds);
        if(TRUE == check_alarm())
        {
        	PRINTF("ALARMA\n");
        }
    }
}

void increment_seconds(void)
{
    uint8_t current_seconds = get_seconds() + 1;
    set_seconds(current_seconds);

    if(0 == get_seconds()) {
        increment_minutes();
    }

    if(g_alarm.seconds == get_seconds())
    {
    	g_alarm_flags.sec_alarm = TRUE;
    } else {
    	g_alarm_flags.sec_alarm = FALSE;
    }
}

void increment_minutes(void)
{
    uint8_t current_minutes = get_minutes() + 1;
    set_minutes(current_minutes);

    if(0 == get_minutes())
    {
    	increment_hours();
    }

    if(g_alarm.minutes == get_minutes())
    {
    	g_alarm_flags.min_alarm = TRUE;
    } else {
    	g_alarm_flags.min_alarm = FALSE;
    }
}

void increment_hours(void)
{
	uint8_t current_hours = get_hours() + 1;
	set_hours(current_hours);

    if(g_alarm.hours == get_hours())
    {
    	g_alarm_flags.hour_alarm = TRUE;
    } else {
    	g_alarm_flags.hour_alarm = FALSE;
    }
}

uint8_t get_seconds(void)
{
    return g_time.seconds;
}

uint8_t get_minutes(void)
{
    return g_time.minutes;
}

uint8_t get_hours(void)
{
	return g_time.hours;
}

void set_seconds(uint8_t sec)
{
    if (60 > sec)
    {
        g_time.seconds = sec;
    }
    else
    {
        g_time.seconds = 0;
    }
}

void set_minutes(uint8_t min)
{
    if (60 > min)
    {
        g_time.minutes = min;
    }
    else
    {
        g_time.minutes = 0;
    }
}

void set_hours(uint8_t hour)
{
	if (24 > hour)
	{
		g_time.hours = hour;
	}
	else
	{
		g_time.hours = 0;
	}
}

bool_t check_alarm(void)
{
	if(TRUE == g_alarm_flags.sec_alarm &&
	   TRUE == g_alarm_flags.min_alarm &&
	   TRUE == g_alarm_flags.hour_alarm)
	{
		g_alarm_flags.sec_alarm = FALSE;
		g_alarm_flags.min_alarm = FALSE;
		g_alarm_flags.hour_alarm = FALSE;
		return TRUE;
	} else {
		return FALSE;
	}
}
