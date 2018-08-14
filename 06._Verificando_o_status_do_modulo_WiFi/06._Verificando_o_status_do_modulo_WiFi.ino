/* Programa....: 06._Verificando_o_status_do_modulo_WiFi.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: É o mesmo programa que o anterior, porém verifica
 *               se o módulo Wifi está funcionando corretamente
 *               antes de qualquer coisa. Caso não esteja interrompe
 *               o funcionamento do programa e mostra no Monitor Serial.
 *               Também espera que a busca por redes esteja completa antes
 *               de continuar.
 * Montagem....: Não há montagem necessária
 */
#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando");
  delay(500);
  if(WiFi.status() == WL_NO_SHIELD) {
    Serial.println("Modulo Wifi não está presente!");
    while(true);
  }
  Serial.println("Procurando redes...");
  int qtde_redes = WiFi.scanNetworks();
  Serial.println("Redes encontradas:");
  for (int i = 0; i < qtde_redes; i++) {
    Serial.print("Nome da rede...........: ");
    Serial.println(WiFi.SSID(i));
    Serial.print("Potencia do Sinal (dBm): ");
    Serial.println(WiFi.RSSI(i));
    Serial.print("Tipo de criptografia...: ");
    String cripto;
    switch(WiFi.encryptionType(i)) {
      case 2: cripto = "TKIP (WPA)"; break;
      case 4: cripto = "CCMP (WPA)"; break;
      case 5: cripto = "WEP"; break;
      case 7: cripto = "Nenhuma"; break;
      case 8: cripto = "AUTO"; break;
    }
    Serial.println(cripto);
    Serial.println("-----------------------");
  }
}

void loop() {}
