// STROKE SENSOR
long CapacitiveSensorVal() {

  for (int i = 0; i < samplingVal_CapSensor ; i++) {
    capVal = touchRead(A9)/10;
    avgCapVal = avgCapVal + capVal;
    delay(5);
  }
  avgCapVal = avgCapVal / samplingVal_CapSensor;
  delay(5);
  return avgCapVal;
}


