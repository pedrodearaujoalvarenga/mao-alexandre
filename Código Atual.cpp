#include <Servo.h>
#include <ESP8266WiFi.h>

const char * ssid = "Braco_Mecanico";
const char * password = "123456789";
Servo dedoMindinho, dedoAnelar, dedodoMeio, dedoIndicador, dedoPolegar;


// Set web server port number to 80
WiFiServer server(80);

//FUNÇÕES QUE CONTROLAM O BRAÇO (IDEIA DESSE CÓDIGO: "DESATACHAR" O MOTOR APÓS FAZER O MOVIMENTO)

void deAbertoparaFechado(Servo serv, int positionNumber){
  
serv.attach(positionNumber);

  int pos;
  for (pos = serv.read(); pos <= 145; pos += 1) { // movimento de 0 a 180º
    // crescente
    serv.write(pos);              // escreve posicao em meuservo
    delay(4);                       // aguarda 35ms
  }
  
  serv.detach();
}

void deFechadoparaAberto(Servo serv, int positionNumber){

serv.attach(positionNumber);
  int pos;
  for (pos = serv.read(); pos >= 0; pos -= 1) { // movimento de 0 a 180º
    // crescente
    serv.write(pos);              // escreve posicao em meuservo
    delay(4);                       // aguarda 35ms
  }
  
  serv.detach();
}

void posicaoOriginal(){
  dedoMindinho.attach(14);  //D5
  dedoAnelar.attach(16);  //D0
  dedodoMeio.attach(5);  //D1
  dedoIndicador.attach(2);  //D4
  dedoPolegar.attach(0);  //D3
 
  
  dedoMindinho.write(0);
  dedoAnelar.write(0);
  dedodoMeio.write(180);
  dedoIndicador.write(0);
  dedoPolegar.write(0);
  
    dedoMindinho.detach();  //D5
  dedoAnelar.detach();  //D0
  dedodoMeio.detach();  //D1
  dedoIndicador.detach();  //D4
  dedoPolegar.detach();  //D3
  
}

void apontarDedo(){
  dedoMindinho.attach(14);  //D5
  dedoAnelar.attach(16);  //D0
  dedodoMeio.attach(5);  //D1
  dedoIndicador.attach(2);  //D4
  dedoPolegar.attach(0);  //D3
  deAbertoparaFechado(dedoMindinho, 14);
    deAbertoparaFechado(dedoAnelar, 16);
      deFechadoparaAberto(dedodoMeio, 5); //do meio funciona ao contrário
      deFechadoparaAberto(dedoIndicador, 2);
        deAbertoparaFechado(dedoPolegar, 0);
        delay(4000);
        posicaoOriginal();
}

void homemAranha(){
  deFechadoparaAberto(dedoMindinho, 14);
    deAbertoparaFechado(dedoAnelar, 16);
      deFechadoparaAberto(dedodoMeio, 5); //do meio funciona ao contrário
      deFechadoparaAberto(dedoIndicador, 2);
        deFechadoparaAberto(dedoPolegar, 0);
        
        delay(4000);
        posicaoOriginal();
}

void hangLoose(){
    deFechadoparaAberto(dedoMindinho, 14);
    deAbertoparaFechado(dedoAnelar, 16);
      deFechadoparaAberto(dedodoMeio, 5); //do meio funciona ao contrário
      deAbertoparaFechado(dedoIndicador, 2);
        deFechadoparaAberto(dedoPolegar, 0);
        
        delay(4000);
        posicaoOriginal();
}

void revolver(){
      deAbertoparaFechado(dedoMindinho, 14);
    deAbertoparaFechado(dedoAnelar, 16);
      deFechadoparaAberto(dedodoMeio, 5); //do Meio funciona ao contrário
      deFechadoparaAberto(dedoIndicador, 2);
        deFechadoparaAberto(dedoPolegar, 0);
        delay(4000);
        posicaoOriginal();
}


//FUNÇÕES QUE CONTROLAM O BRAÇO ^^


void setup() {

  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  
 
  


  posicaoOriginal();
  
  
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");https://lastminuteengineers.b-cdn.net/wp-content/uploads/iot/ESP8266-Pinout-NodeMCU.png
  Serial.println(IP);
  
  server.begin();

  
}

void loop() {
  WiFiClient client = server.available(); // <- Esperar por clientes

  if (client) {                             // Se tiver um cliente
    Serial.println("Novo cliente.");        // Printar no serial
    String currentLine = "";                // Fazer string para segurar dados
    while (client.connected()) {            // Loopar enquanto o cliente estiver conectado
      if (client.available()) {             // Se tiverem bytes para serem lidos do cliente
        char c = client.read();             // ler este byte
        Serial.write(c);                    // printar no serial
        if (c == '\n') {                    // Se o byte é uma quebra de linha (todos os dados já foram recebidos)

          if (currentLine.length() == 0) {
            // Começos de mensagens HTTP sempre vão começar com o código delas (e.g. HTTP/1.1 200 OK)
            // E o tipo do conteúdo (content-type:text/html)
            client.println("HTTP/1.1 200 OK");
     
      //A partir daqui, é uma página HTML normal.
            client.println("Content-type:text/html");
            client.println();
            client.print("Clique <a href=\"/H\">here</a> para ligar o LED.<br>");
            client.print("Clique <a href=\"/L\">here</a> para desligar o LED.<br>");

            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c; //Adicionar byte na string
        }

   
        if (currentLine.endsWith("GET /HANGLOOSE")) {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          digitalWrite(LED_BUILTIN, HIGH);
hangLoose();
          }
        if (currentLine.endsWith("GET /SPIDERMAN")) {
                    digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          digitalWrite(LED_BUILTIN, HIGH);
homemAranha();
        }
        if (currentLine.endsWith("GET /POINTER")) {
                    digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          digitalWrite(LED_BUILTIN, HIGH);
apontarDedo();
}
        if (currentLine.endsWith("GET /GUN")) {
                    digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          digitalWrite(LED_BUILTIN, HIGH);
revolver();
        }



        
      }
    }
    // fechar a conexão
    client.stop();
    Serial.println("Cliente desconectado.");
  }

}