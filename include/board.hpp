#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <array>

class Board {
public:
    // Constructor implicit
    Board();

    // Constructor cu parametri
    Board(const std::array<std::array<char, 3>, 3>& initialGrid);

    // Constructor de copiere
    Board(const Board &other);

    // Operator de copiere
    Board& operator=(const Board &other);

    // Operator de comparație
    bool operator==(const Board &other) const;

    // Operator de afișare
    friend std::ostream& operator<<(std::ostream &out, const Board &board);

    // Operator de citire
    friend std::istream& operator>>(std::istream &in, Board &board);

    void draw() const;
    bool placeMarker(int slot, char marker);
    int checkWinner() const;
    bool isFull() const;

private:
    std::array<std::array<char, 3>, 3> grid;
};

#endif