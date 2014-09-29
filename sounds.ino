void calmSound() {
  Music.getPreset(1);

  Music.noteOn(48); 
  delay(1000);
  Music.getPreset(0);
  Music.noteOn(48);
}


void calmSoundShort() {
  Music.getPreset(1);

  Music.noteOn(48); 

  Music.getPreset(0);
  Music.noteOn(48);
}


void happySound(){
      int rootNote = 40;  //48
    const int mySize = 10;
    Music.getPreset(3);

  int note[mySize] = {
     0,3,5,7,4,7,12,5,3,7};
  int note1[mySize]={
     0,3,5,3,0,3,5,3,0,5};  
for (int n = 0; n < mySize; n++){
  Music.noteOn(rootNote+ note1[n]+note[n]);
  delay(100);
  Music.noteOff();
//  int rootNote = 35;
//  const int mySize = 10;
//  Music.getPreset(3);
//
//  int note[mySize] = {
//    0,3,5,7,4,7,12,5,12,7      };
//  for (int n = 0; n < mySize; n++){
//    Music.noteOn(rootNote+note[n]);
//    delay(100);
//    Music.noteOff();
  }
}


