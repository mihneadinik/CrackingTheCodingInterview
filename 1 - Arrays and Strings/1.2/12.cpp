#include <iostream>
#include <string>

void str_sort(std::string & str) {
    // bubble sort ca sa ordonez caracterele unui string
    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = 0; j < str.length() - 1 - i; j++) {
            if (str.at(j) > str.at(j + 1)) {
                char tmp = str.at(j);
                str.at(j) = str.at(j + 1);
                str.at(j + 1) = tmp;
            }
        }
    }
}

bool check (std::string str1, std::string str2) {
    if (str1.length() != str2.length())
        return false;
    
    str_sort(str1);
    str_sort(str2);

    for (int i = 0; i < str1.length(); i++) {
        if (str1.at(i) != str2.at(i))
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