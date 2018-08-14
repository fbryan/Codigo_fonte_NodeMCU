/* Programa....: 07._Conectando_a_uma_rede.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Conecta em uma rede sem fio mostrando mensagens
 *               no Monitor Serial.
 * Montagem....: Não há montagem necessária
 */
#include <ESP8266WiFi.h>

int tentativas = 50;
char ssid[] = "iPhone de Fernando Bryan";
char senha[] = "biycoj7s5s9cs";

void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, senha);
  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    tentativas--;
    if (tentativas == 0) {
      Serial.println();
      Serial.println("Time-out. Verifique as configurações e tente novamente.");
      while(true);
    }
  }
  Serial.println("Conectado!");
  Serial.print("IP.............: ");
  Serial.println(WiFi.localIP());
  Serial.print("Máscara de rede: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway........: ");
  Serial.println(WiFi.gatewayIP());
}

void loop() {}
