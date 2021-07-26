#include <iostream>
#include </home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h>

int main() {
    
    int nr, x;
    LinkedList <int> list;
    std::cin >> nr;
    for (int i = 0; i < nr; i++) {
        std::cin >> x;
        list.addNode(i, x);
    }
    Node<int> *first = list.getHead();
    int poz = 0;
    while (first != list.getTail()) {
        Node<int> *second = first->next;
        int poz_del = poz + 1;
        while (second != nullptr) {
            if (first->data == second->data) {
                Node<int> *third = second->next;
                list.remNode(poz_del);
                second = third;
            } else {
                second = second->next;
                poz_del++;
            }
        }

        first = first->next;
        poz++;
    }
    std::cout << list;
    
    return 0;
}