int led_pin = 1;

void setup() {
  pinMode(led_pin, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  double freq = random(1, 50) / 10.0f;

  for(double time=0; time<7; time+=0.01){
    double val_sin = sin(2 * PI * (freq / 2.0f) * time);
    double val_abs = abs(val_sin);
    int val_pin = int(val_abs * 255);

    analogWrite(led_pin, val_pin);
    delay(10);
  }
}
