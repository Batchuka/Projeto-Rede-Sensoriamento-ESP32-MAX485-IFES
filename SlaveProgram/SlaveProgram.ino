#define SerialTxControl 2
#define RS485Transmit HIGH
#define RS485Receive LOW

char buffer[100];
byte state = 0;

void setup(void) {
  Serial.begin (9600);
  pinMode(13, OUTPUT);
  pinMode(SerialTxControl, OUTPUT);
  digitalWrite(SerialTxControl, RS485Receive);

}

void loop(void) {
  int i = 0;
  
  // se qualquer informação chegar
  if(Serial.available())
  {
    // esperamos que toda ela chegue no registrador da porta
    delay(5);
    // enquanto houver informação na porta, escrevemos para o buffer
    while(Serial.available())
    {
      buffer[i++] = Serial.read();
    }
  }

  // se houver alguma coisa no buffer
  if(i>0)
  {
    // adicionamos o terminador para transformar o buffer em string
    buffer[i++] ='\0';
    // se a string formada for 'ping', é uma chamada para piscar o LED
    if(strcmp(buffer,"ping"))
    {
      // chamamos a função de escrita para a porta 13 (onde está o LED). Escreveremos 'state'
      digitalWrite(13,state);
      state =! state;
    }
  }
}
