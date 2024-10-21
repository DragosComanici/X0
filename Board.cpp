#include "Board.hpp"
#include <iostream>

Board::Board() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = ' ';
        }
    }
}

Board::Board(char initialGrid[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = initialGrid[i][j];
        }
    }
}

Board::Board(const Board &other) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = other.grid[i][j];
        }
    }
}

Board& Board::operator=(const Board &other) {
    if (this != &other) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                grid[i][j] = other.grid[i][j];
            }
        }
    }
    return *this;
}

bool Board::operator==(const Board &other) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] != other.grid[i][j]) {
                return false;
            }
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream &out, const Board &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            out << board.grid[i][j];
            if (j < 2) out << " | ";
        }
        out << std::endl;
        if (i < 2) out << "---------" << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream &in, Board &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            in >> board.grid[i][j];
        }
    }
    return in;
}

void Board::draw() const {
    std::cout << *this;
}

bool Board::placeMarker(int slot, char marker) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (grid[row][col] == ' ') {
        grid[row][col] = marker;
        return true;
    }
    return false;
}

int Board::checkWinner() const {
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ') {
            return grid[i][0] == 'X' ? 1 : 2;
        }
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ') {
            return grid[0][i] == 'X' ? 1 : 2;
        }
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') {
        return grid[0][0] == 'X' ? 1 : 2;
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') {
        return grid[0][2] == 'X' ? 1 : 2;
    }
    return 0;
}

bool Board::isFull() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
