#include <Arduino.h>
#include "globales.h"


//_________________PIN MODE__________________________
void setup_pin(){
   pinMode(pwm_big,OUTPUT);
   pinMode(pwm_small,OUTPUT);
   pinMode(direction_big,OUTPUT);
   pinMode(direction_small,OUTPUT);
   pinMode(break_motor,OUTPUT);
   pinMode(holdoff_mbig,OUTPUT);
   pinMode(holdoff_msmall,OUTPUT);

   
   pinMode(distributor,OUTPUT);
   pinMode(sensor_distributor,INPUT);  

   pinMode(water_entrance,OUTPUT);
   pinMode(water_exit,OUTPUT);
   pinMode(water_dispenser,OUTPUT);

   pinMode(container1,OUTPUT);
   pinMode(container2,OUTPUT);
   pinMode(container3,OUTPUT);
   pinMode(container4,OUTPUT);
   pinMode(container5,OUTPUT);
   pinMode(container6,OUTPUT);
   pinMode(container7,OUTPUT);
   pinMode(container8,OUTPUT);
   pinMode(container9,OUTPUT);
   pinMode(container10,OUTPUT);
   pinMode(container11,OUTPUT);
   pinMode(container12,OUTPUT);
   pinMode(container13,OUTPUT);
   pinMode(container14,OUTPUT);
   
   pinMode(s_container1,INPUT);
   pinMode(s_container2,INPUT);
   pinMode(s_container3,INPUT);
   pinMode(s_container4,INPUT);
   pinMode(s_container5,INPUT);
   pinMode(s_container6,INPUT);
   pinMode(s_container7,INPUT);
   pinMode(s_container8,INPUT);
   pinMode(s_container9,INPUT);
   pinMode(s_container10,INPUT);
   pinMode(s_container11,INPUT);
   pinMode(s_container12,INPUT);
   pinMode(s_container13,INPUT);
   pinMode(s_container14,INPUT);

   pinMode(s_forgotten_cup,INPUT);
   pinMode(s_no_cup,INPUT);
   pinMode(s_no_cup_Ondispenser,INPUT);
   
   pinMode(station_cup_distribution,INPUT);
   pinMode(s_satation_1,INPUT);
   pinMode(s_satation_2,INPUT);
   pinMode(s_satation_3,INPUT);
   pinMode(s_satation_4,INPUT);
   pinMode(s_satation_5,INPUT);
   pinMode(s_satation_6,INPUT);
   pinMode(s_satation_7,INPUT);

   pinMode(start_career_sm,INPUT);
   pinMode(end_career_sm,INPUT);
   pinMode(mix_pos_bm,INPUT);
   pinMode(start_career_bm,INPUT);
   pinMode(end_career_bm,INPUT);
   pinMode(s_water_distribution,INPUT);
   

   pinMode(ledred,OUTPUT);
   pinMode(ledgreen,OUTPUT);
   pinMode(mixer,OUTPUT);
}
//______________________________________________________



  //*****************************************************************
  //***********funcion inicio de carrera horizontal******************
  //********************motor horizontal****************************** 
   //*****************************************************************   


void horizontal_home()
{ while(digitalRead(start_career_sm)==LOW){
  digitalWrite(direction_small, LOW);             //<------- cambiar el LOW por HIGH o viseversa si gira en sentido contrario
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
   return;
   }

    //***************************************************************** 
  //***********funcion movimiento de motor vertical *****************
  //***********************con sensor********************************
  //*****************************************************************   

void vertical_home()
{
   while (digitalRead(start_career_bm)==LOW){
digitalWrite(direction_big, HIGH);                 //<------- cambiar el HIGH por LOW o viseversa si gira en sentido contrario
digitalWrite(pwm_big, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_big, LOW);
delayMicroseconds(500);


 }
 return;
 }
