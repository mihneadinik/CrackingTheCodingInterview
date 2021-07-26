#include <iostream>
#include <forward_list>

void kth(std::forward_list <int> & list, int k) {
    std::forward_list <int> :: iterator p1, p2;
    p1 = list.begin();
    p2 = list.begin();

    for (int i = 0; i < k; i++) {
        if (p2 == list.end())
            return;
        else
            p2++;
    }

    while(p2 != list.end()) {
        p2++;
        p1++;
    }
    std::cout << *p1;
}

int main() {
    
    int nr, x, k;
    std::forward_list <int> list;
    std::cin >> k >> nr;
    for (int i = 0; i < nr; i++) {
        std::cin >> x;
        list.push_front(x);
    }
    kth(list, k);
    
    return 0;
}