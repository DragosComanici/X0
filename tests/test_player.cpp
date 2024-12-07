#include <gtest/gtest.h>
#include "Player.hpp"

TEST(PlayerTest, CreatePlayer) {
    Player player('X');
    EXPECT_EQ(player.getMarker(), 'X');
    EXPECT_EQ(player.getPlayerNumber(), 1);
}

TEST(PlayerTest, SetMarker) {
    Player player('X');
    player.setMarker('O');
    EXPECT_EQ(player.getMarker(), 'O');
}
