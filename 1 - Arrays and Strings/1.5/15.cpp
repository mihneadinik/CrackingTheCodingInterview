#include <iostream>
#include <string>
#include <cmath>

void check(std::string str_mic, std::string str_mare) {
    int dif = 0, i = 0, j = 0;
    while(j < str_mare.length() && dif < 2) {
        if (str_mic[i] != str_mare[j]) {
            dif++;
            if (str_mare.length() != str_mic.length())
                j++;
        }
        i++;
        j++;
    }
    if (dif < 2)
        std::cout << "Bun\n";
    else
        std::cout << "Rau\n";
}

int main() {

    std::string str1, str2;
    std::cin >> str1 >> str2;
    if (abs(str1.length() - str2.length()) > 1) {
        std::cout << "Rau\n";
        return 0;
    }
    
    if (str1.length() > str2.length())
        check (str2, str1);
    else
        check (str1, str2);

    return 0;
}

// pale
// ple
// pae