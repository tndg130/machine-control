int steps2; 
int steps;
int steps3;
int in_steps;
int steps_down;
int steps_up;
int tiempo=1;
int alm=57;
int paso=0;
bool turnon = false; 
String inputString = ""; 

#define water_time                         // tiempo de dispensado de agua


////////////////////////////////////IO PINS/////////////////////

// -------------------------drivers motore----------------------------------
//_______variable_______________PIN_________Descripcion___________________

#define pwm_big                  2         // pwm motor vertical con freno (PULL) 
#define pwm_small                3         // pwm motor horizontal (PULL)
#define direction_big            4         //direccion motor vertical (DIR)
#define direction_small          5         // direccion motor horizontal (DIR)
#define break_motor              6         // freno motor vertical 
#define holdoff_mbig             7         // hold off motor vertical (ENA)
#define holdoff_msmall           8         // hold off motor horizontal (ENA)


// -------------------------dispensador de vasos ------------------------
//_______variable_______________PIN_________Descripcion___________________

#define distributor              9          //distribuidor de vasos 
#define sensor_distributor       10        // relevador interno del distribuidor de vasos

// -------------------------valvulas ------------------------------------
//_______variable_______________PIN_________Descripcion___________________

#define water_entrance           11        // valbula de entrada de agua de lavadora 
#define water_exit               12        // valvula de salida de agua de la lavadora
#define water_dispenser          13        // valvula de dispensado de agua

// -------------------------MOTORES DC ------------------------------------
//_______variable_______________PIN_________Descripcion___________________

#define container1               22        // M1 motor DC contenedor 1
#define container2               23        // M2 motor DC contenedor 2      
#define container3               24        // M3 motor DC contenedor 3
#define container4               25        // M4 motor DC contenedor 4
#define container5               26        // M5 motor DC contenedor 5
#define container6               27        // M6 motor DC contenedor 6
#define container7               28        // M7 motor DC contenedor 7
#define container8               29        // M8 motor DC contenedor 8
#define container9               30        // M9 motor DC contenedor 9
#define container10              31        // M10 motor DC contenedor 10
#define container11              32        // M11 motor DC contenedor 11
#define container12              33        // M12 motor DC contenedor 12
#define container13              34        // M13 motor DC contenedor 13
#define container14              35        // M14 motor DC contenedor 14

// -------------------------sensores infrarrojs --------------------------
//_______variable_______________PIN_________Descripcion___________________

#define s_container1             36        //sensor infrarrojo contenedor 1
#define s_container2             37        //sensor infrarrojo contenedor 2
#define s_container3             38        //sensor infrarrojo contenedor 3
#define s_container4             39        //sensor infrarrojo contenedor 4
#define s_container5             40        //sensor infrarrojo contenedor 5
#define s_container6             41        //sensor infrarrojo contenedor 6
#define s_container7             42        //sensor infrarrojo contenedor 7
#define s_container8             43        //sensor infrarrojo contenedor 8
#define s_container9             44        //sensor infrarrojo contenedor 9
#define s_container10            45        //sensor infrarrojo contenedor 10
#define s_container11            46        //sensor infrarrojo contenedor 11
#define s_container12            47        //sensor infrarrojo contenedor 12
#define s_container13            48        //sensor infrarrojo contenedor 13
#define s_container14            49        //sensor infrarrojo contenedor 14
#define s_forgotten_cup          50        //sensor infrarrojo inicio (x17)
#define s_no_cup                 51        //sensor infrarojo contenedor de vaso (x16)
#define s_no_cup_Ondispenser     52        //sensor infrarrojo dispensador de vasos (x15)

// -------------------------sensores infrarrojs --------------------------
//_______variable_______________PIN_________Descripcion___________________

#define station_cup_distribution A0        // sensor distribuidor de vasos (f3)
#define s_satation_1             A1        // sensor estacion 1(f4)
#define s_satation_2             A2        // sensor estacion 2(f5)
#define s_satation_3             A3        // sensor estacion 3(f6)
#define s_satation_4             A4        // sensor estacion 4(f7)
#define s_satation_5             A5        // sensor estacion 5(f8)
#define s_satation_6             A6        // sensor estacion 6(f9)
#define s_satation_7             A7        // sensor estacion 7(f10)
#define start_career_sm          A8        // sensor inicio de carrera banda horizontal (f1)
#define end_career_sm            A9        // sensor final de carrera banda horizontal (f2)
#define start_career_bm          A10       // sensor inicio de carrera banda vertical (f11)
#define mix_pos_bm               A11       // sensor punto medio banda vertical (f12)
#define end_career_bm            A12       // sensor final de carrera banda vertical  (f13)
#define s_water_distribution     A13       // sensor distribucion de agua (f14)

// -------------------------LEDS-------------------------------------------
//_______variable_______________PIN_________Descripcion___________________

#define ledred                   A14        // LED ROJO
#define ledgreen                 A15        //LED VERDE 

// -------------------------LICUADORA --------------------------
//_______variable_______________PIN_________Descripcion___________________

#define mixer_a                  53        //licuadora (L1)
