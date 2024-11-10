#include "Game.hpp"
#include <iostream>

// Constructor
Game::Game() 
    : board(),
      player1('X'),
      player2('O'),
      currentPlayer(1) {}

void Game::start() {
    while (!board.isFull() && board.checkWinner() == 0) {
        playTurn();
        switchCurrentPlayer();
    }

    int winner = board.checkWinner();
    if (winner == 0) {
        std::cout << "It's a draw!" << std::endl;
    } else {
        std::cout << "Player " << winner << " wins!" << std::endl;
    }
}

void Game::playTurn() {
    board.draw();
    std::cout << "Player " << currentPlayer << "'s turn. Enter a slot (1-9): ";

    int slot;
    bool validMove = false;

    while (!validMove) {
        std::cin >> slot;

        if (currentPlayer == 1) {
            if (board.placeMarker(slot, player1.getMarker())) {
                validMove = true;
            } else {
                std::cout << "Invalid move! Try again." << std::endl;
            }
        } else {
            if (board.placeMarker(slot, player2.getMarker())) {
                validMove = true;
            } else {
                std::cout << "Invalid move! Try again." << std::endl;
            }
        }
    }
}

void Game::switchCurrentPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}