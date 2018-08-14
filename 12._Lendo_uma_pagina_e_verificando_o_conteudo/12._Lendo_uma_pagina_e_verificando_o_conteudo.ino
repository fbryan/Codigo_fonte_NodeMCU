/* Programa....: 12._Lendo_uma_pagina_e_verificando_o_conteudo.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Conecta em uma rede sem fio e lê uma página específica
 *               e verifica seu conteudo.
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
  pinMode(LED_BUILTIN,OUTPUT);
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
}

void loop() {
  HTTPClient http;
  http.begin("http://seucurso.online/teste.php");
  int codigoHTTP = http.GET();
  if(codigoHTTP == 200) {
    String retorno = http.getString();
    if((retorno.toInt() > 50) && (retorno.toInt() < 59)) {
      digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
      Serial.println(retorno);
    }
  }
}
