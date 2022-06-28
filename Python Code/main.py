#!/usr/bin/python
# -*- coding:utf-8 -*-


import time
import ADS1256
import RPi.GPIO as GPIO



try:
    ADC = ADS1256.ADS1256()
    ADC.ADS1256_init()
    future=time.time()+float(1)
    #buffer=[]    
    #x = array.array('d', [])
    x=[]
    print("initial time is:", time.time())
    while(time.time()<future):#running for 1 sec.
        
        tic = time.perf_counter()
        x.append(ADC.ADS1256_GetAll())#x is a list.
        toc = time.perf_counter()
        print(f"{(toc - tic)*1000000} useconds")#seeing time between each read   
    
    #print("time after loop end is :", time.time())
    #print("count is: ",count)
    for item in x:
        print(item)
    
    
            
except :
    GPIO.cleanup()
    print ("\r\nProgram end     ")
    print("count is: ",count)
    exit()



