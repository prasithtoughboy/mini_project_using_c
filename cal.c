/*
 *Pass by refernce example to dislplay the day using double pointers
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define MAX 10
int cal (int date_inp, char *month_inp,char **op_day)
{
char ptr[10]="\0";
  int i, mon_num = 0;

  int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  char *day_name[] =
    {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday" };

//Assigning month number to each month
  if (strncmp (month_inp, "january",MAX) == 0)
    mon_num = 1;
  if (strncmp (month_inp, "february",MAX) == 0)
    mon_num = 2;
  if (strncmp (month_inp, "march",MAX) == 0)
    mon_num = 3;
  if (strncmp (month_inp, "april",MAX) == 0)
    mon_num = 4;
  if (strncmp (month_inp, "may",MAX) == 0)
    mon_num = 5;
  if (strncmp (month_inp, "june",MAX) == 0)
    mon_num = 6;
  if (strncmp (month_inp, "july",MAX) == 0)
    mon_num = 7;
  if (strncmp (month_inp, "august",MAX) == 0)
    mon_num = 8;
  if (strncmp (month_inp, "september",MAX) == 0)
    mon_num = 9;
  if (strncmp (month_inp, "october",MAX) == 0)
    mon_num = 10;
  if (strncmp (month_inp, "november",MAX) == 0)
    mon_num = 11;
  if (strncmp (month_inp, "december",MAX) == 0)
    mon_num = 12;

//Adding the number of days till the required month and the date, and as a result giving the day name
  int logic_sum=date_inp;
    for (i = 0; i < mon_num - 1; i++)
    logic_sum += month_days[i];
 
	strncpy(ptr,day_name[logic_sum%7],MAX);
//Inserting the day name in the referece pointer that changes the value of the day variable in the main file
	*op_day=ptr;		//TODO: Check how to copy pointer to pointer the right way!
  return 0;
}	



