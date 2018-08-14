/* Programa....: 25._Piscar_LED_com_delay_atrasando.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Pisca o LED embutido a cada segundo, mas a função delay irá atrapalhar
 *               fazendo com que o tempo seja de 2 segundos
 * Montagem....: Não há montagem necessária
 */
 
unsigned long anterior = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  unsigned long atual = millis();

  if (atual - anterior >= 1000) {
    anterior = atual;
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
  delay(2000);
}
