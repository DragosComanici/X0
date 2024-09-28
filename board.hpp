#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
public:
    Board();
    void draw() const;
    bool placeMarker(int slot, char marker);
    int checkWinner() const;
    bool isFull() const;

private:
    char grid[3][3];
};
#endif