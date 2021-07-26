#include <iostream>
#include <string>

bool is_perm(std::string str1, std::string str2) {
    if (str1.length() != str2.length() || str1.length() == 0)
        return false;

    std::string ccat = str2.append(str2);

    if(str2.find(str1) != -1)
        return true;
    return false;
}

int main() {
    
    std::string str1, str2;
    std::cin >> str1 >> str2;
    
    if (is_perm(str1, str2))
        std::cout << "Da\n";
    else
        std::cout << "Nu\n";

    return 0;
}