/* Programa....: 27._Execucao_agendada_com_delay.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Pisca o LED embutido a cada segundo
 * Montagem....: Não há montagem necessária
 */
#include <Ticker.h>

Ticker agenda;

void pisca() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  agenda.attach(1, pisca);
}

void loop() {
  delay(10000);
}
