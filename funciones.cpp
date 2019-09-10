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

   digitalWrite(distributor,HIGH);
   digitalWrite(container1,HIGH);
   digitalWrite(container2,HIGH);
   digitalWrite(container3,HIGH);
   digitalWrite(container4,HIGH);
   digitalWrite(container5,HIGH);
   digitalWrite(container6,HIGH);
   digitalWrite(container7,HIGH);
   digitalWrite(container8,HIGH);
   digitalWrite(container9,HIGH);
   digitalWrite(container10,HIGH);
   digitalWrite(container11,HIGH);
   digitalWrite(container12,HIGH);
   digitalWrite(container13,HIGH);
   digitalWrite(container14,HIGH);
   digitalWrite(water_entrance,HIGH);
   digitalWrite(water_exit,HIGH);
   digitalWrite(ledgreen,HIGH);
   digitalWrite(break_motor,HIGH);
   digitalWrite(water_dispenser,HIGH);
   digitalWrite(mixer,HIGH);
      

}
//______________________________________________________

//******************************************************************
//*********************selecion de direccion************************
//******************************************************************

int select_dirup()
{ if (direccion_motor_vert == 0)
      return HIGH;
  else 
      return LOW;
  }
  
int select_dirdown()
{ if (direccion_motor_vert == 0)
      return LOW;
   else 
      return HIGH;
  }
  
int select_dirback()
{if (direccion_motor_horz == 0)
      return HIGH;
  else 
      return LOW;
  }
int select_dirfront()
  {if (direccion_motor_horz == 0)
      return LOW;
  else 
      return HIGH;
  }
//******************************************************************
//******************************************************************
//******************************************************************

  //*****************************************************************
  //***********funcion inicio de carrera horizontal******************
  //********************motor horizontal*****************************
  //*****************************************************************   

