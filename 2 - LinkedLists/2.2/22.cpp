#include <iostream>
#include "/home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h"

Node<int> *kth(LinkedList <int> & list, int k) {
    Node<int> *p1, *p2;
    p1 = list.getHead();
    p2 = list.getHead();

    for (int i = 0; i < k; i++) {
        if (p2 == nullptr)
            return nullptr;
        else
            p2 = p2->next;
    }

    while(p2 != nullptr) {
        p2 = p2->next;
        p1 = p1->next;
    }
    return p1;
}

int main() {
    
    int nr, x, k;
    LinkedList <int> list;
    std::cin >> k >> nr;
    for (int i = 0; i < nr; i++) {
        std::cin >> x;
        list.addNode(i, x);
    }
    Node <int> *nod = kth(list, k);
    if (nod != nullptr)
        std::cout << nod->data << std::endl;
    
    return 0;
}