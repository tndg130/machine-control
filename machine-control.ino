#include "globales.h"
#include "funciones.h"

#define water_time 14000                         // tiempo de dispensado de agua en milisegundos

int tiempo=1;
int alm=57;
int paso=0;
bool turnon = false; 
String inputString = ""; 
int dir_up, dir_down, dir_back, dir_front;

  //***************************************************************** 

void setup() {
   setup_pin();
   dir_up = select_dirup();
   dir_down = select_dirdown();
   dir_back = select_dirback();
   dir_front = select_dirfront();
   
   Serial.begin(9600);
   inputString.reserve(200);   
}

   //************************************************************************** 
   //*****************************looop main************************************ 
   //************************************************************************** 

 
void loop() {
  if (turnon == false)  // Si esta encendiendo
{
delay(30000);      // pausa de 30 segundos * 2
digitalWrite(break_motor,LOW);//FRENO OFF
vertical_home(dir_up);//POSICION INICIAL VERTICAL
digitalWrite(break_motor,HIGH);//FRENO ON
delay(1000);
horizontal_home(dir_front);                        //POSICION INICIAL HORIZONTAL
digitalWrite(ledred,LOW); // APAGA LED ROJO
digitalWrite(ledgreen,HIGH); // ENCIENDE LED VERDE
turnon=true;
   }
digitalWrite(ledgreen,LOW); // ENCIENDE LED VERDE

  //***************************************************************** 
if (alm !='n' && tiempo != 1){  // si recibe informacion almacenamiento y tiempo del raspberry
  //***************************************************************** 
  //*********************** secuencia********************************* 
   //***************************************************************** 
paso=0;
  do{
switch (paso) {
  //*****************************************************************
  //************************* caso 0*********************************
  //***************************************************************** 
case 0:

//******************************VALORES INICIALES*******************
tiempo=1;
alm=57;
paso=0;
turnon = false; 
inputString = ""; 
//******************************************************************

Serial.print("0_SS_1\n"); //SS - State Started. 1: Successful.
if (digitalRead(s_forgotten_cup) == HIGH)
{
run_horizontal(20);
horizontal_home(dir_front);
}
if (digitalRead(s_forgotten_cup) == HIGH)
{
digitalWrite(ledred,LOW);  //ENCIENDE LED ROJO
digitalWrite(ledgreen,HIGH); // APAGA LED VERDE
motor_cup_station(dir_back);    //distribuidor de vasos
paso=1;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful.
Serial.flush(); // limpia puerto serial
break;
}

else{
alm=57;
tiempo=1;
paso=17;
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
alm=57;
tiempo=1;
paso=17;
Serial.print("SF_0\n");  // SF - State Finished. 0: Unsuccessful.
horizontal_home(dir_front);
Serial.flush(); // limpia puerto serial

break;
}
  //*****************************************************************
  //************************* caso 4*********************************
  //*****************************************************************
case 4:
Serial.print("4_SS_1\n"); //SS - State Started. 1: Successful.
delay(1000);          //pausa para el agua
motor_alm_station(dir_back, alm);  //corrida al almacenamiento
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
digitalWrite(container6,LOW);
if (alm == 7)
digitalWrite(container7,LOW);
if (alm == 8)
digitalWrite(container8,LOW);
if (alm == 9)
digitalWrite(container9,LOW);
if (alm == 10)
digitalWrite(container10,LOW);
if (alm == 11)
digitalWrite(container11,LOW);
if (alm == 12)
digitalWrite(container12,LOW);
if (alm == 13)
digitalWrite(container13,LOW);
if (alm == 14)
digitalWrite(container14,LOW);
delay(tiempo);          //tiempo en el almacenamiento***************************************
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
motor_water_station(dir_back);  //posicion de bomba de agua
delay(1000);
digitalWrite(water_dispenser,LOW); //encendido de la bomba del agua
if (alm !=0)
delay(water_time);//tiempo de llenado del vaso 
if (alm ==0)
delay(17000);
digitalWrite(water_dispenser,HIGH);  //apagado de la bomba del agua
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
motor_mix_station(dir_back);           //corrida a la licuadora
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
down_m(dir_down);            //motor baja
paso=10;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial
break;

  //*****************************************************************
  //************************* caso 10*********************************
  //*****************************************************************

case 10:
Serial.print("10_SS_1\n"); //SS - State Started. 1: Successful.
digitalWrite(mixer,LOW);// licuadora encendida
if (tiempo/1000<=1)
delay(3000);
if (tiempo/1000>1 && tiempo/1000<8 )
delay(6000);
digitalWrite(mixer,HIGH); //licuadora apagada
paso=11;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;
 //*****************************************************************
  //************************* caso 11*********************************
  //*****************************************************************
case 11:
Serial.print("11_SS_1\n"); //SS - State Started. 1: Successful.
vertical_home(dir_up);                     // motor sube 
digitalWrite(break_motor,HIGH); // freno encendido
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
horizontal_home(dir_front);
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
full_down_m(dir_down);          //motor baja
delay(5500);                    // tiempo de lavado
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

digitalWrite(mixer,LOW);// licuadora encendida
delay(4000);
digitalWrite(mixer,HIGH); //licuadora apagada

paso=15;
Serial.print("SF_1\n");   // SF - State Finished. 1: Successful
Serial.flush(); // limpia puerto serial

break;
 //*****************************************************************
 //************************* caso 15********************************
 //*****************************************************************
case 15:
Serial.print("15_SS_1\n"); //SS - State Started. 1: Successful.

vertical_home(dir_up);
digitalWrite(water_exit,LOW);  // desague del agua encendido 
digitalWrite(break_motor,HIGH); // freno encendido
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
