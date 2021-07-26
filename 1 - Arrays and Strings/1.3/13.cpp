#include <iostream>
#include <string>

void space(std::string &str, int truelength) {
    int spaces = 0;
    // Numar spatiile
    for (int i = 0; i < truelength; i++)
        if(str[i] == ' ')
            spaces++;
    //calculez valoarea finala
    int length = truelength + spaces * 2;
    truelength--;
    //rescriu sirul de la coada spre cap, inlocuind spatiile
    for (int i = length - 1; i >= 0; i--) {
        if (str[truelength] == ' ') {
            str[i] = '0';
            str[--i] = '2';
            str[--i] = '%';
        } else {
            str[i] = str[truelength];
        }
        truelength--;
    }
    str[length] = '\0';
    std::cout << str << std::endl;
}

int main() {

    std::string str = "Mr John Smith    ";
    int truelength;

    std::cin >> truelength;

    space(str, truelength);
    std::cout << str << std::endl;
    return 0;
}