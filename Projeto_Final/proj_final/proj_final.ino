#include <SPI.h>
#include <MFRC522.h>

// Definições dos pinos
#define SS_PIN 10    // Pino para SDA/SS do módulo RC522
#define RST_PIN 9    // Pino para RST do módulo RC522
#define BUZZER_PIN 8 // Pino para o buzzer

// Inicializa o módulo RFID
MFRC522 rfid(SS_PIN, RST_PIN);

// LEDs para indicar acesso
const int led_verde = 5;   // LED verde para acesso liberado
const int led_vermelho = 6; // LED vermelho para acesso negado

// Lista de UIDs autorizados (coloque os UIDs dos cartões permitidos)
String uidsAutorizados[] = {"D84B1222", "A1B2C3D4", "E5F6G7H8"}; // Exemplos de UIDs autorizados

void setup() {
  // Configuração dos LEDs e buzzer
  pinMode(led_verde, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

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

  // Verifica se o UID lido está na lista de UIDs autorizados
  bool acessoLiberado = false;
  for (int i = 0; i < sizeof(uidsAutorizados) / sizeof(uidsAutorizados[0]); i++) {
    if (uid == uidsAutorizados[i]) {
      acessoLiberado = true;
      break;
    }
  }

  if (acessoLiberado) {
    Serial.println("Acesso liberado!");
    digitalWrite(led_verde, HIGH);
    tone(BUZZER_PIN, 1000, 200); // Apito curto de 200 ms
    delay(3000); // LED verde aceso por 3 segundos
    digitalWrite(led_verde, LOW);
  } else {
    Serial.println("Acesso negado!");
    digitalWrite(led_vermelho, HIGH);
    tone(BUZZER_PIN, 500, 1000); // Apito longo de 1000 ms
    delay(3000); // LED vermelho aceso por 3 segundos
    digitalWrite(led_vermelho, LOW);
  }

  // Para a leitura repetida do cartão
  rfid.PICC_HaltA();
}
