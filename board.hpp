#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

class Board {
public:
    // Constructor implicit
    Board();

    // Constructor cu parametri
    Board(char initialGrid[3][3]);

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
    char grid[3][3];
};

#endif
