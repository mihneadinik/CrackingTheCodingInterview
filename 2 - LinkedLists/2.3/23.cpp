#include <iostream>
#include "/home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h"

void rem(Node<int> *nod) {
    nod->data = nod->next->data;
    Node<int> *ph = nod->next;
    nod->next = nod->next->next;
    delete ph;
}

int main() {
    
    int nr, x;
    LinkedList <int> list;
    std::cin >> nr;
    for (int i = 0; i < nr; i++) {
        std::cin >> x;
        list.addNode(i, x);
    }
    Node<int> *p1;
    p1 = list.getHead();

    for (int i = 0; i < 3; i++)
        p1 = p1->next;

    rem(p1);

    std::cout << list;
    
    return 0;
}