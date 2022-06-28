#include <stdlib.h>     //exit()
#include <signal.h>     //signal()
#include <time.h>
#include "ADS1256.h"
#include "stdio.h"
#include <time.h>
#include <string.h>
#include <sys/timeb.h>
void  Handler(int signal)
{
    //System Exit
    printf("\r\nEND                  \r\n");
    DEV_ModuleExit();

    exit(0);
}

int main(void)
{
    UDOUBLE ADC[8],i;
    printf("demo\r\n");
    DEV_ModuleInit();
    
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);

    if(ADS1256_init() == 1){
        printf("\r\nEND                  \r\n");
        DEV_ModuleExit();
        exit(0);
    }
    
    time_t endwait;
    int seconds=1;
    endwait = time (NULL) + seconds;
    int count=0;
    struct timespec start, end;

    

    while(time (NULL) < endwait){
    

        
        // printf("0 : %f\r\n",ADS1256_GetChannalValue(0)*5.0/0x7fffff);
        // printf("1 : %f\r\n",ADS1256_GetChannalValue(1)*5.0/0x7fffff);
        // printf("2 : %f\r\n",ADS1256_GetChannalValue(2)*5.0/0x7fffff);
        // printf("3 : %f\r\n",ADS1256_GetChannalValue(3)*5.0/0x7fffff);
        // printf("4 : %f\r\n",ADS1256_GetChannalValue(4)*5.0/0x7fffff);
        // printf("5 : %f\r\n",ADS1256_GetChannalValue(5)*5.0/0x7fffff);
        // printf("6 : %f\r\n",ADS1256_GetChannalValue(6)*5.0/0x7fffff);
        // printf("7 : %f\r\n",ADS1256_GetChannalValue(7)*5.0/0x7fffff);
        clock_gettime(CLOCK_MONOTONIC_RAW, &start);

        ADS1256_GetAll(ADC);
        clock_gettime(CLOCK_MONOTONIC_RAW, &end);
        count=count+1;
        printf("\ncount is: %d\n", count);
        fprintf(stdout, "%lu\n",(end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000);
             
        
        
        //for(i=0;i<8;i++){
        //    printf("%d %f\r\n",i,ADC[i]*5.0/0x7fffff);
        //}
        //printf("\33[8A");//Move the cursor up 8 lines
    }
    printf("count is: %d", count);
    return 0;
}
