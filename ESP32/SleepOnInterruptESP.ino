struct Button {
  const int PIN;
  volatile bool pressed;
};


RTC_DATA_ATTR int count;

typedef enum {
  STATE_OFF = 0,
  STATE_ON = 1,
  STATE_FLASHING = 2
} STATE_T;

Button button1 = { 0, false };

#define ledR 16
#define ledG 17
#define ledB 18


static void handle_state(STATE_T state);

long prevTime = millis();
void isr() {
  long currentTime = millis();
  if ((currentTime - prevTime) >= 500) {
    prevTime = currentTime;
    count++;
    button1.pressed = true;

    if (count >= 5) {
      count = 0;
    }
  }
}

static void setColor(int R, int G, int B) {
  digitalWrite(ledR, R);
  digitalWrite(ledG, G);
  digitalWrite(ledB, B);
}

void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason){
    case ESP_SLEEP_WAKEUP_EXT0 : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_EXT1 : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case ESP_SLEEP_WAKEUP_TIMER : Serial.println("Wakeup caused by timer"); break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD : Serial.println("Wakeup caused by touchpad"); break;
    case ESP_SLEEP_WAKEUP_ULP : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.printf("Wakeup was not caused by deep sleep: %d\n",wakeup_reason); break;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(button1.PIN, INPUT_PULLUP);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  attachInterrupt(button1.PIN, isr, FALLING);
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_0, 0);
  print_wakeup_reason();
}

void loop() {

  button1.pressed = false;

  switch (count) {
    case 0:
      handle_state(STATE_OFF);
      break;
    case 1:
      handle_state(STATE_ON);
      break;
    case 2:
      handle_state(STATE_FLASHING);
      break;
    case 3:
      esp_light_sleep_start();
      Serial.println("Yellow");
      break;
    case 4:
      count = 0;
      esp_deep_sleep_start();
    default:
      break;
    }
}

static void handle_state(STATE_T state) {
  // Serial.print("Pushed: ");
  // Serial.println(count);

  switch (state) {
    case STATE_OFF:
      setColor(100, 100, 100);
      break;
    case STATE_ON:
      setColor(255, 0, 255);
      break;
    case STATE_FLASHING:
      while (true) {
        setColor(0, 255, 255);
        delay(50);
        setColor(100, 100, 100);
        delay(950);

        if (button1.pressed == true) {
          break;
        }
      }
      break;
    default:;
  }
} /*  end handle_state */