#include "Board.hpp"
#include <algorithm>

/**
 * @brief Constructor implicit care inițializează tabla de joc goală.
 */
Board::Board() {
    for (auto& row : grid) {
        row.fill(' ');
    }
}

/**
 * @brief Constructor care inițializează tabla cu un grid specific.
 * @param initialGrid Grid-ul de start pentru tabla de joc.
 */
Board::Board(const std::array<std::array<char, 3>, 3>& initialGrid) : grid(initialGrid) {}

/**
 * @brief Constructor de copiere.
 * @param other O altă tablă de joc pentru copiere.
 */
Board::Board(const Board &other) : grid(other.grid) {}

/**
 * @brief Operator de atribuire.
 * @param other O altă tablă de joc pentru atribuire.
 * @return Referința la obiectul curent.
 */
Board& Board::operator=(const Board &other) {
    if (this != &other) {
        grid = other.grid;
    }
    return *this;
}

/**
 * @brief Operator de egalitate pentru compararea a două table de joc.
 * @param other Altă tablă de joc pentru comparare.
 * @return `true` dacă tablele sunt egale, altfel `false`.
 */
bool Board::operator==(const Board &other) const {
    return grid == other.grid;
}

/**
 * @brief Suprascrie operatorul `<<` pentru a afișa tabla de joc.
 * @param out Fluxul de ieșire.
 * @param board Tabla de joc de afișat.
 * @return Fluxul de ieșire.
 */
std::ostream& operator<<(std::ostream &out, const Board &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            out << board.grid[i][j];
            if (j < 2) out << " | ";
        }
        out << "\n";
        if (i < 2) out << "---------\n";
    }
    return out;
}

/**
 * @brief Suprascrie operatorul `>>` pentru a citi tabla de joc.
 * @param in Fluxul de intrare.
 * @param board Tabla de joc de citit.
 * @return Fluxul de intrare.
 */
std::istream& operator>>(std::istream &in, Board &board) {
    for (auto& row : board.grid) {
        for (char& cell : row) {
            in >> cell;
        }
    }
    return in;
}

/**
 * @brief Desenează tabla de joc în consolă.
 */
void Board::draw() const {
    std::cout << *this;
}

/**
 * @brief Plasează un marker pe tablă într-un slot specificat.
 * @param slot Poziția (1-9) unde se plasează marker-ul.
 * @param marker Marker-ul de plasat (de exemplu, 'X' sau 'O').
 * @return `true` dacă marker-ul a fost plasat cu succes, altfel `false`.
 */
bool Board::placeMarker(int slot, char marker) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (grid[row][col] == ' ') {
        grid[row][col] = marker;
        return true;
    }
    return false;
}

/**
 * @brief Verifică dacă există un câștigător.
 * @return 1 dacă jucătorul cu 'X' a câștigat, 2 dacă jucătorul cu 'O' a câștigat, 0 altfel.
 */
int Board::checkWinner() const {
    for (int i = 0; i < 3; ++i) {
        if (std::equal(grid[i].begin(), grid[i].end(), grid[i].begin()) && grid[i][0] != ' ') {
            return grid[i][0] == 'X' ? 1 : 2;
        }
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ') {
            return grid[0][i] == 'X' ? 1 : 2;
        }
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') {
        return grid[0][0] == 'X' ? 1 : 2;
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') {
        return grid[0][2] == 'X' ? 1 : 2;
    }
    return 0;
}

/**
 * @brief Verifică dacă tabla este completă (fără spații libere).
 * @return `true` dacă tabla este plină, altfel `false`.
 */
bool Board::isFull() const {
    return std::all_of(grid.begin(), grid.end(), [](const std::array<char, 3>& row) {
        return std::all_of(row.begin(), row.end(), [](char cell) { return cell != ' '; });
    });
}
