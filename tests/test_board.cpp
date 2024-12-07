#include <gtest/gtest.h>
#include "Board.hpp"

TEST(BoardTest, InitializeBoard) {
    Board board;
    EXPECT_TRUE(board.isFull() == false);
}

TEST(BoardTest, PlaceMarkerValidMove) {
    Board board;
    EXPECT_TRUE(board.placeMarker(1, 'X'));
    EXPECT_EQ(board.checkWinner(), 0);
}

TEST(BoardTest, PlaceMarkerInvalidMove) {
    Board board;
    board.placeMarker(1, 'X');
    EXPECT_FALSE(board.placeMarker(1, 'O'));
}

TEST(BoardTest, CheckWinnerRow) {
    Board board;
    board.placeMarker(1, 'X');
    board.placeMarker(2, 'X');
    board.placeMarker(3, 'X');
    EXPECT_EQ(board.checkWinner(), 1);
}

TEST(BoardTest, CheckWinnerNoWinner) {
    Board board;
    board.placeMarker(1, 'X');
    board.placeMarker(2, 'O');
    EXPECT_EQ(board.checkWinner(), 0);
}

TEST(BoardTest, CheckWinnerColumn) {
    Board board;
    board.placeMarker(1, 'X');
    board.placeMarker(4, 'X');
    board.placeMarker(7, 'X');
    EXPECT_EQ(board.checkWinner(), 1);
}

TEST(BoardTest, CheckWinnerDiagonal) {
    Board board;
    board.placeMarker(1, 'X');
    board.placeMarker(5, 'X');
    board.placeMarker(9, 'X');
    EXPECT_EQ(board.checkWinner(), 1);
}

TEST(BoardTest, CheckFullBoard) {
    Board board;
    for (int i = 1; i <= 9; ++i) {
        board.placeMarker(i, (i % 2 == 0) ? 'O' : 'X');
    }
    EXPECT_TRUE(board.isFull());
}
