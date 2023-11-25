#include <iostream>

bool canFormPalindrome(const std::string& str) {
    int charCount[256] = {0};
    for (char ch : str) {
        if (isalnum(ch)) {
            charCount[static_cast<unsigned char>(ch)]++;
        }
    }

    int oddCount = 0;


    for (int count : charCount) {
        if (count % 2 != 0) {
            oddCount++;
        }
    }


    return oddCount <= 1;
}

int permutationsPalindromeNeeded(const std::string& str) {
    if (!canFormPalindrome(str)) {
        return 0; // Impossible to form a palindrome
    }

    int charCount[256] = {0};


    for (char ch : str) {
        if (isalnum(ch)) {
            charCount[static_cast<unsigned char>(ch)]++;
        }
    }


    int totalPermutations = 0;
    for (int count : charCount) {
        totalPermutations += count / 2;
    }

    return totalPermutations;
}

int main() {
    std::string inputStr ;
    getline(std::cin,inputStr);
    int permutationsNeeded = permutationsPalindromeNeeded(inputStr);

    if (permutationsNeeded == 0) {
        std::cout << -1  << std::endl;
    } else {
        std::cout << permutationsNeeded  << std::endl;
    }

    return 0;
}
