#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        17 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define pushButton 13

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

int count = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pushButton, INPUT);
    pinMode(16, OUTPUT);
    pixels.begin();

}

long prevTime = millis();

void loop() {
  
  digitalWrite(16, HIGH);

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
           pixels.setPixelColor(0, pixels.Color(0, 0, 0));
           pixels.show();
           break ;
        case STATE_ON:
           pixels.setPixelColor(0, pixels.Color(0, 255, 0));
           pixels.show();
           break ; 
        case STATE_FLASHING:
           while(true){
              pixels.setPixelColor(0, pixels.Color(255, 0, 0));
              pixels.show();
              delay(50) ;
                pixels.setPixelColor(0, pixels.Color(0, 0, 0));
                pixels.show();
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
