
#define Relay_1 12

void setup() {

  Serial.begin(115200);
  
  pinMode(Relay_1, OUTPUT);
  
  digitalWrite(Relay_1, HIGH);  
  
}

void loop() {
  
  if (Serial.available()) {
    
    char inChar = Serial.read();

    // Serial.print(inChar);
    
    if (inChar == '1') {
      
      digitalWrite(Relay_1, LOW);
    }
    else if (inChar == '0') {
      
      digitalWrite(Relay_1, HIGH);
    }
  }

}

// void loop() {
  
//   if (Serial.available()) {
    
//     int getdata = Serial.parseInt();

//     Serial.print(getdata);
//     if (getdata != 0)
//     {
//       if (getdata > 100) {
//       digitalWrite(Relay_1, LOW);
//       }
//       else if (getdata <= 10) {
      
//       digitalWrite(Relay_1, HIGH);
//     }
//     }
    
//   }

// }



