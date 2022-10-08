struct Button {
  const int PIN;
  volatile int count;
  volatile bool pressed;
};

typedef enum {
   STATE_OFF = 0,
   STATE_ON  = 1,
   STATE_FLASHING = 2  
} STATE_T ;

Button button1 = {0, 0,false};

#define ledR 16
#define ledG 17
#define ledB 18


static void handle_state( STATE_T state ) ;

long prevTime = millis();
void isr() {
  long currentTime = millis();
  if((currentTime-prevTime) >= 500){
    prevTime = currentTime;
    button1.count++;
    button1.pressed = true;
  
    if(button1.count >= 3){
      button1.count = 0;
    }
    }
}

static void setColor(int R, int G, int B) {
  digitalWrite(ledR,   R);
  digitalWrite(ledG, G);
  digitalWrite(ledB,  B);
}

void setup() {
  Serial.begin(9600);
  pinMode(button1.PIN, INPUT_PULLUP);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  attachInterrupt(button1.PIN, isr, FALLING);
}

void loop() {

  button1.pressed = false;
  
  switch(button1.count){
    case 0:
      delay(1000);
      handle_state(STATE_OFF);
      break;
    case 1:
      delay(1000);
      handle_state(STATE_ON);
      break;
    case 2:
      delay(1000);
      handle_state(STATE_FLASHING);
      button1.count = 0;
      break;  
    }
}

static void handle_state( STATE_T state )
{
     Serial.print("Pushed: ");
     Serial.println(button1.count);
     
     switch( state ){
        case STATE_OFF:
           setColor(100,100,100);
           break ;
        case STATE_ON:
           setColor(255, 0, 255);
           break ; 
        case STATE_FLASHING:
           while(true){
              setColor(0, 255, 255);
              delay(50) ;
              setColor(100,100,100);
              delay(950) ;

              if(button1.pressed == true){
                break;
              }

              
              
           }
           break ;
        default: ;
      
     }
} /*  end handle_state */
