#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <array>

class Board {
public:
    Board();
    Board(const std::array<std::array<char, 3>, 3>& initialGrid);
    Board(const Board &other);
    Board& operator=(const Board &other);
    bool operator==(const Board &other) const;
    friend std::ostream& operator<<(std::ostream &out, const Board &board);
    friend std::istream& operator>>(std::istream &in, Board &board);

    void draw() const;
    bool placeMarker(int slot, char marker);
    int checkWinner() const;
    bool isFull() const;

private:
    std::array<std::array<char, 3>, 3> grid;
};

#endif
