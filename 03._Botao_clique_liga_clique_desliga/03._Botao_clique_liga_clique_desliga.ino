/* Programa....: 03._Botao_clique_liga_clique_desliga.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Apertando uma vez o botão o LED acenderá,
 *               apertando novamente o LED apagará.
 * Montagem....: O botão está entre o GPIO12 (D6) e o GND
  */
int botao = 12;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  int leitura = digitalRead(botao);
  if(leitura == LOW) {
    while(leitura == LOW) {
      leitura = digitalRead(botao);
      delay(50);
    }
    int estado = digitalRead(LED_BUILTIN);
    digitalWrite(LED_BUILTIN, !estado);
  }
}
