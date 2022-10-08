int W_PIN, X_PIN;     //USE THESE VARIABLES FOR W and X PINS
int Y_PIN, Z_PIN;     //USE THESE VARIABLES FOR Y and Z PINS
int w_value, x_value;   //USE THESE VARIABLES FOR  
              //THE VALUES OF W and X
int y_value, z_value;   //USE THESE VARIABLES FOR  
              //THE VALUES OF Y and Z
int counter = 0;    //USE THIS AS YOUR COUNTER VARIABLE

void printOutput();   //Function for printing output for
            //for varifivation

void setup()
{
  
  /*
  Put code here that you would like to happen once
  at the start of the program.
  */
  
  //YOUR CODE HERE
  
  W_PIN = 36;
  X_PIN = 35;
  Y_PIN = 34;
  Z_PIN = 33;
    
  pinMode(W_PIN, OUTPUT);
  pinMode(X_PIN, OUTPUT);
  pinMode(Y_PIN, OUTPUT);
  pinMode(Z_PIN, OUTPUT);
  
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  
  
  
  // DO NOT EDIT THE CODE BELOW THIS
  Serial.begin(9600); //Initilize the serial monitor
}

void loop()
{
  /*
  Put code here that you would like to be repeated.
  It is recomended that you increment your counter
  BEFORE you set the value of the pins
  */

  //YOUR CODE HERE
  
  counter+=1;
  
  delay(1000);
  
  digitalWrite(W_PIN, LOW);
  digitalWrite(X_PIN, LOW);
  digitalWrite(Y_PIN, LOW);
  digitalWrite(Z_PIN, LOW);

    switch(counter){
      case 1:
        w_value = 0;
        x_value = 0;
        y_value = 0;
        z_value = 0;
        break;
      case 2:
        w_value = 0;
        x_value = 0;
        y_value = 0;
        z_value = 1;
        digitalWrite(Z_PIN, HIGH);
        break;
      case 3:
        w_value = 0;
        x_value = 0;
        y_value = 1;
        z_value = 0;
        digitalWrite(Y_PIN, HIGH);
        break;
      case 4:
        w_value = 0;
        x_value = 0;
        y_value = 1;
        z_value = 1;
        digitalWrite(Y_PIN, HIGH);
        digitalWrite(Z_PIN, HIGH);
        break;
        break;
      case 5:
        w_value = 0;
        x_value = 1;
        y_value = 0;
        z_value = 0;
        digitalWrite(X_PIN, HIGH);
        break;
      case 6:
        w_value = 0;
        x_value = 1;
        y_value = 0;
        z_value = 1;
        digitalWrite(X_PIN, HIGH);
        digitalWrite(Z_PIN, HIGH);
        break;
      case 7:
        w_value = 0;
        x_value = 1;
        y_value = 1;
        z_value = 0;
        digitalWrite(Y_PIN, HIGH);
        digitalWrite(X_PIN, HIGH);
        break;
      case 8:
        w_value = 0;
        x_value = 1;
        y_value = 1;
        z_value = 1;
        digitalWrite(X_PIN, HIGH);
        digitalWrite(Y_PIN, HIGH);
        digitalWrite(Z_PIN, HIGH);
        break;
      case 9:
        w_value = 1;
        x_value = 0;
        y_value = 0;
        z_value = 0;
        digitalWrite(W_PIN, HIGH);
        break;
      case 10:
        w_value = 1;
        x_value = 0;
        y_value = 0;
        z_value = 1;
        digitalWrite(W_PIN, HIGH);
        digitalWrite(Z_PIN, HIGH);
        counter = 0;
        break;
    }

  

  //DO NOT EDIT THE CODE BELOW THIS
  printOutput(); //Print output to serial monitor
}

/*
This function prints the output to the serial console.
Use the serial console to verify that your values are correct
for your counter.

NOTE: If you increment your counter after you set the values,
then the value of the counter will be off by 1. As long as both
the binary values and the counter increment correctly, your design
will work.
*/
void printOutput()
{
  String outputString = "Counter = ";
  outputString += counter;
  outputString += ", WXYZ = ";
  outputString += w_value;
  outputString += x_value;
  outputString += y_value;
  outputString += z_value;
  outputString += ", W = ";
  outputString += w_value;
  outputString += ", X = ";
  outputString += x_value;
  outputString += ", Y = ";
  outputString += y_value;
  outputString += ", Z = ";
  outputString += z_value;
  Serial.println(outputString);
  return;
}

/*
Serial Monitor is below
*/
