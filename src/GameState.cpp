#include "GameState.hpp"
#include <fstream>
#include <iostream>

/**
 * @brief Constructor implicit care inițializează datele jocului.
 */
GameState::GameState() {
    gameData["player1_score"] = 0;
    gameData["player2_score"] = 0;
}

/**
 * @brief Încarcă datele jocului dintr-un fișier JSON.
 * 
 * Dacă fișierul nu există, inițializează datele implicite.
 */
void GameState::load() {
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        inputFile >> gameData;
    } else {
        std::cout << "Nu există date de joc salvate. Începem un joc nou." << std::endl;
    }
}

/**
 * @brief Salvează datele curente ale jocului într-un fișier JSON.
 */
void GameState::save() const {
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        outputFile << gameData.dump(4); // Format JSON cu indentare.
    }
}

/**
 * @brief Incrementează scorul unui jucător specificat.
 * 
 * @param player Jucătorul căruia i se va crește scorul (1 sau 2).
 */
void GameState::incrementScore(int player) {
    if (player == 1) {
        gameData["player1_score"] = gameData["player1_score"].get<int>() + 1;
    } else if (player == 2) {
        gameData["player2_score"] = gameData["player2_score"].get<int>() + 1;
    }
}

/**
 * @brief Returnează scorul unui jucător specificat.
 * 
 * @param player Jucătorul pentru care se returnează scorul (1 sau 2).
 * @return Scorul jucătorului.
 */
int GameState::getScore(int player) const {
    if (player == 1) {
        return gameData["player1_score"].get<int>();
    } else if (player == 2) {
        return gameData["player2_score"].get<int>();
    }
    return 0;
}
