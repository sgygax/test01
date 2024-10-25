void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  while(1){
    _int_disable();
    ///*
    // ton = 272 nsec
    GPIO4_DR|=(1U<<6); //digitalWrite(13, HIGH);
    GPIO4_DR&=(~(1U<<6)); //digitalWrite(13, LOW);
    //*/
    
    // ton = 900 nsec
    //digitalWrite(13, HIGH);
    //digitalWrite(13, LOW);
    
    _int_enable();
    delay(10);
  }
}
