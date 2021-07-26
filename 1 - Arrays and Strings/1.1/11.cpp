#include <iostream>
#include <string>

bool isunique(std::string str) {
    // daca avem mai multe caractere decat in alfabet, clar nu e unic
    if (str.length() > 128)
        return false;

    // vector de aparitii
    bool char_set[128] = {false};

    // verificam caracter cu caracter daca e unic
    for (char i : str) {
        int val = i;
        if (char_set[val])
            return false;
        char_set[val] = true;
    }

    return true;
}

int main() {
    std::string str;

    std::cin >> str;
    if (isunique(str))
        std::cout << "Unic\n";
    else
        std::cout << "Nu e\n";

    return 0;
}