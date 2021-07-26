#include <iostream>
#include <map>
#include <string>

bool check_pal(std::string str) {
    std::string alp = "abcdefghijklmnopqrstuvwxyz";
    std::multimap<char, int> map;
    int len = 0;

    // mapez toate caracterele din sir si le fac litere mici daca sunt mari si le ignor daca nu sunt litere
    for (char ch : str) {
        if (isupper(ch)) {
            ch = tolower(ch);
            if (alp.find(ch) != -1) {
                map.insert(std::make_pair(ch, ch));
                len++;
            }
        } else {
            if (ch >= 'a' && ch <= 'z') {
                map.insert(std::make_pair(ch, ch));
                len++;
            }
        }
    }

    // pt fiecare litera din alfabet vad nr de aparitii si permitem un singur impar
    int imp = 0;
    for(char ch : alp) {
        int nr = map.count(ch);
        if (nr % 2 != 0)
            imp++;

        if (imp > 1)
            return false;
    }
    if (len % 2 == 0 && imp == 1)
        return false;
    return true;
}

int main() {

    std::string str;

    std::getline(std::cin, str);
    if (check_pal(str))
        std::cout << "Da\n";
    else
        std::cout << "Nu\n";

    return 0;
}