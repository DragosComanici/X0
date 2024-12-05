# Joc X și 0

Acest proiect implementează jocul clasic de X și 0 (Tic-Tac-Toe), un joc între doi jucători pe o tablă de 3x3, unde jucătorii își plasează alternativ simbolurile pe tablă pentru a câștiga.

## Descrierea Regulilor Jocului

- **Scopul jocului**: Obiectivul jocului este să plasezi 3 simboluri (X sau O) pe o linie orizontală, verticală sau diagonală.
- **Mod de joc**:
  1. Jucătorii își aleg simbolul (X sau O) și joacă pe rând.
  2. Jucătorul 1 folosește simbolul 'X', iar jucătorul 2 folosește simbolul 'O'.
  3. Fiecare jucător își plasează simbolul pe una dintre cele 9 poziții disponibile de pe tablă.
  4. Jocul se încheie atunci când unul dintre jucători câștigă sau când tabla este plină, rezultând într-o remiză.

## Dependențe

Pentru a construi și rula proiectul, sunt necesare următoarele:

- **Mediu de dezvoltare**: Visual Studio Code sau orice alt editor de cod preferat.
- **Compilator**: GCC (pentru Linux/Mac) sau MinGW (pentru Windows).
- **Biblioteci terțe**:
  - `nlohmann/json` pentru manipularea fișierelor JSON (folosită pentru salvarea și încărcarea stării jocului).

### Instalare bibliotecă `nlohmann/json`

Pentru a utiliza biblioteca `nlohmann/json`, o poți instala folosind gestionarul de pachete `vcpkg` sau prin includerea fișierului `json.hpp` în proiectul tău.

```bash'
git clone https://github.com/nlohmann/json.git
cd X0
Ctrl+Shift+B pentru a compila proiectul
Executabilul va fi generat în folderul bin/

Pentru a șterge fișierele temporare:
rm -rf obj/*.o bin/main.exe



Structura Proiectului
board.hpp

Definește structura tabloului de joc, incluzând:

    Metode pentru desenarea tablei
    Plasarea simbolurilor
    Verificarea câștigătorului
    Constructori și operatori pentru gestionarea stării tabloului.

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