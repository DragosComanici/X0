#include "Game.hpp"
#include <iostream>

Game::Game() : currentPlayer(1), player1('X'), player2('O') {}

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
    std::cin >> slot;

    if (currentPlayer == 1) {
        if (!board.placeMarker(slot, player1.getMarker())) {
            std::cout << "Invalid move! Try again." << std::endl;
            playTurn();
        }
    } else {
        if (!board.placeMarker(slot, player2.getMarker())) {
            std::cout << "Invalid move! Try again." << std::endl;
            playTurn();
        }
    }
}

void Game::switchCurrentPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}
