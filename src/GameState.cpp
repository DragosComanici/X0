#include "GameState.hpp"
#include <fstream>
#include <iostream>

GameState::GameState() {
    gameData["player1_score"] = 0;
    gameData["player2_score"] = 0;
}

void GameState::load() {
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        inputFile >> gameData;
    } else {
        std::cout << "No existing game data found. Starting fresh." << std::endl;
    }
}

void GameState::save() const {
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        outputFile << gameData.dump(4);
    }
}

void GameState::incrementScore(int player) {
    if (player == 1) {
        gameData["player1_score"] = gameData["player1_score"].get<int>() + 1;
    } else if (player == 2) {
        gameData["player2_score"] = gameData["player2_score"].get<int>() + 1;
    }
}

int GameState::getScore(int player) const {
    if (player == 1) {
        return gameData["player1_score"].get<int>();
    } else if (player == 2) {
        return gameData["player2_score"].get<int>();
    }
    return 0;
}
