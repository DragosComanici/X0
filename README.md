# Joc X și 0

- **board.hpp**: Definește structura tabloului de joc, inclusiv metodele pentru desenarea tablei, plasarea simbolurilor și verificarea câștigătorului.

- **board.cpp**: Conține implementarea metodelor definite în `board.hpp`, gestionând logica pentru interacțiunea cu tabla de joc.

- **game.hpp**: Coordonează logica jocului, incluzând metodele pentru gestionarea rândurilor jucătorilor și alternarea între aceștia.

- **game.cpp**: Implementarea metodelor din `game.hpp`, controlând fluxul jocului și interacțiunea cu jucătorii și tabla de joc.

- **player.hpp**: Definește structura unui jucător, incluzând simbolul acestuia și metodele pentru gestionarea rândului și simbolului.

- **player.cpp**: Conține implementarea metodelor din `player.hpp`, gestionând informațiile specifice fiecărui jucător.

- **Makefile**: Conține instrucțiuni pentru compilarea proiectului. Acesta definește variabilele necesare, regulile pentru a genera executabilul și o regulă de curățare pentru a șterge executabilul generat.


# Construcția Proiectului

Clonăm repositoriul:
"```bash"
git clone https://github.com/DragosComanici/X0.git
cd X0

Pentru a compila proiectul folosim: "make"
Pentru a rula jocul: "./compileX0"