/* Programa....: 17._Como_um_access_point_sem_senha.ino
 * Autor.......: Fernando Bryan Frizzarin
 * Observações.: Funciona como um access point que aceita conexões
 *               de qualquer dispositivo wifi.
 *               Fornece endereço IP via DHCP para os clientes.
 *               IP fornecido é sempre acima do final 100.
 *               O nome da rede pode ter no máximo 64 caracteres.
 * Montagem....: Não há montagem necessária
 */
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
 
ESP8266WebServer servidor(80);

IPAddress local_IP(192, 168, 0, 1);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

char ssid[] = "meu_AP_sem_senha";

int clientes = 0;
String pagina = "";

void setup()
{
  Serial.begin(9600);
  if(WiFi.softAPConfig(local_IP, gateway, subnet)) {
    Serial.println("OK");
  } else {
    Serial.println("Falhou!");
    while(true);
  }
  if(WiFi.softAP(ssid)) {
    Serial.println("OK");
  } else {
    Serial.println("Falhou!");
    while(true);
  }
  Serial.print("Endereço IP do Access Point = ");
  Serial.println(WiFi.softAPIP());
  servidor.on("/", [](){
    pagina = "<html>"
             "<head>"
               "<title>NodeMCU como Ponto de Acesso</title>"
             "</head>"
             "<body>"
               "<h1>Numero de clientes conectados nesse momento:</h1>"
               "<p><center><h1><b>" + String(clientes) + "</b></h1></center></p>"
             "</body>"
           "</html>";
    servidor.send(200, "text/html", pagina);
  });
  servidor.begin();
}

void loop() {
  if (WiFi.softAPgetStationNum() != clientes) {
    clientes = WiFi.softAPgetStationNum();
    Serial.println("Numero de clientes = " + String(clientes));
  }
  servidor.handleClient();
}
