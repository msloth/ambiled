

String inputString = "";
boolean stringComplete = false;

#define NUM_LEDS       200
#define STRING_LEN_MAX  (NUM_LEDS * 3 + 10) // 3 bytes per pixel plus some extra

void setup() {
  // initialize serial:
  Serial.begin(115200);
  // reserve 200 bytes for the inputString:
  inputString.reserve(STRING_LEN_MAX);
}

void loop() {
  if(stringComplete) {
    Serial.println(inputString); 
    inputString = "";
    stringComplete = false;
  }
}


/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  */
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read(); 
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}

