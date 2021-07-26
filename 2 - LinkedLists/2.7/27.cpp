#include <iostream>
#include <cmath>
#include "/home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h"

int main() {
    
    LinkedList<int> l1, l2;
    int n1, n2, x;
    std::cin >> n1;
    for (int i = 0; i < n1; i++) {
        std::cin >> x;
        l1.addNode(i, x);
    }
    std::cin >> n2;
    for (int i = 0; i < n2; i++) {
        std::cin >> x;
        l2.addNode(i, x);
    }
    int sz1 = 1, sz2 = 1;
    Node<int> *it1, *it2;
    it1 = l1.getHead();
    it2 = l2.getHead();
    while(it1->next != nullptr) {
        sz1++;
        it1 = it1->next;
    }
    while(it2->next != nullptr) {
        sz2++;
        it2 = it2->next;
    }
    if (it1 != it2) {
        std::cout << "Diferite\n";
        return 0;
    }
    it1 = l1.getHead();
    it2 = l2.getHead();
    int dif = abs(sz1 - sz2);
    if (sz1 > sz2) {
        for (int i = 0; i < dif; i++)
            it1 = it1->next;
    } else {
        for (int i = 0; i < dif; i++)
            it2 = it2->next;
    }
    while (it1 != nullptr) {
        if (it1 == it2) {
            std::cout << "Intersectie la nodul " << it1->data << std::endl;
            return 0;
        }
        it1 = it1->next;
        it2 = it2->next;
    }
    std::cout << "Diferite\n";
    return 0;
}