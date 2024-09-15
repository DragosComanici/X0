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

    void playTurn();
    void switchCurrentPlayer();
};