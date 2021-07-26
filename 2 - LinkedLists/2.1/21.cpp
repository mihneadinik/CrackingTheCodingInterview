#include <iostream>
#include <forward_list>

void print(std::forward_list <int> dups) {
    for (auto &i : dups) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void rem_dup(std::forward_list <int> & dups) {
    std::forward_list <int> :: iterator p1, p2;
    p1 = dups.begin();
    p2 = dups.begin();
    while (p1 != dups.end()) {
        p2 = p1;
        p2++;
        std::forward_list <int> :: iterator ph = p1;
        while (p2 != dups.end() && ph != dups.end()) {
            if (*p1 == *p2) {
                dups.erase_after(ph);
            }
            p2++;
            ph++;
        }
        p1++;
    }
}

int main() {

    std::forward_list <int> dups;
    dups.push_front(1);
    dups.push_front(2);
    dups.push_front(2);
    dups.push_front(1);
    dups.push_front(3);
    dups.push_front(4);
    dups.push_front(5);
    dups.push_front(4);
    dups.push_front(3);
    dups.push_front(6);
    dups.push_front(8);

    print(dups);
    rem_dup(dups);
    print(dups);

    return 0;
}