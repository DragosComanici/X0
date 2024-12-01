#include <iostream>
#include <nlohmann/json.hpp>
#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "GameState.hpp"

int main() {
    GameState gameState;

    gameState.load();

    Game game;

    game.start();

    gameState.incrementScore(1);
    gameState.incrementScore(2);

    std::cout << "Player 1 Score: " << gameState.getScore(1) << std::endl;
    std::cout << "Player 2 Score: " << gameState.getScore(2) << std::endl;

    gameState.save();

    return 0;
}
