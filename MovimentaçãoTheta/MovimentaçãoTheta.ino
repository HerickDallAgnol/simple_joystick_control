#include <stdlib.h> // biblioteca para incluir as variáveis com definição de tamanho em bits

#define potx A0 // Potenciômetro X
#define poty A1 // Potenciômetro Y
#define axisx 5 // Eixo X
#define axisy 6 // Eixo Y

void setup() {
  pinMode(axisx, OUTPUT);
  pinMode(axisy, OUTPUT);
  pinMode(potx, INPUT);
  pinMode(poty, INPUT);

  Serial.begin(9600);
}

void loop() {
  uint8_t x = map(analogRead(potx), 0, 1023, 0, 255); // Map faz uma regra de 3 para converter o valor do potenciômetro para o valor do PWM
  uint8_t y = map(analogRead(poty), 0, 1023, 0, 255);
 
  analogWrite(axisx, x); // Escreve o valor na porta
  analogWrite(axisy, y);

  Serial.print("%d, %d\n", x, y);//printa para o monitor serial    
}
