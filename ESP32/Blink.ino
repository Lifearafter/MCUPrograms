int LED_BUILTIN_BLUE = 18;
int LED_BUILTIN_GREEN = 17;
int LED_BUILTIN_RED = 16;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN_BLUE, OUTPUT ) ;
  pinMode(LED_BUILTIN_GREEN, OUTPUT);
  pinMode(LED_BUILTIN_RED, OUTPUT);

}

void loop() {

  setColor(0, 255, 255);
  delay(4000);
  setColor(100,100,100);
  delay(3000);
  setColor(255,0,255);
  delay(2000);
  setColor(100,100,100);
  delay(3000);
}

void setColor(int R, int G, int B) {
  digitalWrite(LED_BUILTIN_RED,   R);
  digitalWrite(LED_BUILTIN_GREEN, G);
  digitalWrite(LED_BUILTIN_BLUE,  B);
}
