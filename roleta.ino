// Parametros:
int num_leds = 16; // Quantidade de LEDs
int fast = 100; // Velocidade (Quanto maior mais lento)
int slow_down = 5; // Desaceleraçao (Quanto maior mais lento)
float slow_lap = 1.5; // Voltas des Desaceleraçao 
int min_lap = 2; // Minimo de voltas
int max_lap = 4; // Maximo de voltas

int start_led = 30;
int end_led = start_led + num_leds;
int button = 3;
int buzzer = 2;
int led;

void turn(int num){
  int cont = num;
  int cont2 = 0;
  led=start_led;
  while(cont > 0){
    digitalWrite(led, 0);
    led++;
    if (led == end_led){
      led = start_led;
    }
    tone(buzzer, 200, 80);
    digitalWrite(led, 1);
    delay(fast+cont2);
    if(cont< (num_leds*slow_lap)){
      cont2 += slow_down;
    }
    Serial.print("Led ");
    Serial.print(led);
    Serial.println(" ligado.");
    cont--;
  }
}

void clean(){
  for(led=start_led;led<end_led;led++){
    digitalWrite(led, 0);
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando....");
  for(led=start_led;led<end_led;led++){
    pinMode(led, OUTPUT);
    Serial.print("Led ");
    Serial.print(led);
    Serial.println(" ativado.");
  }
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  if(digitalRead(button)==1){
    clean();
    turn(random(num_leds*min_lap,num_leds*max_lap));
    delay(50);
  }
}
