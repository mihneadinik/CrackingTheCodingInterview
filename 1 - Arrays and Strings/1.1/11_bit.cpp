#include <iostream>
#include <string>

bool isunique(std::string str) {
    // va avea 4 blocuri de 8 biti, toti fiind 0
    int checker = 0;

    for (int i = 0; i < str.length(); i++) {
        // val este 0 pt 'a', 1 pt 'b', 2 pt 'c' si tot asa
        int val = str.at(i) - 'a';
        // 1 << val inseamna 2^val, adica in scrierea pe biti 1 pe pozitia val si 0 in rest
        // verificam daca a mai aparut litera, deci daca pozitia corespunzatoare este deja 1
        if ((checker & (1 << val)) > 0)
            return false;
        // actualizam caracterele folosite punand 1 pe pozitia lor
        checker |= (1 << val);
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