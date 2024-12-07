#include <gtest/gtest.h>
#include "GameState.hpp"

TEST(GameStateTest, InitializeGameState) {
    GameState gameState;
    EXPECT_EQ(gameState.getScore(1), 0);
    EXPECT_EQ(gameState.getScore(2), 0);
}

TEST(GameStateTest, IncrementScore) {
    GameState gameState;
    gameState.incrementScore(1);
    EXPECT_EQ(gameState.getScore(1), 1);
    gameState.incrementScore(2);
    EXPECT_EQ(gameState.getScore(2), 1);
}

TEST(GameStateTest, SaveAndLoadGameState) {
    GameState gameState;
    gameState.incrementScore(1);
    gameState.save();
    
    GameState loadedGameState;
    loadedGameState.load();
    EXPECT_EQ(loadedGameState.getScore(1), 1);
    EXPECT_EQ(loadedGameState.getScore(2), 0);
}
