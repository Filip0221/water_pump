
const int water_pump = 2;     // uruchamienie pompy wody D2
const int work_mode = 3;      // sterowanie trybem pracy D3
const int flood_sensor_1 = 4; // czujnik zalania 1 dolny D4
const int flood_sensor_2 = 5; // czujnik zalania 2 górny D5
const int led_work_mode_1 = 6;// dioda sygnalizująca tryb pracy z 2 czujnikiem jesli ponad 3/4 wypompuj D6
const int led_work_mode_2 = 7;// dioda sygnalizująca tryb pracy z 1 czujnikiem jesli ponad 1/4 wypompuj D7

void first_work_mode();   // jezeli wiecej niz 3/4 beczki wypompowuj wode
void second_work_mode();  // jezeli wiecej niz 1/4 beczki wypompowuj wode
void start_pump();        // funkcja uruchamiająca pompe wody
void stop_pump();         // funkcja stopująca pompe wody

void setup() {
  pinMode(water_pump, OUTPUT);
  pinMode(work_mode, INPUT_PULLUP);
  pinMode(flood_sensor_1, INPUT_PULLUP);
  pinMode(flood_sensor_2, INPUT_PULLUP);
  pinMode(led_work_mode_1, OUTPUT);
  pinMode(led_work_mode_2, OUTPUT);
}

void loop() {
  if (digitalRead(work_mode) == LOW){
    digitalWrite(led_work_mode_1, HIGH);
    digitalWrite(led_work_mode_2, LOW);
    first_work_mode();
  }
  else{
    digitalWrite(led_work_mode_2, HIGH);
    digitalWrite(led_work_mode_1, LOW);
    second_work_mode();
  }
}
void first_work_mode(){ // jezeli wiecej niz 3/4 beczki wypompowuj wode
  while(digitalRead(flood_sensor_2) == LOW && (digitalRead(work_mode) == LOW)){
    start_pump();
  }
  stop_pump();
}
void second_work_mode(){ // jezeli wiecej niz 1/4 beczki wypompowuj wode
  while(digitalRead(flood_sensor_1) == LOW && (digitalRead(work_mode) == HIGH)){
    start_pump();
  }
  stop_pump();
}
void start_pump(){ // funkcja uruchamiająca pompe wody
  digitalWrite(water_pump, LOW);
}

void stop_pump(){ // funkcja stopująca pompe wody
  digitalWrite(water_pump, HIGH);
}
