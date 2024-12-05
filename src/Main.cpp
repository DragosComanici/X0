#include <iostream>
#include <nlohmann/json.hpp>
#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "GameState.hpp"

/**
 * @file main.cpp
 * @brief Punctul de intrare al aplicației pentru jocul X și O.
 * 
 * Acest fișier inițializează starea jocului, rulează jocul principal
 * și gestionează salvarea și încărcarea scorurilor jucătorilor.
 * 
 * @author [Numele tău]
 * @date [Anul curent]
 */

int main() {
    /**
     * @brief Creează și gestionează starea jocului.
     */
    GameState gameState;

    /**
     * @brief Încarcă datele jocului din fișierul salvării.
     */
    gameState.load();

    /**
     * @brief Creează și pornește un nou joc.
     */
    Game game;
    game.start();

    /**
     * @brief Incrementează scorurile pentru a testa funcționalitatea salvării.
     */
    gameState.incrementScore(1);
    gameState.incrementScore(2);

    /**
     * @brief Afișează scorurile curente ale jucătorilor.
     */
    std::cout << "Scor Jucător 1: " << gameState.getScore(1) << std::endl;
    std::cout << "Scor Jucător 2: " << gameState.getScore(2) << std::endl;

    /**
     * @brief Salvează starea jocului în fișier.
     */
    gameState.save();

    return 0;
}
