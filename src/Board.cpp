#include "Board.hpp"
#include <algorithm>

Board::Board() {
    for (auto& row : grid) {
        row.fill(' ');
    }
}

Board::Board(const std::array<std::array<char, 3>, 3>& initialGrid) : grid(initialGrid) {}

Board::Board(const Board &other) : grid(other.grid) {}

Board& Board::operator=(const Board &other) {
    if (this != &other) {
        grid = other.grid;
    }
    return *this;
}

bool Board::operator==(const Board &other) const {
    return grid == other.grid;
}

std::ostream& operator<<(std::ostream &out, const Board &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            out << board.grid[i][j];
            if (j < 2) out << " | ";
        }
        out << "\n";
        if (i < 2) out << "---------\n";
    }
    return out;
}

std::istream& operator>>(std::istream &in, Board &board) {
    for (auto& row : board.grid) {
        for (char& cell : row) {
            in >> cell;
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
        if (std::equal(grid[i].begin(), grid[i].end(), grid[i].begin()) && grid[i][0] != ' ') {
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
    return std::all_of(grid.begin(), grid.end(), [](const std::array<char, 3>& row) {
        return std::all_of(row.begin(), row.end(), [](char cell) { return cell != ' '; });
    });
}
