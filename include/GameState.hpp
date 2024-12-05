/**
 * @file gamestate.hpp
 * @brief Gestionarea stării și a scorurilor jocului X și 0.
 * @author 
 * @date 2024
 */

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <nlohmann/json.hpp>
#include <string>

/**
 * @class GameState
 * @brief Reprezintă starea jocului, incluzând scorurile și persistarea datelor.
 *
 * Clasa permite încărcarea și salvarea datelor de joc, precum și gestionarea scorurilor jucătorilor.
 */
class GameState {
public:
    /**
     * @brief Creează o nouă stare de joc.
     */
    GameState();

    /**
     * @brief Încarcă datele de joc dintr-un fișier JSON.
     */
    void load();

    /**
     * @brief Salvează datele de joc într-un fișier JSON.
     */
    void save() const;

    /**
     * @brief Incrementează scorul unui jucător specificat.
     * @param player Numărul jucătorului (1 sau 2).
     */
    void incrementScore(int player);

    /**
     * @brief Obține scorul unui jucător specificat.
     * @param player Numărul jucătorului (1 sau 2).
     * @return Scorul jucătorului.
     */
    int getScore(int player) const;

private:
    nlohmann::json gameData; ///< Obiect JSON care stochează datele jocului.
    const std::string fileName = "game_data.json"; ///< Numele fișierului pentru salvare.
};

#endif
