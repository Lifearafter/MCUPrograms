const int ledS = 17 ;   /* GREEN */
const int ledR = 16;
const int ledB = 18;
const int pushButton = 0;

typedef enum {
   STATE_OFF = 0,
   STATE_ON  = 1,
   STATE_FLASHING = 2  
} STATE_T ;

#if defined(ESP32)
#undef ACTIVE_HIGH_LED 
#endif /* ESP32 */

#ifdef ACTIVE_HIGH_LED
typedef enum {
  LED_OFF_T = LOW,
  LED_ON_T = HIGH
} LED_STATE_T ;
#else
typedef enum {
  LED_OFF_T = HIGH,
  LED_ON_T = LOW
} LED_STATE_T ;
#endif /* ACTIVE_LOW_LED */
 
static void handle_state( STATE_T state ) ;

static bool newState();

static void setColor(int R, int G, int B);

int count = 0;

void setup() {
    Serial.begin(9600);
    pinMode( ledS, OUTPUT ) ;
    pinMode(pushButton, INPUT);
    pinMode(ledR, OUTPUT);
    pinMode(ledB,OUTPUT); 

}

long prevTime = millis();

void loop() {

  delay(1);
  if(newState() == true){
      Serial.println("Button is pressed.");
      count++;
      if (count >= 3){
          count = 0;
      }
    }
  
  switch(count){
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
      break;  
    }
    

}

static void handle_state( STATE_T state )
{
     Serial.print("Pushed: ");
     Serial.println(count);
     
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
              bool tempBreak = false;
              for(int i = 0; i < 950; i++){
                delay(1) ;
                if(newState() == true){
                  tempBreak = true;
                  count = 0;
                  break;  
                }
              }
              if(tempBreak == true){
                break;
              }
              
           }
           break ;
        default: ;
      
     }
} /*  end handle_state */

static bool newState(){
  long currentTime = millis();
  if((currentTime - prevTime) > 150){
    prevTime = currentTime;
    if(digitalRead(pushButton) == LOW){
      return true;
    }
  }
  return false;
  
}

static void setColor(int R, int G, int B) {
  digitalWrite(ledR,   R);
  digitalWrite(ledS, G);
  digitalWrite(ledB,  B);
}