void horizontal_home(int dir_front)
{ 
  digitalWrite(holdoff_msmall,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende 
  while(digitalRead(start_career_sm)==LOW){
digitalWrite(direction_small, dir_front);             
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
  digitalWrite(holdoff_msmall,LOW);            //<------- cambiar el LOW por HIGH o viseversa si no enciende 
   return;
   }
   

 //***************************************************************** 
  //**********funcion movimiento de motor horizontal ****************
  //**********************a licuadora********************************
  //***************************************************************** 
  
  void motor_mix_station(int dir_back)
{   digitalWrite(holdoff_msmall,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  while(digitalRead(end_career_sm)==LOW){
  digitalWrite(direction_small, dir_back);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
  digitalWrite(holdoff_msmall,LOW);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  return;
  }
  //***************************************************************** 
  //***********funcion movimiento de motor horizontal****************
  //***********************dispensador de agua********************** 
  //***************************************************************** 
void motor_water_station(int dir_back)
{   digitalWrite(holdoff_msmall,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  while(digitalRead(s_water_distribution)==LOW){
  digitalWrite(direction_small, dir_back);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
  digitalWrite(holdoff_msmall,LOW);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  return;
  }
//*******************************************************************
//*******************************************************************
//*******************************************************************

  //***************************************************************** 
  //***********funcion movimiento de motor horizontal****************
  //***********************dispensador de vasos********************** 
  //***************************************************************** 
void motor_cup_station(int dir_back)
{   digitalWrite(holdoff_msmall,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  while(digitalRead(station_cup_distribution)==LOW){
  digitalWrite(direction_small, dir_back);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
  digitalWrite(holdoff_msmall,LOW);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  return;
  }
//*******************************************************************
//*******************************************************************
//*******************************************************************


  //***************************************************************** 
  //***********funcion movimiento de motor horizontal****************
  //***********************almacenamiento ********************** 
  //***************************************************************** 

void motor_alm_station(int dir_back, int alm){ 
  if(alm == 1 || alm == 5)
{ 
  
  digitalWrite(holdoff_msmall,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  while(digitalRead(s_satation_1)==LOW){
  digitalWrite(direction_small, dir_back);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
  digitalWrite(holdoff_msmall,LOW);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  return;
  }
   if(alm == 2 || alm == 6)
{  digitalWrite(holdoff_msmall,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  while(digitalRead(s_satation_2)==LOW){
  digitalWrite(direction_small, dir_back);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
  digitalWrite(holdoff_msmall,LOW);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  return;
  }
   if(alm == 3 || alm == 7)
   {  digitalWrite(holdoff_msmall,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  while(digitalRead(s_satation_3)==LOW){
  digitalWrite(direction_small, dir_back);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
  digitalWrite(holdoff_msmall,LOW);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  return;}
   if(alm == 4 || alm == 8)
   {  digitalWrite(holdoff_msmall,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  while(digitalRead(s_satation_4)==LOW){
  digitalWrite(direction_small, dir_back);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
  digitalWrite(holdoff_msmall,LOW);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  return;}
   if(alm == 9 || alm == 12)
   {  digitalWrite(holdoff_msmall,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  while(digitalRead(s_satation_5)==LOW){
  digitalWrite(direction_small, dir_back);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
  digitalWrite(holdoff_msmall,LOW);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  return;}
   if(alm == 10 || alm == 13){
      digitalWrite(holdoff_msmall,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  while(digitalRead(s_satation_6)==LOW){
  digitalWrite(direction_small, dir_back);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
  digitalWrite(holdoff_msmall,LOW);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  return;}
   if(alm == 11 || alm == 14)
   {  digitalWrite(holdoff_msmall,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  while(digitalRead(s_satation_7)==LOW){
  digitalWrite(direction_small, dir_back);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }
  digitalWrite(holdoff_msmall,LOW);             //<------- cambiar el LOW por HIGH o viseversa si no enciende
  return;}
  }
//*******************************************************************
//*******************************************************************
//*******************************************************************



  //***************************************************************** 
  //***********funcion movimiento de motor horizontal****************
  //***********************con pasos********************************* 
  //***************************************************************** 
void run_horizontal(int steps)
{ 
  while (steps > 0){
digitalWrite(direction_small, HIGH);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
steps--;
if (digitalRead(end_career_sm)==LOW)
 return;
 }
 return;
 }




  //***************************************************************** 
  //***********funcion movimiento de motor vertical *****************
  //***********************con sensor********************************
  //*****************************************************************   

void vertical_home(int dir_up)
{
    digitalWrite(holdoff_mbig,HIGH);             //<------- cambiar el LOW por HIGH o viseversa si no enciende 
   while (digitalRead(start_career_bm)==LOW){
digitalWrite(direction_big, dir_up);             
digitalWrite(pwm_big, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_big, LOW);
delayMicroseconds(500);
 }
 digitalWrite(holdoff_mbig,LOW);             //<------- cambiar el LOW por HIGH o viseversa si no enciende 
 return;
 }
//******************************************************************
//******************************************************************
//******************************************************************


  //***************************************************************** 
  //***********funcion movimiento de motor vertical *****************
  //*****************************************************************
  //***************************************************************** 
  
void down_m(int dir_down)
{  digitalWrite(holdoff_mbig,HIGH);       //<------- cambiar el LOW por HIGH o viseversa si no enciende 
   while (digitalRead(mix_pos_bm)== LOW){
digitalWrite(direction_big, dir_down);       
digitalWrite(pwm_big, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_big, LOW);
delayMicroseconds(500);
 }
 digitalWrite(holdoff_mbig,LOW);          //<------- cambiar el LOW por HIGH o viseversa si no enciende 
 return;
 }
//******************************************************************
//******************************************************************
//******************************************************************

 
  //***************************************************************** 
  //***********funcion movimiento fin de carrera de motor vertical **
  //*****************************************************************
  //***************************************************************** 
  
 void full_down_m(int dir_down)
{digitalWrite(holdoff_mbig,HIGH);       //<------- cambiar el LOW por HIGH o viseversa si no enciende 
   while (digitalRead(end_career_bm)==LOW){
digitalWrite(direction_big, dir_down);
digitalWrite(pwm_big, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_big, LOW);
delayMicroseconds(500);
 }
  digitalWrite(holdoff_mbig,LOW);          //<------- cambiar el LOW por HIGH o viseversa si no enciende 
 return;
 }

//********************************************************************
//******************************************************************
//******************************************************************





   //*****************************************************************
   //*********************funcion de medicion ************************
    //******************sesnsores almacenamientos*********************
  //****************************************************************** 
void measure()
{
  if (digitalRead(s_container1))
  Serial.print('L'); //contenedor 1 low 
  else 
  Serial.print('h'); //contenedor 1 high 
   if (digitalRead(s_container2))
  Serial.print('L');//contenedor 2 low 
  else 
  Serial.print('h');//contenedor 2 high 
   if (digitalRead(s_container3))
  Serial.print('L');//contenedor 3 low 
  else 
  Serial.print('h');//contenedor 3 high 
 if (digitalRead(s_container4))
  Serial.print('L');//contenedor 4 low 
  else 
  Serial.print('h');//contenedor 4 high 
 if (digitalRead(s_container5))
  Serial.print('L');//contenedor 5 low 
  else 
  Serial.print('h');//contenedor 5 high 
 if (digitalRead(s_container6))
  Serial.print('L');//contenedor 6 low 
  else 
  Serial.print('h'); //contenedor 6 high 
 if (digitalRead(s_container7))
  Serial.print('L');//contenedor 7 low 
  else 
  Serial.print('h');//contenedor 7 high 
 if (digitalRead(s_container8))
  Serial.print('L');//contenedor 8 low 
  else 
  Serial.print('h');//contenedor 8 high 
   if (digitalRead(s_container9))
  Serial.print('L');//contenedor 9 low 
  else 
  Serial.print('h');//contenedor 9 high 
 if (digitalRead(s_container10))
  Serial.print('L');//contenedor 10 low 
  else 
  Serial.print('h');//contenedor 10 high 
   if (digitalRead(s_container11))
  Serial.print('L');//contenedor 11 low 
  else 
  Serial.print('h');//contenedor 11 high 
   if (digitalRead(s_container12))
  Serial.print('L');//contenedor 12 low 
  else 
  Serial.print('h');//contenedor 12 high 
   if (digitalRead(s_container13))
  Serial.print('L');//contenedor 13 low 
  else 
  Serial.print('h');//contenedor 13 high 
   if (digitalRead(s_container14))
  Serial.print('L');//contenedor 14 low 
  else 
  Serial.print('h');//contenedor 14 high 

  Serial.print('F');
}

////////////////////////////////////////////////////////////////////////////////////////////////////////





 
