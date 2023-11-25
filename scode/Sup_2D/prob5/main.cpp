#include <iostream>
#include <cmath>

bool isWhiteKingUnderAttack(const std::string &rookPos, const std::string &blackKingPos, const std::string &whiteKingPos) {
   
    int rookRow = rookPos[1] - '0';
    char rookCol = rookPos[0];

    int blackKingRow = blackKingPos[1] - '0';
    char blackKingCol = blackKingPos[0];

    int whiteKingRow = whiteKingPos[1] - '0';
    char whiteKingCol = whiteKingPos[0];

   if (rookRow == blackKingRow || rookCol == blackKingCol || std::abs(rookRow - blackKingRow) == std::abs(rookCol - blackKingCol)) {
    return true;
} else {
    return false;
}

}

int main() {
    std::string rookPosition, blackKingPosition, whiteKingPosition;
    std::cin >> rookPosition >> blackKingPosition >> whiteKingPosition;

    if (isWhiteKingUnderAttack(rookPosition, blackKingPosition, whiteKingPosition)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
