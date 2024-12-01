#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Player.hpp"

class Game {
public:
    Game();
    void start();

private:
    Board board;
    Player player1;
    Player player2;
    int currentPlayer;
    int player1Wins;
    int player2Wins;

    void playTurn();
    void switchCurrentPlayer();
    void displayScore() const;
};

#endif
