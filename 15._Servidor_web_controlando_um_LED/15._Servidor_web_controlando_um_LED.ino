/* Programa....: 15._Servidor_web_controlando_um_LED.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Conecta em uma rede sem fio e disponibiliza
 *               uma página web que pode controlar o LED embutido.
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
               "<title>Controla LED</title>"
             "</head>"
             "<body>"
               "<h1>Clique nos botoes para ligar/desligar o LED</h1>"
               "<p><a href='on'><button>LIGAR</button></a></p>"
               "<p><a href='off'><button>DESLIGAR</button></a></p>"
             "</body>"
           "</html>";
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
  Serial.println();
  Serial.print("Conectado em ");
  Serial.println(ssid);
  Serial.print("Meu endereço IP = ");
  Serial.println(WiFi.localIP());
   
  servidor.on("/", [](){
    servidor.send(200, "text/html", pagina);
  });
  servidor.on("/on", [](){
    servidor.send(200, "text/html", pagina);
    digitalWrite(LED_BUILTIN,LOW);
    delay(500);
  });
  servidor.on("/off", [](){
    servidor.send(200, "text/html", pagina);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(500);
  });
  servidor.begin();
  Serial.println("Servidor WEB iniciado!");
}
 
void loop(void){
  servidor.handleClient();
}
