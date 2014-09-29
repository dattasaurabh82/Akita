#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

//SQUEEZE sensor variables
int squeezePin = 7;
boolean isSqueezed;
boolean isVibrating; //has the button been pressed
int nbr_strokes = 0;

//STROKE sensor variables
int capVal;
const int samplingVal_CapSensor = 30;
int avgCapVal;

// for dev
boolean happySwitch = false;

// OOP VIBRATION variables
long interval = 1000;           // interval (milliseconds)
long previousMillis = 0;        // will store last time updated
int vibrateState = 0;
int playSound = 0; 

void setup(){
  //SOUNDS setup
  Music.init();
  Music.enableEnvelope1();
  Music.enableEnvelope2();
  MotorA.init(); //idk why we need this but it doesn't work if we don't have it


}

void loop(){
  unsigned long currentMillis = millis();
  // HAPPY/CALM Switch
  
  if (analogRead(A1) < 10) {
    
    happySwitch = true;
    if (playSound < 1){
    happySound();
    isVibrating = true;
    playSound = 1;
    }

  }
  if (analogRead(A1) >= 10) {
    happySwitch = false;
    
  }

  
  // READ SENSORS
  isSqueezed = digitalRead(7);
  avgCapVal = CapacitiveSensorVal();
    Serial.println(avgCapVal);
//Serial.println(analogRead(A1));

  // SQUEEZE & STROKE LOGIC
  if (isSqueezed) { // squeezed -> nervous
    isVibrating=true;

    calmSound();


  }
  else if (isVibrating && !isSqueezed && avgCapVal > 530) { // stroke 3 times -> not nervous
    nbr_strokes++;
//    Serial.println(analogRead(avgCapVal));
    if (nbr_strokes >= 3) {
      isVibrating=false;
      nbr_strokes = 0;
    }
  }

  // MOTORS & MUSIC OUTPUT
  if (isVibrating) {
//    calmSoundShort();
    if (happySwitch) {
      randomVibrate();
    }
    else {
      if (currentMillis - previousMillis > interval){
        previousMillis = currentMillis;
        vibrateState++;
        if (vibrateState == 3) {
          vibrateState = 0;
        }
        simpleVibrate(vibrateState);
      }
    }
  }
  if (!isVibrating) {
    //other sound?
    playSound = 0;
    blankVibrate();
  }


}










