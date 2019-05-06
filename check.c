#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
#define MAX 10
static int init_lib=0;

const char *error_msg(enum check_error err){
 switch(err){
 case invalid_date:
  return "invalid date\n";
 case invalid_month:
  return "invalid month\n";
 case invalid_feb_date:
  return "invalid feb date\n";
 case no_error:
  return "no error\n";
 case no_init:
 return "library is not initialised\n\n";
 default:
  return "unknown\n";
 }
}

enum check_error error(int date, char month[]){
int count=0;
//Check boundary values for 31 day months
  if((strncmp (month, "january",MAX) == 0)
           || (strncmp (month, "march",MAX) == 0)
           || (strncmp (month, "august",MAX) == 0) || (strncmp (month, "december",MAX) == 0)
           || (strncmp (month, "may",MAX) == 0) || (strncmp (month, "october",MAX) == 0)
           || (strncmp (month, "july",MAX) == 0))
        {

                if(date < 1 || date > 31)
                        return invalid_date;
        }
//Check boundary values for 30 day months
   if ((strncmp (month, "april",MAX) == 0)
           || (strncmp (month, "june",MAX) == 0)
           || (strncmp (month, "september",MAX) == 0) || (strncmp (month, "november",MAX) == 0))
        {
                if(date < 1 || date > 30)
                return invalid_date;
        }

//Check boundary conditions for february
  if (strncmp (month, "february",MAX) == 0 && date > 28){
    return invalid_feb_date;
    }
//Check that the input string is one of the defined months
  if ((strncmp (month, "january",MAX) != 0)
           && (strncmp (month, "february",MAX) != 0)
           && (strncmp (month, "march",MAX) != 0) && (strncmp (month, "april",MAX) != 0)
           && (strncmp (month, "may",MAX) != 0) && (strncmp (month, "june",MAX) != 0)
           && (strncmp (month, "july",MAX) != 0) && (strncmp (month, "august",MAX) != 0)
           && (strncmp (month, "september",MAX) != 0)
           && (strncmp (month, "october",MAX) != 0)
           && (strncmp (month, "november",MAX) != 0)
           && (strncmp (month, "december",MAX) != 0)){
    return invalid_month;
    } 
    

 else return no_error;
}

//Check initialisation of the library
enum check_error init(void)
{
 if(init_lib == 0){
  fprintf(stdout,"library initialised\n\n");
  init_lib =1;
  return no_error;
  }
 else return no_init;
}

//Check deinitialisation of the library
enum check_error deinit(void)
{
 if(init_lib != 1)
  return no_init;
 else
 { 
  init_lib=0;
  fprintf(stdout,"library deinitialised\n\n");
  return no_error;
 }
}

