ESP32 - Um Botão, Dois LEDs

C

📌 Objetivo

Controlar dois LEDs utilizando um botão. A cada toque no botão, o LED aceso é alternado entre azul e amarelo.

Ao iniciar o sistema:

LED amarelo: aceso
LED azul: apagado

A cada novo toque, os LEDs trocam de estado. O estado permanece até que o botão seja pressionado novamente.

🔧 Componentes
ESP32 DevKit V1
1 botão momentâneo
1 LED azul
1 LED amarelo
2 resistores de 330 Ω
Protoboard
Jumpers
🔌 Ligações
Componente	GPIO
Botão	GPIO 23
LED azul	GPIO 18
LED amarelo	GPIO 19

O botão é conectado ao GPIO 23 e ao GND.

Cada LED utiliza um resistor de 330 Ω e possui seu cátodo conectado ao GND.

💻 Funcionamento

O botão utiliza o INPUT_PULLUP interno do ESP32. Dessa forma:

Botão solto → HIGH
Botão pressionado → LOW

O programa identifica um novo pressionamento e alterna o estado dos LEDs.

Também é utilizado um debounce de 50 ms para evitar que um único toque seja interpretado como vários pressionamentos.

🛠️ Tecnologias
C++
Arduino IDE
ESP32 DevKit V1
Entrada digital
INPUT_PULLUP
Debounce
🎯 Resultado esperado

O LED amarelo começa aceso. Ao pressionar o botão, o LED azul acende e o amarelo apaga. No próximo toque, o amarelo volta a acender e o azul apaga.
O sistema continua alternando os LEDs a cada novo toque.
