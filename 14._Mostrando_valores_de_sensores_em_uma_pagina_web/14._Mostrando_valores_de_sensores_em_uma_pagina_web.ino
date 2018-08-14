/* Programa....: 14._Mostrando_valores_de_sensores_em_uma_pagina_web.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Mostra valores lidos de um potenciômetro em uma página
 *               web
 * Montagem....: Não há montagem necessária
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
ESP8266WebServer servidor(80);

int sensor = 0;
int potenciometro = A0;
String pagina = "";
int tentativas = 50;
char ssid[] = "iPhone de Fernando Bryan";
char senha[] = "biycoj7s5s9cs";

void setup(void){
  pinMode(potenciometro,INPUT);
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
  Serial.println();
  Serial.print("Conectado em ");
  Serial.println(ssid);
  Serial.print("Meu endereço IP = ");
  Serial.println(WiFi.localIP());
   
  servidor.on("/", [](){
    pagina = "<html>"
             "<head>"
               "<title>Dados potenciometro</title>"
             "</head>"
             "<body>"
               "<h1>O potenciometro do NodeMCU esta em:</h1>"
               "<p><b>" + String(sensor) + "</b></p>"
             "</body>"
           "</html>";
    servidor.send(200, "text/html", pagina);
  });
  servidor.begin();
  Serial.println("Servidor WEB iniciado!");
}
 
void loop(void){
  sensor = analogRead(potenciometro);
  servidor.handleClient();
}
