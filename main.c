#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
#include"cal.h"

void print_err(enum check_error err)
{
	if(err != no_error){
	fprintf(stderr,"Error: %s",error_msg(err));
}
}

void help()
{
        fprintf(stdout,"\n-----Day of the Week(2019)------\n");
        fprintf(stdout,"\nEnter the month and date in the format: month(name) date\n");
	fprintf(stdout,"\nEverything should be in lowercase\n");
        fprintf(stdout,"\nExample: january 21\n");
        fprintf(stdout,"\nEnter 'quit' to exit\n\n");
}


int main(int argc,char *argv[])
{
 int date;
 char month[10],*day;
 enum check_error err;
 while(1){
  scanf("%s",month);

//Display details if user enters 'help'
  if(strncmp(month,"help",4)==0 ){
        help();
        scanf("%s",month);
        }

//Exit the program if user enters 'quit'
  if(strncmp(month,"quit",4)==0)
        exit(0);

  scanf("%d",&date);

//Display error in inputs(if any)
 err=error(date,month);
 print_err(err);
 if(err == no_error){

//Library initialisation check
 err=init();
 print_err(err);

//Main API execution
 cal(date,month,&day);
 fprintf(stdout,"The day on %d %s 2019 is: %s\n\n",date,month,day);

//Library deinitialisation check
 err=deinit();
 print_err(err);
 }
 }
return 0;
}
