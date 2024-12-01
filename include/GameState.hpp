#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <nlohmann/json.hpp>
#include <string>

class GameState {
public:
    GameState();
    void load();
    void save() const;
    void incrementScore(int player);
    int getScore(int player) const;

private:
    nlohmann::json gameData;
    const std::string fileName = "game_data.json";
};

#endif
