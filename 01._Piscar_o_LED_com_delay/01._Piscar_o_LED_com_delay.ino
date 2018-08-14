/* Programa....: 01._Piscar_o_LED_com_delay.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Não é preciso saber o pino do LED, que é o 16,
 *               basta usar a constante LED_BUILTIN
 * Montagem....: Não há montagem necessária
 */
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}
