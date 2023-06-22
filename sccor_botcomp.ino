int motorRightA = 8;    //Right Motor-clockwise
int motorRightB = 9;   //Right Motor-anticlockwise
int motorLeftA = 11;    //Left Motor-clockwise
int motorLeftB = 10;    //Left Motor-
//int motorRightA1 = 4;    //Right Motor-clockwise
//int motorRightB1 = 5;   //Right Motor-anticlockwise
//int motorLeftA1= 6;    //Left Motor-clockwise
//int motorLeftB1 = 7;    //Left Motor-

char bt = 0;       //Bluetooth Control
void setup()
{
  pinMode(motorRightA, OUTPUT);
  pinMode(motorRightB, OUTPUT);
  pinMode(motorRightB, OUTPUT);
  pinMode(motorLeftB, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  
  control();
}

// All the Controls of the Soccer Bot
void control() {
  if (Serial.available() > 0)
  {
    bt = Serial.read();
    if (bt == 'F')       //move forwards
    {
      digitalWrite(motorRightA, HIGH);
      digitalWrite(motorLeftA,  0);
      digitalWrite(motorRightB, LOW);
      digitalWrite(motorLeftB, 1);
      
    }

    else if (bt == 'S')     //stop!
    {
      digitalWrite(motorRightA, LOW);
      digitalWrite(motorRightB, LOW);
      digitalWrite(motorLeftA, LOW);
      digitalWrite(motorLeftB, LOW);
      
    }
    else if (bt == 'R')    //right
    {
      digitalWrite(motorRightA, LOW);
      digitalWrite(motorRightB, LOW);
      digitalWrite(motorLeftA, 0);
      digitalWrite(motorLeftB, 1);
      
    }
    else if (bt == 'L')     //left
    {
      digitalWrite(motorRightA, HIGH);
      digitalWrite(motorRightB, LOW);
      digitalWrite(motorLeftA, LOW);
      digitalWrite(motorLeftB, LOW);
      
    }
    else if (bt == 'G')    //forward right
    {
      digitalWrite(motorRightA, HIGH);
      digitalWrite(motorRightB, LOW);
      digitalWrite(motorLeftA, 1);
      digitalWrite(motorLeftB, 0);
      
    }
    else if (bt == 'I')    //forward left
    {
      digitalWrite(motorRightA, LOW);
      digitalWrite(motorRightB, HIGH);
      digitalWrite(motorLeftA, 0);
      digitalWrite(motorLeftB, 1);
      
    }
    else if (bt == 'B')       //move backwards
    {
      digitalWrite(motorRightB, HIGH);
      digitalWrite(motorLeftB, 0);
      digitalWrite(motorRightA, LOW);
      digitalWrite(motorLeftA, 1);
      

    }
  }
}
