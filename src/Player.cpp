#include "Player.hpp"

/**
 * @file player.cpp
 * @brief Definițiile metodelor pentru clasa Player.
 * 
 * Acest fișier conține implementarea funcțiilor care permit gestionarea jucătorilor
 * și a marker-ului acestora în jocul X și O.
 * 
 * @author [Numele tău]
 * @date [Anul curent]
 */

/**
 * @brief Constructor pentru crearea unui jucător cu un marker specificat.
 * 
 * @param marker Caracterul care reprezintă marker-ul jucătorului ('X' sau 'O').
 */
Player::Player(char marker) : marker(marker), playerNumber(marker == 'X' ? 1 : 2) {}

/**
 * @brief Returnează marker-ul jucătorului.
 * 
 * @return Caracterul care reprezintă marker-ul jucătorului ('X' sau 'O').
 */
char Player::getMarker() const {
    return marker;
}

/**
 * @brief Setează marker-ul jucătorului.
 * 
 * @param marker Caracterul care reprezintă noul marker al jucătorului.
 */
void Player::setMarker(char marker) {
    this->marker = marker;
}

/**
 * @brief Returnează numărul jucătorului (1 pentru 'X', 2 pentru 'O').
 * 
 * @return numărul jucătorului.
 */
int Player::getPlayerNumber() const {
    return playerNumber;
}
