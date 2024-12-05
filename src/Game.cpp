#include "Game.hpp"
#include <iostream>

/**
 * @brief Constructor implicit care inițializează un joc nou cu valorile implicite.
 */
Game::Game() 
    : board(), 
      player1('X'), 
      player2('O'), 
      currentPlayer(1),
      player1Wins(0), 
      player2Wins(0) {}

/**
 * @brief Metoda principală care gestionează desfășurarea jocului.
 */
void Game::start() {
    while (true) {
        board = Board(); // Resetează tabla.
        while (!board.isFull() && board.checkWinner() == 0) {
            playTurn();
            switchCurrentPlayer();
        }

        int winner = board.checkWinner();
        if (winner == 0) {
            std::cout << "Egalitate!" << std::endl;
        } else {
            std::cout << "Jucătorul " << winner << " a câștigat!" << std::endl;
            if (winner == 1) {
                player1Wins++;
            } else {
                player2Wins++;
            }
        }

        displayScore();

        char playAgain;
        std::cout << "Joci din nou? (y/n): ";
        std::cin >> playAgain;
        if (playAgain != 'y') {
            break;
        }
    }
}

/**
 * @brief Gestionează o tură a jucătorului curent, incluzând validarea mutării.
 */
void Game::playTurn() {
    board.draw();
    std::cout << "Tura jucătorului " << currentPlayer << ". Introdu un slot (1-9): ";

    int slot;
    bool validMove = false;

    while (!validMove) {
        std::cin >> slot;
        if (currentPlayer == 1) {
            if (board.placeMarker(slot, player1.getMarker())) {
                validMove = true;
            } else {
                std::cout << "Mutare invalidă! Încearcă din nou." << std::endl;
            }
        } else {
            if (board.placeMarker(slot, player2.getMarker())) {
                validMove = true;
            } else {
                std::cout << "Mutare invalidă! Încearcă din nou." << std::endl;
            }
        }
    }
}

/**
 * @brief Schimbă jucătorul curent între Player 1 și Player 2.
 */
void Game::switchCurrentPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

/**
 * @brief Afișează scorul curent al jucătorilor.
 */
void Game::displayScore() const {
    std::cout << "Scor: Jucătorul 1 (X): " << player1Wins << " - Jucătorul 2 (O): " << player2Wins << std::endl;
}
