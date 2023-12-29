int led_pin = 1;

double getRandomValue() {
  static const int freq_min = 0.1;
  static const int freq_max = 5.0;

  long val_rnd = random(long(freq_min * 10.0f), long(freq_max * 10.0f));
  return val_rnd / 10.0f;
}

double getLEDValue(const double freq, const double time) {
  double val_sin = sin(TWO_PI * (freq / 2.0f) * time);
  double val_abs = abs(val_sin);

  return val_abs;
}

void analogOutput(const pin_size_t pinNumber, const double value) {
  // move value 0.0-1.0 to 0-255
  int value_in_analog = int(value * 255);
  analogWrite(pinNumber, value_in_analog);
}

void setup() {
  pinMode(led_pin, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  double freq = getRandomValue();

  for (double time = 0; time < 7; time += 0.01) {
    double value = getLEDValue(freq, time);
    analogOutput(led_pin, value);

    delay(10);
  }
}
