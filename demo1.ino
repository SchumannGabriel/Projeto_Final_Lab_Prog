#include <SPI.h>
#include <MFRC522.h>

// Definições dos pinos
#define SS_PIN 10    // Pino para SDA/SS do módulo RC522
#define RST_PIN 9    // Pino para RST do módulo RC522

// Inicializa o módulo RFID
MFRC522 rfid(SS_PIN, RST_PIN);

// LEDs para indicar acesso
const int led_verde = 5;   // LED verde para acesso liberado
const int led_vermelho = 6; // LED vermelho para acesso negado

void setup() {
  // Configuração dos LEDs
  pinMode(led_verde, OUTPUT);
  pinMode(led_vermelho, OUTPUT);

  // Inicializa comunicação serial e SPI
  Serial.begin(9600);
  SPI.begin();

  // Inicializa o módulo RFID
  rfid.PCD_Init();
  Serial.println("Sistema de Controle RFID Iniciado");
  Serial.println("Aproxime o cartão/tag RFID...");
}

void loop() {
  // Verifica se há um novo cartão presente
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Lê o UID do cartão
  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i] < 0x10 ? "0" : ""); // Formata o byte
    uid += String(rfid.uid.uidByte[i], HEX); // Converte para HEX
  }
  uid.toUpperCase(); // Converte o UID para maiúsculo

  // Mostra o UID no Serial Monitor
  Serial.print("UID lido: ");
  Serial.println(uid);

  // Verifica se o UID é autorizado
  if (uid == "D84B1222") { // Substitua pelo UID do seu cartão autorizado
    Serial.println("Acesso liberado!");
    digitalWrite(led_verde, HIGH);
    delay(3000); // LED verde aceso por 3 segundos
    digitalWrite(led_verde, LOW);
  } else {
    Serial.println("Acesso negado!");
    digitalWrite(led_vermelho, HIGH);
    delay(3000); // LED vermelho aceso por 3 segundos
    digitalWrite(led_vermelho, LOW);
  }

  // Para a leitura repetida do cartão
  rfid.PICC_HaltA();
}
