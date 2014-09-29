//MOTOR PINS
const int r0m1 = 0; //0; //row... motor...
const int r0m2 = 2;//2;
const int r0m3 = 4;//4;
const int r1m1 = 1;
const int r1m2 = 3;
const int r1m3 = 5;

int val = 255; 
int maxValueAttuatore = val;



void simpleVibrate(int state) {
  //vibrate1, vibrate2, vibrate3, updatefunction... 
  if (state == 0) {
  analogWrite(r0m3,0);
  analogWrite(r1m3,0);
 Serial.println("state 0");
  analogWrite(r0m1,val);
   analogWrite(r1m1,val);
  }
  else if (state==1) {
  analogWrite(r0m1,0);
  analogWrite(r1m1,0);

  analogWrite(r0m2,val);
  analogWrite(r1m2,val);
  }
  else if (state ==2) {
  analogWrite(r0m2,0);
  analogWrite(r1m2,0);
  analogWrite(r0m3,val);
  analogWrite(r1m3,val);

  }

}

void blankVibrate(){
  analogWrite(r0m1,0);
  analogWrite(r0m2,0);
  analogWrite(r0m3,0);
  analogWrite(r1m1,0);
  analogWrite(r1m2,0);
  analogWrite(r1m3,0);
}

void randomVibrate() {
  int motors[6]={r0m1, r0m2, r0m3, r1m1, r1m2, r1m3};
  int randomVal = random(0,3); //print int from 0 to 2
  int randomMotor=random(0,6);

 for(int i=randomVal ; i<6 ; i++){
   
  analogWrite(motors[randomMotor], randomVal * val);
  analogWrite(motors[randomMotor+1], randomVal* val);
  analogWrite(motors[randomMotor-1], randomVal * val);  //in case delete this
  
  delay(40);
 }
}

void gradualVibrate() {

  for (int count = 0; count <= maxValueAttuatore; count++){
    Serial.println(count);
    if (count <maxValueAttuatore/4) {
      analogWrite(r0m1, 0);
       analogWrite(r0m2, 0);
      analogWrite(r0m3, 0);
      
      analogWrite(r1m1, 0);
       analogWrite(r1m2, 0);
      analogWrite(r1m3, 0);
    }
    else if (count > maxValueAttuatore/4 && count <= maxValueAttuatore/2) {
      analogWrite(r0m1, maxValueAttuatore/2);
      analogWrite(r0m2, 0);
      analogWrite(r0m3, 0);
      
      analogWrite(r1m1, maxValueAttuatore/2);
      analogWrite(r1m2, 0);
      analogWrite(r1m3, 0);
    }

    else if (count > maxValueAttuatore/2 && count <= ((maxValueAttuatore/4)*3)) {
      analogWrite(r0m1, maxValueAttuatore);
      analogWrite(r0m2, maxValueAttuatore/2);
      analogWrite(r0m3, 0);
      
      analogWrite(r1m1, maxValueAttuatore);
      analogWrite(r1m2, maxValueAttuatore/2);
      analogWrite(r1m3, 0);
    }

    else if (count > ((maxValueAttuatore/4)*3) && count <= maxValueAttuatore) {
      analogWrite(r0m1, 0);
      analogWrite(r0m2, maxValueAttuatore);
      analogWrite(r0m3, maxValueAttuatore/2);
      
      analogWrite(r1m1, 0);
      analogWrite(r1m2, maxValueAttuatore);
      analogWrite(r1m3, maxValueAttuatore/2);
    }
    else if (count == maxValueAttuatore) {
      analogWrite(r0m1,0);
       analogWrite(r0m2, 0);
      analogWrite(r0m3, maxValueAttuatore);
      
      analogWrite(r1m1,0);
       analogWrite(r1m2, 0);
      analogWrite(r1m3, maxValueAttuatore);
      
    }
  }

}
