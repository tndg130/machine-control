#include "globales.h"

  //***************************************************************** 

void setup() {
   pinMode(s_forgotten_cup,INPUT);
   pinMode(s_no_cup,INPUT);
   pinMode(break_motor, OUTPUT);
   pinMode(pwm_small,OUTPUT);
   pinMode(direction_small,OUTPUT);
   pinMode(direction_big,OUTPUT);
   pinMode(pwm_big,OUTPUT);
   pinMode(water,OUTPUT);
   pinMode(mixer_a,OUTPUT);
   pinMode(holdoff_mbig,OUTPUT);
   pinMode(distributor,OUTPUT);
   pinMode(holdoff_msmall,OUTPUT);
   pinMode(container1,OUTPUT);
   pinMode(container2,OUTPUT);
   pinMode(container3,OUTPUT);
   pinMode(container4,OUTPUT);
   pinMode(container5,OUTPUT);
   pinMode(s_container1,INPUT);
   pinMode(s_container2,INPUT);
   pinMode(s_container3,INPUT);
   pinMode(s_container4a,INPUT);
   pinMode(s_container4b,INPUT);
   pinMode(s_container5a,INPUT);
   pinMode(s_container5b,INPUT);
   pinMode(s_container6a,INPUT);
   pinMode(s_container6b,INPUT);
   pinMode(start_career_sm,INPUT);
   pinMode(end_career_sm,INPUT);
   pinMode(start_career_bm,INPUT);
   pinMode(end_career_bm,INPUT);
   pinMode(sensor_door,INPUT);
   pinMode(water_entrance,OUTPUT);
   pinMode(water_exit,OUTPUT);
   pinMode(sensor_distributor,INPUT);  
   pinMode(ledred,OUTPUT);
   pinMode(ledgreen,OUTPUT);
   Serial.begin(9600);
   
   inputString.reserve(200);   
}
  //*****************************************************************
  //***********funcion inicio de carrera horizontal******************
  //********************motor horizontal****************************** 
   //*****************************************************************   

void go_home()
{ while(digitalRead(start_career_sm)==HIGH){
  digitalWrite(direction_small, LOW);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }}



  
  //***************************************************************** 
  //***********funcion movimiento de motor vertical *****************
  //***********************con sensor********************************
  //*****************************************************************   

void motor_up()
{
   while (digitalRead(start_career_bm)==HIGH){
digitalWrite(direction_big, HIGH);
digitalWrite(pwm_big, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_big, LOW);
delayMicroseconds(500);


 }
 return;
 }




 
  //***************************************************************** 
  //***********funcion movimiento de motor vertical *****************
  //***********************con pasos********************************* 
  //***************************************************************** 
  
 void motor_up_wsteps()
{
   while (steps_up > 0){
digitalWrite(direction_big, HIGH);
digitalWrite(pwm_big, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_big, LOW);
delayMicroseconds(500);

steps_up--;
 }
 return;
 }



 
   //*****************************************************************
   //*********************funcion de medicion ************************
    //******************sesnsores almacenamientos*********************
  //****************************************************************** 
void measure()
{
  if (digitalRead(s_container1))
  Serial.print('L');
  
  else 
  Serial.print('h');

   if (digitalRead(s_container2))
  Serial.print('L');
  
  else 
  Serial.print('h');

   if (digitalRead(s_container3))
  Serial.print('L');
  
  else 
  Serial.print('h');

   if (digitalRead(s_container4a) || digitalRead(s_container4b))
  Serial.print('L');
  
  else 
  Serial.print('h');
  
   if (digitalRead(s_container5a) || digitalRead(s_container5b))
  Serial.print('L');
  
  else 
  Serial.print('h');
  if (digitalRead(s_container6a) || digitalRead(s_container6b))
  Serial.print('L');
  
  else 
  Serial.print('h');
  Serial.print('F');
}

  //***************************************************************** 
  //***********funcion movimiento de motor vertical *****************
  //***********************con pasos********************************* 
  //***************************************************************** 
  
void down_m()
{
   while (steps_down > 0){
digitalWrite(direction_big, LOW);
digitalWrite(pwm_big, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_big, LOW);
delayMicroseconds(500);
steps_down--;

 }
 return;
 }
 ///////////////////////////
