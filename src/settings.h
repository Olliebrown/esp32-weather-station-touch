// SPDX-FileCopyrightText: 2023 ThingPulse Ltd., https://thingpulse.com
// SPDX-License-Identifier: MIT

#include "secrets.h"

#pragma once

#include <stdint.h>
#include <string>

// ****************************************************************************
// User settings
// ****************************************************************************
#ifndef SECRET_WIFI_USERNAME
#define SECRET_WIFI_USERNAME nullptr
#endif

// WiFi
const char *SSID = SECRET_WIFI_SSID;
const char *WIFI_PWD = SECRET_WIFI_PASSWORD;
const char *WIFI_USERNAME = SECRET_WIFI_USERNAME;
const char *WIFI_EAPID = SECRET_WIFI_USERNAME;

// timezone america/chicago as per https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv
#define TIMEZONE "CST6CDT,M3.2.0,M11.1.0"

#define UPDATE_INTERVAL_MINUTES 10

// uncomment to get "08/23/2022 02:55:02 pm" instead of "23.08.2022 14:55:02"
#define DATE_TIME_FORMAT_US

// values in metric or imperial system?
bool IS_METRIC = false;

// OpenWeatherMap Settings
// Sign up here to get an API key: https://docs.thingpulse.com/how-tos/openweathermap-key/
const String OPEN_WEATHER_MAP_API_KEY = SECRET_OPEN_WEATHER_MAP_API_KEY;
const String OPEN_WEATHER_MAP_HOST = "pro.openweathermap.org";

/*
Go to https://openweathermap.org/find?q= and search for a location. Go through the
result set and select the entry closest to the actual location you want to display
data for. It'll be a URL like https://openweathermap.org/city/2657896. The number
at the end is what you assign to the constant below.
 */
const String OPEN_WEATHER_MAP_LOCATION_ID = "5262634";
const String DISPLAYED_LOCATION_NAME = "Menomonie";
// String OPEN_WEATHER_MAP_LOCATION_ID = "4381072";
// String DISPLAYED_LOCATION_NAME = "Chesterfield";
// String OPEN_WEATHER_MAP_LOCATION_ID = "5254218";
// String DISPLAYED_LOCATION_NAME = "Germantown";

// Supported languages: https://openweathermap.org/current#multi
const String OPEN_WEATHER_MAP_LANGUAGE = "en";

const String WEEKDAYS[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const String WEEKDAYS_ABBR[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

const String SUN_MOON_LABEL[] = {"Sun", "Moon"};
const String MOON_PHASES[] = {"New Moon", "Waxing Crescent", "First Quarter", "Waxing Gibbous",
                              "Full Moon", "Waning Gibbous", "Third quarter", "Waning Crescent"};

// ****************************************************************************
// System settings - do not modify unless you understand what you are doing!
// ****************************************************************************
typedef struct RectangleDef
{
  uint16_t x;
  uint16_t y;
  uint16_t width;
  uint16_t height;
} RectangleDef;

typedef struct DayForecast
{
  float minTemp;
  float maxTemp;
  int conditionCode;
  int conditionHour;
  int day;
} DayForecast;

RectangleDef timeSpritePos = {0, 0, 320, 88};

const String WIND_ICON_NAMES[] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
const String WIND_DIR_NAMES[] = {"N", "NO", "O", "SO", "S", "SW", "W", "NW"};

// average approximation for the actual length of the synodic month
const double LUNAR_MONTH = 29.530588853;
const uint8_t NUMBER_OF_MOON_IMAGES = 32;

// 2: portrait, on/off switch right side -> 0/0 top left
// 3: landscape, on/off switch at the top -> 0/0 top left
#define TFT_ROTATION 3
// all other TFT_xyz flags are defined in platformio.ini as PIO build flags

// 0: portrait, on/off switch right side -> 0/0 top left
// 1: landscape, on/off switch at the top -> 0/0 top left
#define TOUCH_ROTATION 1
#define TOUCH_SENSITIVITY 40
#ifdef COLOR_KIT_GRANDE
#define TOUCH_SDA 23
#define TOUCH_SCL 22
#else
// TouchDown
#define TOUCH_SDA 21
#define TOUCH_SCL 22
#define TOUCH_IRQ 27
#define BUZZER_PIN 26
#endif

// Initial LCD Backlight brightness
#define TFT_LED_BRIGHTNESS 200
// Turn off LCD after given number of seconds (comment out for always on)
#define TFT_SLEEP_DELAY_SECONDS 60

// the medium blue in the TP logo is 0x0067B0 which converts to 0x0336 in 16bit RGB565
#define TFT_TP_BLUE 0x0336

// format specifiers: https://cplusplus.com/reference/ctime/strftime/
#ifdef DATE_TIME_FORMAT_US
int timePosX = 29;
#define UI_DATE_FORMAT "%m/%d/%Y"
#define UI_TIME_FORMAT "%I:%M:%S %P"
#define UI_TIME_FORMAT_NO_SECONDS "%I:%M %P"
#define UI_TIMESTAMP_FORMAT (UI_DATE_FORMAT + " " + UI_TIME_FORMAT)
#else
int timePosX = 68;
#define UI_DATE_FORMAT "%d.%m.%Y"
#define UI_TIME_FORMAT "%H:%M:%S"
#define UI_TIME_FORMAT_NO_SECONDS "%H:%M"
#define UI_TIMESTAMP_FORMAT (UI_DATE_FORMAT + " " + UI_TIME_FORMAT)
#endif

#define SYSTEM_TIMESTAMP_FORMAT "%Y-%m-%d %H:%M:%S"

// every 3h (UTC), we need all to be able to calculate daily min/max temperatures
const uint8_t forecastHoursUtc[] = {0, 3, 6, 9, 12, 15, 18, 21};
// 5 day / 3 hour forecast data => 8 forecasts/day => 40 total
#define NUMBER_OF_FORECASTS 40
#define NUMBER_OF_DAY_FORECASTS 4
#define NUMBER_OF_CLOSE_FORECASTS 8
// #define SKIP_TODAYS_FORECAST

#define APP_NAME "ESP32 Weather Station Touch"
#define VERSION "1.0.0"
