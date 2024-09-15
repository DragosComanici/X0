class Player {
public:
    Player(char marker);
    char getMarker() const;
    void setMarker(char marker);
    int getPlayerNumber() const;
    void switchPlayer();

private:
    char marker;
    int playerNumber;
};