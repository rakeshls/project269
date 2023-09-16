//  this module interacts with the hardware on lower level
#include <MD_MAX72xx.h>

//  this module helps to display patterns and animations easily
#include <MD_Parola.h>
#include <SPI.h>

//add the pin numbers to which you have connected your Dot Matrix unit
const byte clock_pin = 13 ;
const byte data_pin = 11 ;
const byte chip_select_pin = 10 ;

const byte max_devices = 4;

// the data variable will hold the string input entered in the serial monitor.
String data = "";

// creating an instance of MD_Parola class
MD_Parola matrix = MD_Parola(MD_MAX72XX::PAROLA_HW, chip_select_pin, max_devices);

void setup(){
  Serial.begin(9660);
  matrix.begin();  //  initialise the module
  matrix.displayClear();  //  clear, if there is anything
  Serial.println("Enter the text to display: ");
}

void loop(){
 
    //write code to create the effect

   if (Serial.available()){
      data = Serial.readStringUntil('\n');
    }
    else if (data != ""){
      matrix.setTextAlignment(PA_CENTER);
      matrix.setInvert(false);
      matrix.print(data);
      delay(1000);
      matrix.setInvert(true);
      matrix.print(data);
      delay(1000);
    }  

}