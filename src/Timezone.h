/*----------------------------------------------------------------------*
 * Arduino Timezone Library                                             *
 * Jack Christensen Mar 2012                                            *
 *                                                                      *
 * Arduino Timezone Library Copyright (C) 2018 by Jack Christensen and  *
 * licensed under GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html   *
 *----------------------------------------------------------------------*/ 

#ifndef TIMEZONE_H_INCLUDED
#define TIMEZONE_H_INCLUDED
#if ARDUINO >= 100
#include <Arduino.h> 
#else
//#include <WProgram.h>
#endif
#include <TimeLib.h>    // https://github.com/PaulStoffregen/Time

#include <stdbool.h>

// convenient constants for TimeChangeRules
typedef enum
{
	Last,
	First,
	Second,
	Third,
	Fourth
} week_t;
typedef enum
{
	Sun=1,
	Mon,
	Tue,
	Wed,
	Thu,
	Fri,
	Sat
} dow_t;
typedef enum
{
	Jan=1,
	Feb,
	Mar,
	Apr,
	May,
	Jun,
	Jul,
	Aug,
	Sep,
	Oct,
	Nov,
	Dec
} month_t;

// structure to describe rules for when daylight/summer time begins,
// or when standard time begins.
typedef struct
{
    char abbrev[6];    // five chars max
    uint8_t week;      // First, Second, Third, Fourth, or Last week of the month
    uint8_t dow;       // day of week, 1=Sun, 2=Mon, ... 7=Sat
    uint8_t month;     // 1=Jan, 2=Feb, ... 12=Dec
    uint8_t hour;      // 0-23
    int offset;        // offset from UTC in minutes
} TimeChangeRule;
        
void Timezone(TimeChangeRule *dstStart, TimeChangeRule *stdStart);
void TimezoneNoDST(TimeChangeRule *stdTime);
time_t toLocal(time_t utc);
time_t toLocalTcr(time_t utc, TimeChangeRule **tcr);
time_t toUTC(time_t local);
bool utcIsDST(time_t utc);
bool locIsDST(time_t local);
void setRules(TimeChangeRule *dstStart, TimeChangeRule *stdStart);

#endif
