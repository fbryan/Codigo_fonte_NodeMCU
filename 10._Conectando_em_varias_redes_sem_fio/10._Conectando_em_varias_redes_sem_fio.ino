
/* Programa....: 10._Conectando_em_varias_redes_sem_fio.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Configura várias redes sem fio, quando encontrar
 *               alguma delas irá conectar-se.
 * Montagem....: Não há montagem necessária
 */
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

int tentativas = 50;

ESP8266WiFiMulti redes;

void setup()
{
  Serial.begin(9600);
  redes.addAP("iPhone de Fernando Bryan","biycoj7s5s9cs");
  redes.addAP("Rede de Fernando","Xx*23tw_77i20");
  redes.addAP("Rede do Trabalho","7762-8901+837");
  Serial.print("Conectando...");
  while(redes.run() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    tentativas--;
    if (tentativas == 0) {
      Serial.println();
      Serial.println("Time-out. Verifique as configurações e tente novamente.");
      while (true);
    }
  }
  Serial.println("Conectado!");
  Serial.print("REDE...........: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP.............: ");
  Serial.println(WiFi.localIP());
  Serial.print("Máscara de rede: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway........: ");
  Serial.println(WiFi.gatewayIP());
}

void loop() {}

