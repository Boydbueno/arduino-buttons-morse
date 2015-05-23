
#define LONG  1
#define SHORT 2

int longButtonPin = A0;
int shortButtonPin = A1;

boolean longButtonActive = false;
boolean shortButtonActive = false;

long lastLongPress = 0;
long lastShortPress = 0;
long timeSinceLastPress = 0;

int durationChain[4];
int chainLength = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  boolean newLongButtonActive = isActive(analogRead(longButtonPin));
  boolean newShortButtonActive = isActive(analogRead(shortButtonPin));

  if (hasStateChanged(newLongButtonActive, longButtonActive) && newLongButtonActive) {
    long timeSinceLastLongPress = millis() - lastLongPress;
    
    timeSinceLastPress = timeSinceLastLongPress;
    
    if (timeSinceLastLongPress > 10) {
      buttonPressLogic(LONG);
      
      lastLongPress = millis();
    }
  }

  if (hasStateChanged(newShortButtonActive, shortButtonActive) && newShortButtonActive) {
    long timeSinceLastShortPress = millis() - lastShortPress;
    
    timeSinceLastPress = timeSinceLastShortPress;
    
    if (timeSinceLastShortPress > 10) {
      buttonPressLogic(SHORT);
      
      lastShortPress = millis();
    }
  }
  
  // put your main code here, to run repeatedly:
  longButtonActive = newLongButtonActive;
  shortButtonActive = newShortButtonActive;
}

boolean isActive(int sensorValue) {
   return sensorValue == 0; 
}

boolean hasStateChanged(boolean currentState, boolean newState) {
   return currentState != newState;
}

void removePreviousCharacter() {
  Keyboard.write(8);
}

void outputCharacter() {
    if (chainLength == 1) {
      if (durationChain[0] == SHORT) {
        Keyboard.write('e');  
      } else if (durationChain[0] == LONG) {
        Keyboard.write('t'); 
      }
    } else if (chainLength == 2) {
      if (durationChain[0] == SHORT && durationChain[1] == SHORT) {
          Keyboard.write('i');  
      } else if (durationChain[0] == SHORT && durationChain[1] == LONG) {
          Keyboard.write('a');
      } else if (durationChain[0] == LONG && durationChain[1] == SHORT) {
          Keyboard.write('n'); 
      } else if (durationChain[1] == LONG && durationChain[1] == LONG) {
          Keyboard.write('m');
      }
    } else if (chainLength == 3) {
       if (durationChain[0] == SHORT && durationChain[1] == SHORT && durationChain[2] == SHORT) {
          Keyboard.write('s');
       } else if(durationChain[0] == SHORT && durationChain[1] == SHORT && durationChain[2] == LONG) {
          Keyboard.write('u'); 
       } else if(durationChain[0] == SHORT && durationChain[1] == LONG && durationChain[2] == SHORT) {
          Keyboard.write('r'); 
       } else if(durationChain[0] == SHORT && durationChain[1] == LONG && durationChain[2] == LONG) {
          Keyboard.write('w'); 
       } else if(durationChain[0] == LONG && durationChain[1] == SHORT && durationChain[2] == SHORT) {
          Keyboard.write('d'); 
       } else if(durationChain[0] == LONG && durationChain[1] == SHORT && durationChain[2] == LONG) {
          Keyboard.write('k'); 
       } else if(durationChain[0] == LONG && durationChain[1] == LONG && durationChain[2] == SHORT) {
          Keyboard.write('g');
       } else if(durationChain[0] == LONG && durationChain[1] == LONG && durationChain[2] == LONG) {
          Keyboard.write('o'); 
       }
    } else if (chainLength == 4) {
      if (durationChain[0] == SHORT && durationChain[1] == SHORT && durationChain[2] == SHORT && durationChain[3] == SHORT) {
        Keyboard.write('h');
      } else if (durationChain[0] == SHORT && durationChain[1] == SHORT && durationChain[2] == SHORT && durationChain[3] == LONG) {
        Keyboard.write('v');
      } else if (durationChain[0] == SHORT && durationChain[1] == SHORT && durationChain[2] == LONG && durationChain[3] == SHORT) {
        Keyboard.write('f');
      } else if (durationChain[0] == SHORT && durationChain[1] == SHORT && durationChain[2] == LONG && durationChain[3] == LONG) {
        Keyboard.write(176);
      } else if (durationChain[0] == SHORT && durationChain[1] == LONG && durationChain[2] == SHORT && durationChain[3] == SHORT) {
        Keyboard.write('l');
      } else if (durationChain[0] == SHORT && durationChain[1] == LONG && durationChain[2] == SHORT && durationChain[3] == LONG) {
        Keyboard.write('ä');
      } else if (durationChain[0] == SHORT && durationChain[1] == LONG && durationChain[2] == LONG && durationChain[3] == SHORT) {
        Keyboard.write('p');
      } else if (durationChain[0] == SHORT && durationChain[1] == LONG && durationChain[2] == LONG && durationChain[3] == LONG) {
        Keyboard.write('j');
      } else if (durationChain[0] == LONG && durationChain[1] == SHORT && durationChain[2] == SHORT && durationChain[3] == SHORT) {
        Keyboard.write('b');
      } else if (durationChain[0] == LONG && durationChain[1] == SHORT && durationChain[2] == SHORT && durationChain[3] == LONG) {
        Keyboard.write('x');
      } else if (durationChain[0] == LONG && durationChain[1] == SHORT && durationChain[2] == LONG && durationChain[3] == SHORT) {
        Keyboard.write('c');
      } else if (durationChain[0] == LONG && durationChain[1] == SHORT && durationChain[2] == LONG && durationChain[3] == LONG) {
        Keyboard.write('y');
      } else if (durationChain[0] == LONG && durationChain[1] == LONG && durationChain[2] == SHORT && durationChain[3] == SHORT) {
        Keyboard.write('z');
      } else if (durationChain[0] == LONG && durationChain[1] == LONG && durationChain[2] == SHORT && durationChain[3] == LONG) {
        Keyboard.write('q');
      } else if (durationChain[0] == LONG && durationChain[1] == LONG && durationChain[2] == LONG && durationChain[3] == SHORT) {
        Keyboard.write('ö');
      } else if (durationChain[0] == LONG && durationChain[1] == LONG && durationChain[2] == LONG && durationChain[3] == LONG) {
        Keyboard.write(' ');
      }
    }
}

void buttonPressLogic(int duration) {
  if (timeSinceLastPress > 2000) {
     Keyboard.write('_');
     chainLength = 0;  
  }
  
  // Do logic 
  chainLength++;
  
  durationChain[chainLength - 1] = duration;

//  if (chainLength > 1) {
//      removePreviousCharacter();  
//  }  
  
  outputCharacter(); 
}

