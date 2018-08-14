/* Programa....: 20._Lendo_arquivo_carregado_junto_com_o_programa.ino
   Autor.......: Fernando Bryan Frizzarin
   Observações.: Demonstração de como funciona a leitura de um arquivo
                 que foi carregado pela IDE Arduino
   Montagem....: Não há montagem necessária
*/
#include <FS.h>

String arquivo = "/texto.txt";

void setup() {
  Serial.begin(9600);
  delay(500);
  boolean ok = SPIFFS.begin();
  if (ok) {
    boolean existe = SPIFFS.exists(arquivo);
    if (existe) {
      File arq = SPIFFS.open(arquivo, "r");
      if (!arq) {
        Serial.println("Deu alguma coisa errada com o arquivo! (Leitura)");
      } else {
        Serial.println("O arquivo existe!");
        Serial.println("Tamanho do arquivo = " + String(arq.size()) + " bytes");
        String dados = arq.readString();
        Serial.println("Texto = " + dados);
        arq.close();
      }
    }
  }
}

void loop() {}
