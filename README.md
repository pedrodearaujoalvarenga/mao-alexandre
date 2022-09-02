# GUIA DO PROJETINHO DA MÃO

## COMO PREPARAR O SEU COMPUTADOR PARA A ESP8266

1) Baixar e instalar a IDE da Arduíno. Qualquer versão serve.
2) Na IDE da Arduíno, vá em "Arquivo" -> "Preferências"
3) Nas preferências, localize "URLs Adicionais para Gerenciadores de Placas"
4) Insira: https://arduino.esp8266.com/stable/package_esp8266com_index.json
5) Isso será necessário pois a IDE da Arduíno está preparada para lidar somente com a placa Arduíno 
porém, existe uma library que você pode baixar que permite que a IDE da Arduíno também funcione na 
ESP8266.
6) Clique em "OK" -> "OK" -> (volte para a IDE normal)
7) Vá em "Ferramentas" -> "Placa" -> "Gerenciador de Placas"
8) Digite "ESP8266". Se você não tiver concluído o passo 4, a ESP8266 não vai aparecer.
9) Clique em "Instalar"
10) Volte, novamente, para o princípio da IDE (dê OK em tudo)
11) Vá em "Ferramentas" -> "Placa" -> "ESP8266 Module" -> Clique na opção "Generic ESP8266 Module"
12) Conecte a ESP8266 no MicroUSB e no seu computador. Em "Ferramentas" -> "Porta"; você deve ver
selecionado uma das portas COM3 COM4 ou outras disponível. Caso contrário, você precisa de instalar
esse driver:
13) https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads
14) Aconselho já baixá-lo caso seja um notebook e você vá pra um lugar que não tenha internet.

Feito tudo isso, você consegue utilizar a ESP8266 e fazer upload de código para ela. É necessário
um cabo MicroUSB, que é aquele de celular antigo.

Caso meu tutorial não seja o suficiente, siga esse, pois tem figuras. É para a ESP32, mas é só
substituir os passos pelos da ESP8266. 
https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/

## COMO FAZER UPLOAD NA ESP8266: 
escrever o código na IDE, clicar na seta e SEGURAR O BOTÃO FLASH DA ESP8266

## SOBRE OS CÓDIGOS QUE DISPONIBILIZEI PARA VOCÊS:

Estou disponibilizando dois códigos para vocês, "código antigo" e "código atual".
Ambos estão comentados, e existe uma seção em ambos que fala "Funções que controlam o braço"

Acredito que, tendo visto algo sobre programação e Arduíno no geral, seja do conhecimento de vocês.
No mais, podem me pedir ajuda. 

Código antigo: Executa o movimento perfeitamente, logo depois a mão abre, e se prepara para executar
o próximo movimento. Bug: O dedo do meio fica se mexendo de modo aleatório depois de um tempo, aleatoriamente.

Código novo: O dedo não fica maluco, mas os movimentos não funcionam adequadamente.

Se tiverem tempo, façam melhorias no código. Peço que tomem cuidado para não forçarem os motores demais, por 
medo de arrebentarem as cordas. Mas não se preocupem, o motor é bem estável, e me parece que não é possível
quebrar ela com simples código kk

## PROBLEMA COMUM QUE VOCÊS ENFRENTARAM

(EXTRA) atenção: Notei que muitos de vocês enfrentaram o problema da placa começar funcionando, e depois parar
de funcionar. Isso acontece porque vocês conectaram no Wi-Fi da placa, mas o seu celular vai querer se desconectar
e conectar no Wi-Fi do CEFET-MG, pois a placa não tem internet, e o CEFET tem.
 
Para resolver isso, vocês devem "Esquecer" todas as redes de Wi-Fi próximas que tenham internet. Perdão, isso é chato,
mas é a única forma de fazer isso. Pedi para o Alexandre para fazer usando a ESP32 (que tem Bluetooth) mas,
infelizmente, a construção dessa mão robótica foi toda feita para a ESP8266.

## SE PUDEREM ME AJUDAR

Se tiverem tempo, façam melhorias no código. Peço que tomem cuidado para não forçarem os motores demais, por 
medo de arrebentarem as cordas. Mas não se preocupem, o motor é bem estável, e me parece que não é possível
quebrar ela com simples código kk

Agradeceria muito, caso vocês pudessem, de tirar fotos bonitas do negócio funcionando ou de algo funcionando
acho que vocês sabem como é, vocês devem ter 16-17; mas eu já tenho quase 20, preciso de achar um trabalho, postar
esse tipo de coisa no meu Instagram me dá muitos "pontos" em arrumar alguma coisa na vida 

## NO MAIS, PODEM CONTAR COMIGO QUALQUER COISA.
