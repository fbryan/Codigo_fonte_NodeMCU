/* Programa....: 09._Definindo_IP_fixo.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Conecta-se a uma rede sem fio e define o endereço
 *               IP, DNS, gateway e máscara de rede manualmente.
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
      while (true);
    }
  }
  IPAddress ip(172, 20, 10, 3);
  IPAddress dns(8, 8, 8, 8);
  IPAddress gateway(172, 20, 10, 1);
  IPAddress mascara(255, 255, 255, 0);
  WiFi.config(ip, dns, gateway, mascara);
  Serial.println("Conectado!");
  Serial.print("IP.............: ");
  Serial.println(WiFi.localIP());
  Serial.print("Máscara de rede: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway........: ");
  Serial.println(WiFi.gatewayIP());
}

void loop() {}

