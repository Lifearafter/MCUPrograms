int Y_PIN, Z_PIN; 		//USE THESE VARIABLES FOR Y and Z PINS

int y_value, z_value; 	//USE THESE VARIABLES FOR  
					  	          //THE VALUES OF Y and Z
int counter;			//USE THIS AS YOUR COUNTER VARIABLE

void printOutput();		//Function for printing output for
						//for varifivation

void setup()
{
  
  /*
  Put code here that you would like to happen once
  at the start of the program.
  */
  
  //YOUR CODE HERE

    
  Z_PIN = 8;
  Y_PIN  = 12;

  pinmode(Z_PIN, OUTPUT);
  pinMode(Y_PIN, OUTPUT);

  counter = 0;

  loop();
  
  
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

  digitalWrite(Y_PIN, LOW);
  digitalWrite(Z_PIN, LOW)

  switch(counter){
    case 0:
      y_value = 0;
      z_value = 0;
      break;
    case 1:
      y_value = 0;
      z_value = 1;

      digitalWrite(Z_PIN, HIGH)
      break;
    case 2:
      y_value = 1;
      z_value = 0;

      digitalWrite(Y_PIN, HIGH)
      break;
    case 2:
      y_value = 1;
      z_value = 1;

      digitalWrite(Y_PIN, HIGH)
      digitalWrite(Z_PIN, HIGH)
      break;
  }

  counter++;
  delay(500)
  
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
  outputString += ", YZ = ";
  outputString += y_value;
  outputString += z_value;
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