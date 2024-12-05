/**
 * @file board.hpp
 * @brief Structura tabelului de joc pentru X și 0.
 * @author [Numele Autorului]
 * @date 2024
 */

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <array>

/**
 * @class Board
 * @brief Reprezintă tabla de joc pentru jocul X și 0.
 *
 * Clasa oferă funcționalități pentru inițializarea tablei, plasarea simbolurilor, 
 * verificarea câștigătorului și alte operațiuni asociate jocului.
 */
class Board {
public:
    /**
     * @brief Creează o tablă de joc goală.
     */
    Board();

    /**
     * @brief Creează o tablă de joc cu o stare inițială specificată.
     * @param initialGrid O matrice 3x3 care reprezintă starea inițială a tablei.
     */
    Board(const std::array<std::array<char, 3>, 3>& initialGrid);

    /**
     * @brief Constructor de copiere.
     * @param other Obiectul Board din care se copiază datele.
     */
    Board(const Board &other);

    /**
     * @brief Operator de atribuire.
     * @param other Obiectul Board din care se copiază datele.
     * @return O referință la acest obiect Board.
     */
    Board& operator=(const Board &other);

    /**
     * @brief Compară două obiecte Board pentru egalitate.
     * @param other Obiectul Board cu care se face comparația.
     * @return True dacă tablele sunt identice, false altfel.
     */
    bool operator==(const Board &other) const;

    /**
     * @brief Afișează tabla de joc într-un flux de ieșire.
     * @param out Fluxul de ieșire.
     * @param board Obiectul Board de afișat.
     * @return Fluxul de ieșire modificat.
     */
    friend std::ostream& operator<<(std::ostream &out, const Board &board);

    /**
     * @brief Citește tabla de joc dintr-un flux de intrare.
     * @param in Fluxul de intrare.
     * @param board Obiectul Board de populat.
     * @return Fluxul de intrare modificat.
     */
    friend std::istream& operator>>(std::istream &in, Board &board);

    /**
     * @brief Desenează starea actuală a tablei în consolă.
     */
    void draw() const;

    /**
     * @brief Plasează un simbol pe tablă.
     * @param slot Poziția unde se plasează simbolul (1-9, de la stânga sus la dreapta jos).
     * @param marker Simbolul care urmează să fie plasat ('X' sau 'O').
     * @return True dacă simbolul a fost plasat cu succes, false altfel.
     */
    bool placeMarker(int slot, char marker);

    /**
     * @brief Verifică dacă există un câștigător pe tablă.
     * @return 1 dacă jucătorul 1 câștigă, 2 dacă jucătorul 2 câștigă, 0 altfel.
     */
    int checkWinner() const;

    /**
     * @brief Verifică dacă tabla este complet ocupată.
     * @return True dacă toate pozițiile sunt ocupate, false altfel.
     */
    bool isFull() const;

private:
    /**
     * @brief Matrice 3x3 care reprezintă starea tablei de joc.
     *
     * Fiecare element poate fi 'X', 'O' sau '\0' (gol).
     */
    std::array<std::array<char, 3>, 3> grid;
};

#endif
