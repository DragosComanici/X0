/**
 * @file game.hpp
 * @brief Gestionarea logicii pentru jocul X și 0.
 * @author [Numele Autorului]
 * @date 2024
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Player.hpp"

/**
 * @class Game
 * @brief Reprezintă jocul X și 0.
 *
 * Clasa coordonează logica principală a jocului, incluzând gestionarea turelor, 
 * schimbarea jucătorilor și afișarea scorurilor.
 */
class Game {
public:
    /**
     * @brief Creează un nou joc cu setările implicite.
     */
    Game();

    /**
     * @brief Pornește jocul și gestionează fluxul principal al acestuia.
     */
    void start();

private:
    Board board;           ///< Tabla de joc.
    Player player1;        ///< Primul jucător.
    Player player2;        ///< Al doilea jucător.
    int currentPlayer;     ///< Jucătorul curent (1 sau 2).
    int player1Wins;       ///< Numărul de victorii ale jucătorului 1.
    int player2Wins;       ///< Numărul de victorii ale jucătorului 2.

    /**
     * @brief Gestionează o tură individuală a jocului.
     */
    void playTurn();

    /**
     * @brief Schimbă jucătorul curent.
     */
    void switchCurrentPlayer();

    /**
     * @brief Afișează scorurile curente ale jocului.
     */
    void displayScore() const;
};

#endif
