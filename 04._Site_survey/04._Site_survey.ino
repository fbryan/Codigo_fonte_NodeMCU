/* Programa....: 04._Site_survey.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Faz uma busca por redes sem fio ao alcance e
 *               mostra no Monitor Serial.
 * Montagem....: Não há montagem necessária
 */
#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando");
  delay(500);
  Serial.println("Procurando redes...");
  int qtde_redes = WiFi.scanNetworks();
  Serial.println("Redes encontradas:");
  for (int i = 0; i < qtde_redes; i++) {
    Serial.print("Nome da rede...........: ");
    Serial.println(WiFi.SSID(i));
    Serial.print("Potencia do Sinal (dBm): ");
    Serial.println(WiFi.RSSI(i));
    Serial.println("-----------------------");
  }
}

void loop() {}