void full_down_m()
{
   while (digitalRead(end_career_bm)==HIGH){
digitalWrite(direction_big, LOW);
digitalWrite(pwm_big, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_big, LOW);
delayMicroseconds(500);
steps_down--;

 }
 return;
 }




  //***************************************************************** 
  //**********funcion movimiento de motor horizontal ****************
  //**********************a licuadora********************************
  //***************************************************************** 
  
  void mixer()
{ while(digitalRead(end_career_sm)==HIGH){
  digitalWrite(direction_small, HIGH);
digitalWrite(pwm_small, HIGH);
delayMicroseconds(500);
digitalWrite(pwm_small, LOW);
delayMicroseconds(500);
  }}


  
  //***************************************************************** 
  //***********funcion movimiento de motor horizontal****************
  //***********************con pasos********************************* 
  //***************************************************************** 
void run_horizontal()
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



   //************************************************************************** 
   //*****************************looop main************************************ 
   //************************************************************************** 

 
void loop() {
  if (turnon == false)  // Si esta encendiendo
  
   {digitalWrite(distributor,HIGH);
    digitalWrite(container1,HIGH);
    digitalWrite(container2,HIGH);
    digitalWrite(container3,HIGH);
    digitalWrite(container4,HIGH);
    digitalWrite(container5,HIGH);
    digitalWrite(water_entrance,HIGH);
    digitalWrite(water_exit,HIGH);
    digitalWrite(ledgreen,HIGH);
    digitalWrite(break_motor,HIGH);
    digitalWrite(water,HIGH);
    digitalWrite(mixer_a,HIGH);
    delay(30000);      // pausa de 30 segundos * 2
digitalWrite(water_exit,LOW);//DESAGUE ON
digitalWrite(holdoff_mbig,HIGH);// HOLD OFF encendido
delay(100);
digitalWrite(holdoff_mbig,LOW);// HOLD OFF apagado
digitalWrite(break_motor,LOW);//FRENO OFF
motor_up();//POSICION INICIAL VERTICAL

digitalWrite(break_motor,HIGH);//FRENO ON
digitalWrite(holdoff_mbig,HIGH);// HOLD OFF encendido
delay(1000);
go_home();                        //POSICION INICIAL HORIZONTAL
digitalWrite(holdoff_msmall,HIGH);// HOLD OFF encendido
digitalWrite(water_exit,HIGH);  //DESAGUE OFF
digitalWrite(ledred,LOW); // APAGA LED ROJO
digitalWrite(ledgreen,HIGH); // ENCIENDE LED VERDE
turnon=true;

   }
digitalWrite(ledgreen,LOW); // ENCIENDE LED VERDE


   //************************************************************************** 
   //**********************obtenciÃ³n de datos del Raspberry********************* 
   //**************************************************************************              
switch (alm) {
  case 1:
    in_steps=800-160; //PASOS A ALMACENAMIENTO 1
    delay(200);
    
    
    break;
  case 2:
  in_steps=1300-160; //PASOS A ALMACENAMIENTO 2
  delay(200);
   
  break;
     case 3:
 in_steps=1800-160; //PASOS A ALMACENAMIENTO 3
 delay(200);
 
 break;
    case 4:
 in_steps=2550-160; //PASOS A ALMACENAMIENTO 4
 delay(200);
   
 break;
  case 5:
 in_steps=3425-160; //PASOS A ALMACENAMIENTO 5
 delay(200);
  break;

     case 6:
    in_steps=800-160; //PASOS A ALMACENAMIENTO 1
    delay(200);
    
 break;
  default:
  in_steps=0; //PASOS A ALMACENAMIENTO 6
   break;
}


  //***************************************************************** 
if (alm !='n' && tiempo != 1){  // si recibe informacion almacenamiento y tiempo del raspberry

  
  //***************************************************************** 
  //*********************** secuencia********************************* 
   //***************************************************************** 
paso=0;

if (digitalRead(sensor_door)==LOW){ // si sensor de la puerta esta bajo (puerta cerrada)
  do{
switch (paso) {

  //*****************************************************************
  //************************* caso 0*********************************
  //***************************************************************** 
case 0:

Serial.print("0_SS_1\n"); //SS - State Started. 1: Successful.

if (digitalRead(s_forgotten_cup) == HIGH)
{
digitalWrite(holdoff_msmall,LOW);  // encendido motor chico
steps=20;
run_horizontal();
go_home();
}
if (digitalRead(s_forgotten_cup) == HIGH)
{
digitalWrite(ledred,LOW);  //ENCIENDE LED ROJO
digitalWrite(ledgreen,HIGH); // APAGA LED VERDE
steps=960;
run_horizontal();    //distribuidor de vasos
paso=1;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful.
Serial.flush(); // limpia puerto serial

break;
}

else{
steps=0;
alm=57;
tiempo=1;
paso=17;
digitalWrite(holdoff_msmall,HIGH);  // encendido motor chico

Serial.print("SF_0\n");  // SF - State Finished. 0: Unsuccessful.
break;
}
   //*****************************************************************
  //************************* caso 1*********************************
  //*****************************************************************  

case 1:
Serial.print("1_SS_1\n"); //SS - State Started. 1: Successful.

digitalWrite(distributor,LOW);            // Distribuidor ON
if (digitalRead(sensor_distributor)==HIGH) // Si NO esta en la referencia el distribuidor      
{
  paso=2;
  Serial.print("SF_1\n");   // SF - State Finished. 1: Successful.
  Serial.flush(); // limpia puerto serial
 Serial.print("2_SS_1\n"); //SS - State Started. 1: Successful.

}
break;

case 2:

if (digitalRead(sensor_distributor)==LOW){   // Si ESTA en la referencia el distribuidor    
delay(200);
paso=3;
}

break;

  //*****************************************************************
  //************************* caso 3*********************************
  //*****************************************************************
case 3:
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful.

Serial.print("3_SS_1\n"); //SS - State Started. 1: Successful.

digitalWrite(distributor,HIGH);  //apagado distribuidor vasos
delay(1000);
if (digitalRead(s_no_cup) ==LOW){
paso=4;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;
}

else{
steps=0;
alm=57;
tiempo=1;
paso=17;
Serial.print("SF_0\n");  // SF - State Finished. 0: Unsuccessful.
go_home();
Serial.flush(); // limpia puerto serial

break;
}



  //*****************************************************************
  //************************* caso 4*********************************
  //*****************************************************************
case 4:
Serial.print("4_SS_1\n"); //SS - State Started. 1: Successful.

delay(1000);          //pausa para el agua
steps=in_steps;
run_horizontal();  //corrida al almacenamiento
paso=5;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;


  //*****************************************************************
  //************************* caso 5*********************************
  //*****************************************************************
case 5:
Serial.print("5_SS_1\n"); //SS - State Started. 1: Successful.
 
if (alm ==0){
paso=6;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial
break;
  }

  
if (alm == 1)
digitalWrite(container1,LOW);
if (alm == 2)
digitalWrite(container2,LOW);
if (alm == 3)
digitalWrite(container3,LOW);
if (alm == 4)
digitalWrite(container4,LOW);
if (alm == 5)
digitalWrite(container5,LOW);
if (alm == 6)
digitalWrite(container1,LOW);

delay(tiempo);          //tiempo en el almacenamiento***************************************
digitalWrite(container1,HIGH);
digitalWrite(container2,HIGH);
digitalWrite(container3,HIGH);
digitalWrite(container4,HIGH);
digitalWrite(container5,HIGH);
paso=6;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;


  //*****************************************************************
  //************************* caso 6*********************************
  //*****************************************************************
case 6:
Serial.print("6_SS_1\n"); //SS - State Started. 1: Successful.

delay(1000);
steps=4600-in_steps;
run_horizontal();                 //posicion de bomba de agua
delay(1000);
digitalWrite(water,LOW); //encendido de la bomba del agua
if (alm !=0)
delay(11000);//tiempo de llenado del vaso 
if (alm ==0)
delay(17000);
digitalWrite(water,HIGH);  //apagado de la bomba del agua
paso=7;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

if (alm ==0){
paso=12;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial
break;
  }

break;

  //*****************************************************************
  //************************* caso 7*********************************
  //*****************************************************************
case 7:
Serial.print("7_SS_1\n"); //SS - State Started. 1: Successful.

delay(1000);
mixer();           //corrida a la licuadora
if(digitalRead(end_career_sm)==LOW){ //si final de carrera horizontal esta activo
paso=8;
}
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;
  

  //*****************************************************************
  //************************* caso 8*********************************
  //*****************************************************************

case 8:
Serial.print("8_SS_1\n"); //SS - State Started. 1: Successful.

digitalWrite(holdoff_mbig,LOW);// HOLD OFF apagado
digitalWrite(break_motor,LOW); // freno apagado
paso=9;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;
 //*****************************************************************
  //************************* caso 9*********************************
  //*****************************************************************

case 9:
Serial.print("9_SS_1\n"); //SS - State Started. 1: Successful.

steps_down=1700;
down_m();            //motor baja
paso=10;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;
  


  //*****************************************************************
  //************************* caso 10*********************************
  //*****************************************************************

case 10:
Serial.print("10_SS_1\n"); //SS - State Started. 1: Successful.

digitalWrite(mixer_a,LOW);// licuadora encendida
if (tiempo/1000<=1)
delay(3000);
if (tiempo/1000>1 && tiempo/1000<8 )
delay(6000);
if (tiempo/1000>8){        // si el tiempo recibido del raspberry es mayor a 3s
steps_up=tiempo/1000*.23*147;
motor_up_wsteps();         // sube motor
delay(4000);
steps_down=tiempo/1000*.23*147;
down_m();                   // baja motor
delay(tiempo*.5);
steps_up=tiempo/1000*.23*147;
motor_up_wsteps();          // sube motor
delay(tiempo*.5);
steps_down=tiempo/1000*.23*147;
down_m();                   // baja motor
delay(tiempo*.5);
steps_up=tiempo/1000*.23*147;
motor_up_wsteps();          // sube motor
delay(tiempo*.5);
}
digitalWrite(mixer_a,HIGH); //licuadora apagada
paso=11;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;




 //*****************************************************************
  //************************* caso 11*********************************
  //*****************************************************************
case 11:
Serial.print("11_SS_1\n"); //SS - State Started. 1: Successful.

motor_up();                     // motor sube 
digitalWrite(break_motor,HIGH); // freno encendido
digitalWrite(holdoff_mbig,HIGH);// HOLD OFF encendido
while(digitalRead(start_career_bm)==LOW){
  delay(1000);

if(digitalRead(start_career_bm)==LOW){  // si motor vertical esta en posicion inicial
paso=12;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial
break;


}
}





 //*****************************************************************
  //************************* caso 12*********************************
  //*****************************************************************
case 12:
Serial.print("12_SS_1\n"); //SS - State Started. 1: Successful.

go_home();
digitalWrite(holdoff_mbig,LOW);// HOLD OFF apagado
digitalWrite(break_motor,LOW); // freno apagado
while(digitalRead(start_career_sm)==LOW){
  delay(1000);
if(digitalRead(start_career_sm)==LOW){ // si motor horizontal esta en posicion inicial

  
paso=13;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial
break;
}

}


 //*****************************************************************
  //************************* caso 13*********************************
  //*****************************************************************
case 13:
Serial.print("13_SS_1\n"); //SS - State Started. 1: Successful.


if (alm ==0){
paso=16;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial
break;
  }
  
digitalWrite(water_entrance,LOW); //agua al lavado ON
steps_down=3200;
full_down_m();          //motor baja
delay(5500);       // tiempo de lavado
digitalWrite(water_entrance,HIGH); //agua al lavado OFF
paso=14;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;




 //*****************************************************************
  //************************* caso 14*********************************
  //*****************************************************************
case 14:
Serial.print("14_SS_1\n"); //SS - State Started. 1: Successful.

digitalWrite(mixer_a,LOW);// licuadora encendida
delay(4000);
digitalWrite(mixer_a,HIGH); //licuadora apagada

paso=15;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;




 //*****************************************************************
  //************************* caso 15*********************************
  //*****************************************************************
case 15:
Serial.print("15_SS_1\n"); //SS - State Started. 1: Successful.

motor_up();
digitalWrite(water_exit,LOW);  // desague del agua encendido 
digitalWrite(break_motor,HIGH); // freno encendido
digitalWrite(holdoff_mbig,HIGH);// HOLD OFF encendido
digitalWrite(holdoff_msmall,HIGH);//  HOLD OFF motor chico
paso=16;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;




 //*****************************************************************
  //************************* caso 16*********************************
  //*****************************************************************
case 16:
Serial.print("16_SS_1\n"); //SS - State Started. 1: Successful.

delay(8000); 
digitalWrite(water_exit,HIGH);// desague del agua apagado 


digitalWrite(ledred,HIGH); //APAGA LED ROJO
digitalWrite(ledgreen,LOW); //ENCIENDE LED VERDE
steps=0;
alm=57;
tiempo=1;
paso=17;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.print("P_F\n");   // Process -  Finished
measure();
Serial.flush(); // limpia puerto serial

break;
  //***************************************************************** 

}
  }while (paso!=17);  
  }

}}


  //***************************************************************** 
  //****************obtencion de datos serial************************
  //***************************************************************** 

  
void serialEvent() {
  while (Serial.available()) {

    char inChar = (char)Serial.read();
 
    if (inChar == '\n' && alm == 57) {
      alm=inputString.toInt();
      inputString = "";
      return;
      }
    if (inChar == '\n' && alm != 57) {
      tiempo= inputString.toInt();
      inputString = "";
      
      return;
      }
    else
      inputString += inChar;
    
    
  }
}
//***************************************************************** 
