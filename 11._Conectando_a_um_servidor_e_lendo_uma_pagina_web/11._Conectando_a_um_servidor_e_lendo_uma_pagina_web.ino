/* Programa....: 11._Conectando_a_um_servidor_e_lendo_uma_pagina_web.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Conecta em uma rede sem fio e lê uma página específica.
 * Montagem....: Não há montagem necessária
 */
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

int tentativas = 50;
char ssid[] = "iPhone de Fernando Bryan";
char senha[] = "biycoj7s5s9cs";
IPAddress servidor(74,125,115,105);
WiFiClient cliente;

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
  Serial.println("Pagina lida:");
  HTTPClient http;
  http.begin("http://seucurso.online/teste.php");
  int codigoHTTP = http.GET();
  if(codigoHTTP == 200) {
    Serial.println(http.getString());
  }
  WiFi.disconnect();
}

void loop() {}
