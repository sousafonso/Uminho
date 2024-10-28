#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/time.h"

struct DateTime {
    int year, month, day, hour, minute, second;
};

static struct DateTime parseDateTime(char *dateStr) {
    struct DateTime dt;
    sscanf(dateStr, "%d/%d/%d %d:%d:%d", &dt.year, &dt.month, &dt.day, &dt.hour, &dt.minute, &dt.second);
    return dt;
}

// Calcular o número de dias entre duas datas no formato YYYY/MM/DD
int days_time(char *begin_date, char *end_date) {

if(begin_date == NULL || end_date == NULL) return -1;

  char date1[3], date2[3];

  date1[2] = '\0';
  date1[0] = begin_date[8];
  date1[1] = begin_date[9];

  date2[2] = '\0';
  date2[0] = end_date[8];
  date2[1] = end_date[9];

  int days = atoi(date2) - atoi(date1);
  return days;
}

//calcula a diferença dos tempos em segundos
static int time_differenceIn_seconds(char *date1, char *date2) {
    struct DateTime dt1 = parseDateTime(date1);
    struct DateTime dt2 = parseDateTime(date2);

    int daysInMonth = 31;

    time_t time1 = dt1.second + 60 * (dt1.minute + 60 * (dt1.hour + 24 * (dt1.day - 1 + daysInMonth * (dt1.month - 1 + 12 * (dt1.year - 1)))));
    time_t time2 = dt2.second + 60 * (dt2.minute + 60 * (dt2.hour + 24 * (dt2.day - 1 + daysInMonth * (dt2.month - 1 + 12 * (dt2.year - 1)))));

    return (int)difftime(time1, time2);
}

int calculate_tempo_atraso(char *arrival_fake, char *arrival_real){

    char *chegada_fake = malloc(sizeof(char) * 20);
    strcpy(chegada_fake, arrival_fake);

    char *chegada_real = malloc(sizeof(char) * 20);
    strcpy(chegada_real, arrival_real);

    int difference = time_differenceIn_seconds(chegada_real, chegada_fake);

    free(chegada_fake);
    free(chegada_real);

    return difference;
}

// Comparar duas datas no formato YYYY/MM/DD HH:MM:SS
int days_time_all(char *begin_date, char *end_date) {
if(begin_date == NULL || end_date == NULL) return -1;

  int days = 0;

  char date1d[3], date2d[3], date1m[3], date2m[3], date1y[5], date2y[5];

  date1d[2] = '\0';
  date1d[0] = begin_date[8];
  date1d[1] = begin_date[9];

  date2d[2] = '\0';
  date2d[0] = end_date[8];
  date2d[1] = end_date[9];

  date1m[2] = '\0';
  date1m[0] = begin_date[5];
  date1m[1] = begin_date[6];

  date2m[2] = '\0';
  date2m[0] = end_date[5];
  date2m[1] = end_date[6];

  date1y[4] = '\0';
  date1y[0] = begin_date[0];
  date1y[1] = begin_date[1];
  date1y[2] = begin_date[2];
  date1y[3] = begin_date[3];

  date2y[4] = '\0';
  date2y[0] = end_date[0];
  date2y[1] = end_date[1];
  date2y[2] = end_date[2];
  date2y[3] = end_date[3];

  days += (atoi(date2y) - atoi(date1y)) * 372;
  days += (atoi(date2m) - atoi(date1m)) * 31;
  days += atoi(date2d) - atoi(date1d);

  return days;
}

int seconds_time_all(char *begin_date, char *end_date) {
if(begin_date == NULL || end_date == NULL) return -1;

  int days = 0;

  char date1d[3], date2d[3], date1m[3], date1h[3], date1min[3], date1s[3], date2m[3], date1y[5], date2y[5], date2h[3], date2min[3], date2s[3];

  date1d[2] = '\0';
  date1d[0] = begin_date[8];
  date1d[1] = begin_date[9];

  date1m[2] = '\0';
  date1m[0] = begin_date[5];
  date1m[1] = begin_date[6];

  date1y[4] = '\0';
  date1y[0] = begin_date[0];
  date1y[1] = begin_date[1];
  date1y[2] = begin_date[2];
  date1y[3] = begin_date[3];

  date1h[2] = '\0';
  date1h[0] = begin_date[11];
  date1h[1] = begin_date[12];

  date1min[2] = '\0';
  date1min[0] = begin_date[14];
  date1min[1] = begin_date[15];

  date1s[2] = '\0';
  date1s[0] = begin_date[17];
  date1s[1] = begin_date[18];

  date2d[2] = '\0';
  date2d[0] = end_date[8];
  date2d[1] = end_date[9];

  date2m[2] = '\0';
  date2m[0] = end_date[5];
  date2m[1] = end_date[6];

  date2y[4] = '\0';
  date2y[0] = end_date[0];
  date2y[1] = end_date[1];
  date2y[2] = end_date[2];
  date2y[3] = end_date[3];

  date2h[2] = '\0';
  date2h[0] = end_date[11];
  date2h[1] = end_date[12];

  date2min[2] = '\0';
  date2min[0] = end_date[14];
  date2min[1] = end_date[15];

  date2s[2] = '\0';
  date2s[0] = end_date[17];
  date2s[1] = end_date[18];

  days += (atoi(date2y) - atoi(date1y)) * 12 * 31 * 24 * 3600;
  days += (atoi(date2m) - atoi(date1m)) * 31 * 24 * 3600;
  days += (atoi(date2d) - atoi(date1d)) * 24 * 3600;
  days += (atoi(date2h) - atoi(date1h)) * 3600;
  days += (atoi(date2min) - atoi(date1min)) * 60;
  days += (atoi(date2s) - atoi(date1s));

  return days;
}