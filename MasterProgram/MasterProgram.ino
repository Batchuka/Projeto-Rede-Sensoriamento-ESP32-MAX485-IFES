#define SerialTxControl 2
#define RS485Transmit HIGH
#define RS485Receive LOW

void setup(void) {
  // Configurando Baud Rate de 9600
  Serial.begin (9600);
  // Configurando porta 2 para OUTPUT
  pinMode (SerialTxControl, OUTPUT);
  // Configurando porta 2 para transmitir nível lógico alto
  digitalWrite (SerialTxControl, RS485Transmit);

}

void loop(void) {
  Serial.print("ping");
  delay(500);
}
