/* Programa....: 19._O_sistema_de_arquivos_SPIFFS.ino
   Autor.......: Fernando Bryan Frizzarin
   Observações.: Demonstração de como funciona o sistema de arquivos embutido
                 do NodeMCU - SPIFFS
                 Usa o sistema de arquivo na memória flash do NodeMCU
                 Modos de abertura: w gravação  - se existir é apagado e um novo arquivo criado.
                      r leitura   - o arquivo deve existir.
                      a append    - abre o arquivo para gravação ao final. O arquivo deve existir.
                      w+ gravação - abre o arquivo para atualização (gravar/ler). Se existir é criado um novo.
                      r+ leitura  - abre o arquivo para atualização (gravar/ler). Arquivo deve existir.
                      a+ append   - abre o arquivo para atualização (gravar/ler), dados são adicionados ao final. Arquivo é criado se não existir.
   Montagem....: Não há montagem necessária
*/
#include <FS.h>

String arquivo = "/numero.txt";

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
        String dados = arq.readStringUntil('\n');
        Serial.println("Valor atual = " + dados);
        arq.close();
        File arq = SPIFFS.open(arquivo, "w+");
        if (!arq) {
          Serial.println("Deu alguma coisa errada com o arquivo! (Atualização)");
        } else {
          arq.println(String(dados.toInt()+1));
          arq.close();
        }
      }
    } else {
      Serial.println("O arquivo nao existe!");
      Serial.println("Gravando zero!");
      File arq = SPIFFS.open(arquivo, "w");
      if (!arq) {
        Serial.println("Deu alguma coisa errada com o arquivo! (Gravação)");
      } else {
        arq.println("0");
        arq.close();
      }
    }
  }
}

void loop() {}
