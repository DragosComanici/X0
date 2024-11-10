#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
public:
    Player(char marker);

    char getMarker() const;
    void setMarker(char marker);

    int getPlayerNumber() const;

private:
    char marker;
    int playerNumber;
};

#endif