/* Programa....: 22._Contando_tempo_com_protocolo_NTP_configuracoes.ino
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
char servidor[] = "a.stl.ntp.br";
long fuso = -3 * 60 * 60;
int tempoAtual, tempoAnterior, contador;

WiFiUDP ntpUDP;
NTPClient cliente(ntpUDP,servidor,fuso);
 
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
  tempoAtual = millis();
  if (tempoAtual - tempoAnterior > 1000) {
    tempoAnterior = tempoAtual;
    contador++;
    Serial.println("Hora atual: ");
    Serial.println(cliente.getFormattedTime());
  }
  if (contador >= 86400) {
    cliente.update();
    contador = 0;
  }
}
