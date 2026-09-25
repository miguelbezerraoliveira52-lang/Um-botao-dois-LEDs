const int BOTAO = 23;
const int LED_AZUL = 18;
const int LED_AMARELO = 19;

bool estadoLed = false;

int leituraAtual = HIGH;
int leituraAnterior = HIGH;

unsigned long ultimoDebounce = 0;
const unsigned long tempoDebounce = 50;

void setup() {
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);

  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_AMARELO, HIGH);
}

void loop() {
  int leitura = digitalRead(BOTAO);

  if (leitura != leituraAnterior) {
    ultimoDebounce = millis();
  }

  if ((millis() - ultimoDebounce) > tempoDebounce) {

    if (leitura != leituraAtual) {
      leituraAtual = leitura;

      if (leituraAtual == LOW) {
        estadoLed = !estadoLed;

        if (estadoLed) {
          digitalWrite(LED_AZUL, HIGH);
          digitalWrite(LED_AMARELO, LOW);
        } else {
          digitalWrite(LED_AZUL, LOW);
          digitalWrite(LED_AMARELO, HIGH);
        }
      }
    }
  }

  leituraAnterior = leitura;
}