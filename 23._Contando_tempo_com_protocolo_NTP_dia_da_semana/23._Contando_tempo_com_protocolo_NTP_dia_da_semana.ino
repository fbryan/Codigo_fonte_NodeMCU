/* Programa....: 23._Contando_tempo_com_protocolo_NTP_dia_da_semana.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Conecta a uma rede sem fio e usa um servidor NTP 
 *               para obter a contagem de tempo.
 * Montagem....: Não há montagem necessária
 */
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
 
int tentativas = 50;
char ssid[] = "iPhone de Fernando Bryan";
char senha[] = "biycoj7s5s9cs";

WiFiUDP ntpUDP;
NTPClient cliente(ntpUDP);
 
void setup(){
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
  cliente.begin();
  cliente.update();
}
 
void loop() {
    Serial.print("Dia....: ");
    String dia;
    switch(cliente.getDay()) {
      case 0: dia = "Domingo"; break;
      case 1: dia = "Segunda"; break;
      case 2: dia = "Terça"; break;
      case 3: dia = "Quarta"; break;
      case 4: dia = "Quinta"; break;
      case 5: dia = "Sexta"; break;
      case 6: dia = "Sabado"; break;
    }
    Serial.println(dia);
    Serial.print("Hora...: ");
    Serial.println(cliente.getHours());
    Serial.print("Minuto.: ");
    Serial.println(cliente.getMinutes());
    Serial.print("Segundo: ");
    Serial.println(cliente.getSeconds());
    delay(1000);
    cliente.update();
}
