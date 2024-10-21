#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Player.hpp"

class Game {
public:
    // Constructor implicit
    Game();

    void start();

private:
    Board board;
    Player player1;
    Player player2;
    int currentPlayer;

    void playTurn();

    void switchCurrentPlayer();
};

#endif
