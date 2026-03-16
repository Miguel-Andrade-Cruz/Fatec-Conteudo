#include <stdio.h>
#include <string.h>

void clear_buffer();

void ask_date(int *day, int *month, int *year);

int leap_year_check(int year);

int calculate_total_leap_years(int year);

int get_days_since_start_point(int day, int month, int year, int is_leap_year, int total_leap_years);

void resolve_weekday(int days_since_start_point, char *weekday);

void show_weekday_date(int day, int month, int year, char *weekday);