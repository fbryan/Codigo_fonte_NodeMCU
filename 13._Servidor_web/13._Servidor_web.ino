/* Programa....: 13._Servidor_web.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Conecta em uma rede sem fio e disponibiliza
 *               uma página web.
 * Montagem....: Não há montagem necessária
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
ESP8266WebServer servidor(80);

int tentativas = 50;
String pagina = "";
char ssid[] = "iPhone de Fernando Bryan";
char senha[] = "biycoj7s5s9cs";

void setup(void){
  pagina = "<html>"
             "<head>"
               "<title>Hello Word!</title>"
             "</head>"
             "<body>"
               "<h1>Minha primeira pagina web.</h1>"
             "</body>"
           "</html>";

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
    servidor.send(200, "text/html", pagina);
  });
  servidor.begin();
  Serial.println("Servidor WEB iniciado!");
}
 
void loop(void){
  servidor.handleClient();
}
