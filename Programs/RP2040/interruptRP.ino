#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define NEOPIN        17 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 

Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIN, NEO_GRB + NEO_KHZ800);

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

Button button1 = {13, 0,false};

#define led 16


static void handle_state( STATE_T state ) ;

long prevTime = millis();
void isr() {
  //Serial.printf("I am indisde isr \n");
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

void setup() {
  Serial.begin(9600);
  pinMode(button1.PIN, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(button1.PIN), isr, LOW);
  pixels.begin();
}

void loop() {
  
  digitalWrite(16, HIGH);

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
              delay(950) ;

              if(button1.pressed == true){
                break;
              }

              
              
           }
           break ;
        default: ;
      
     }
} /*  end handle_state */
