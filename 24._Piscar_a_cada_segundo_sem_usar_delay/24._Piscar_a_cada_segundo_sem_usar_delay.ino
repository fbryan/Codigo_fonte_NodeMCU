/* Programa....: 24._Piscar_a_cada_segundo_sem_usar_delay.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Pisca o LED embutido a cada segundo sem usar a função delay
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
}
