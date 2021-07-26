#include <iostream>
#include <string>

// verific daca merita sa creez un string nou
bool check(std::string str) {
    int countcons = 0, len = 0;
    for (int i = 0; i < str.length(); i++) {
        countcons++;

        // daca mi iese din sir sau nu mai am acelasi caracter, resetam
        if (i + 1 > str.length() || str[i] != str[i + 1]) {
            int k = 0;
            while (countcons != 0) {
                k++;
                countcons /= 10;
            }
            // actualizam lungimea
            len += 1 + k;
            countcons = 0;
        }
    }

    if (str.length() < len)
        return false;
    return true;
}

void compress(std::string str) {
    int countcons = 0;
    std::string new_str;

    for (int i = 0; i < str.length(); i++) {
        countcons++;

        if (i + 1 > str.length() || str[i] != str[i + 1]) {
            // actualizam sirul
            new_str += str[i];
            std::string nr = std::to_string(countcons);
            new_str += nr;
            countcons = 0;
        }
    }

    std::cout << new_str << std::endl;
}

int main() {

    std::string str;
    std::cin >> str;

    if (!check(str))
        std::cout << str << std::endl;
    else
        compress(str);

    return 0;
}