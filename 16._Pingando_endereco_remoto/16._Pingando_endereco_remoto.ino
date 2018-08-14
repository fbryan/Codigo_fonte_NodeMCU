/* Programa....: 16._Pingando_endereco_remoto.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Verifica a existência de um endereço remoto através
 *               do envio de pacotes PING
 * Montagem....: Não há montagem necessária
 */
#include <ESP8266Ping.h>
#include <ESP8266WiFi.h>

int tentativas = 50;
char ssid[] = "iPhone de Fernando Bryan";
char senha[] = "biycoj7s5s9cs";

// IPAddress endereco_remoto(1, 217, 28, 67);
char* endereco_remoto = "www.google.com.br";

void setup() {
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
  Serial.println();
  Serial.print("Endereço IP local = ");  
  Serial.println(WiFi.localIP());

  Serial.print("Pingando o IP remoto = ");
  Serial.println(endereco_remoto);

  if(Ping.ping(endereco_remoto)) {
    Serial.println("Sucesso!");
    Serial.println("Tempo de resposta: " + String(Ping.averageTime()) + "ms");
  } else {
    Serial.println("Erro!");
  }
}

void loop() {}
