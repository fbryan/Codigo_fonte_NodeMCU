/* Programa....: 02._Um_botao_LED.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Após a ligação correta do botão, ao mantê-lo
 *               pressioná-lo o LED embutido acenderá.
 *               Os pinos já possuem resistor PULL-UP integrado
 *               que podem ser ativados usando o modo INPUT_PULLUP
 *               A leitura do botão é sempre LOW.
 * Montagem....: O botão 1 está entre o GPIO12 (D6) e o GND
 */
int botao = 12;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  int leitura = digitalRead(botao);
  if(leitura == LOW) {
    digitalWrite(LED_BUILTIN, LOW);  
  } else {
    digitalWrite(LED_BUILTIN, HIGH); 
  }
}
