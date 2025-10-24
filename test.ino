const int Pin1 = 8; 
const int Pin2 = 9; 
const int senspin = A0;

const int RELAY_ON = LOW; 
const int RELAY_OFF = HIGH; 

char inp;
bool isMoving = false; 

void setup() {
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  
  digitalWrite(Pin1, RELAY_OFF);
  digitalWrite(Pin2, RELAY_OFF);
  
  Serial.begin(9600); 
  Serial.println(" Type s -> start , p -> stop");
}

void loop() {
  int sensvalue = analogRead(senspin);

  if(Serial.available() > 0){
    inp = Serial.read();
    
    if(inp == 's'){
      isMoving = true;
      Serial.println("Motors Start");
      Serial.print("Sens : ");
      Serial.println(sensvalue);
    }
    else if(inp == 'p'){
      isMoving = false; 
      Serial.println("Motors Stop");
    }
  }

  if (isMoving) { 

    if (sensvalue > 500 && sensvalue < 600){
        
        digitalWrite(Pin1, RELAY_OFF);
        digitalWrite(Pin2, RELAY_OFF);
        isMoving = false; 
        
        Serial.println("sensor detected => Motors Stop");
        Serial.print("sens: ");
        Serial.println(sensvalue);
    }
    else {
        digitalWrite(Pin1, RELAY_ON);
        digitalWrite(Pin2, RELAY_ON);
    }
  }
  
  else {
      digitalWrite(Pin1, RELAY_OFF);
      digitalWrite(Pin2, RELAY_OFF);
  }
}
