#include <iostream>
#include <string>
#include <vector>

bool check (std::string str1, std::string str2) {
    if (str1.length() != str2.length())
        return false;
    
    std::vector<int> char1(128);

    for (char c : str1) {
        char1[c]++; 
    }

    for (char c : str2) {
        char1[c]--;
        if (char1[c] < 0)
            return false;
    }
    return true;
}

int main() {

    std::string str1, str2;

    std::cin >> str1 >> str2;

    if (check(str1, str2))
        std::cout << "Da\n";
    else
        std::cout << "Nu\n";

    return 0;
}