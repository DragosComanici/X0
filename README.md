# Joc X și 0

board.hpp

Definește structura tabloului de joc, incluzând:

    Metode pentru desenarea tablei
    Plasarea simbolurilor
    Verificarea câștigătorului
    Adaugă suport pentru constructori și operatori pentru gestionarea stării tabloului.

board.cpp

Conține implementarea metodelor definite în board.hpp, gestionând logica pentru interacțiunea cu tabla de joc.
game.hpp

Coordonează logica jocului, incluzând metode pentru:

    Gestionarea rândurilor jucătorilor
    Alternarea între jucători

game.cpp

Implementarea metodelor din game.hpp, controlând fluxul jocului și interacțiunea cu jucătorii și tabla de joc.
player.hpp

Definește structura unui jucător, incluzând:

    Simbolul (marker-ul) acestuia
    Metode pentru accesarea și modificarea simbolului
    Numărul jucătorului este atribuit automat pe baza simbolului.

player.cpp

Implementarea metodelor din player.hpp, gestionând informațiile fiecărui jucător. Oferă funcționalitate pentru:

    Crearea jucătorilor
    Obținerea simbolurilor lor

GameState.hpp și GameState.cpp

Adaugă o structură care gestionează stările jocului, incluzând metode pentru:

    Salvarea și restaurarea stării curente a jocului
    Manipularea datelor persistente pentru fluxul jocului.

main.cpp

Punctul de intrare al aplicației, unde:

    Se inițializează jocul
    Se creează obiectele principale (Board, Game, Player)
    Se controlează logica principală a interacțiunii utilizatorului.

tasks.json

Folosit în Visual Studio Code pentru gestionarea sarcinilor automate, inclusiv:

    Compilarea fișierelor .cpp
    Generarea executabilului principal.

c_cpp_properties.json

Conține configurațiile specifice pentru Visual Studio Code, inclusiv căile pentru fișierele de antet.



# Construcția Proiectului

Clonăm repositoriul:
```bash'
git clone https://github.com/DragosComanici/X0.git
cd X0

Rulați comanda Ctrl+Shift+B pentru a compila și construi proiectul.
Executabilul va fi generat în folderul bin/.

CLEANUP
rm -rf obj/*.o bin/main.exe