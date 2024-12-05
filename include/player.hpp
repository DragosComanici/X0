/**
 * @file player.hpp
 * @brief Reprezintă un jucător în jocul X și 0.
 * @author 
 * @date 2024
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

/**
 * @class Player
 * @brief Reprezintă un jucător și gestionează simbolul acestuia (marker-ul).
 *
 * Clasa permite definirea unui jucător cu un marker specific, asocierea unui număr de jucător și oferă metode pentru accesarea și modificarea acestor informații.
 */
class Player {
public:
    /**
     * @brief Creează un jucător cu un marker specific.
     * @param marker Simbolul utilizat de jucător (ex. 'X' sau 'O').
     */
    Player(char marker);

    /**
     * @brief Obține marker-ul jucătorului.
     * @return Marker-ul jucătorului.
     */
    char getMarker() const;

    /**
     * @brief Setează un marker nou pentru jucător.
     * @param marker Marker-ul nou.
     */
    void setMarker(char marker);

    /**
     * @brief Obține numărul unic al jucătorului.
     * @return Numărul jucătorului.
     */
    int getPlayerNumber() const;

private:
    char marker; ///< Marker-ul jucătorului (simbolul utilizat în joc).
    int playerNumber; ///< Numărul unic asociat jucătorului.
};

#endif
