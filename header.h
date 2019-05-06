#include<stdio.h>
#ifdef C
extern "C"{
#endif
enum check_error{

 invalid_month,
 invalid_date,
 invalid_feb_date,
 no_error,
 no_init,
};
const char *error_msg(enum check_error);
/*
Display the error messages
*/
enum check_error error (int date,char month[]);
/*
Check the error conditions
*/
enum check_error init(void);
/*
Check initialisation of the library
*/
enum check_error deinit(void);
/*
Checks the deinitialisation of the library
*/
#ifdef C
};
#endif
