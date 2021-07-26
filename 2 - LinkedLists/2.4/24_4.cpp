#include <iostream>
#include "/home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h"

Node<int> *rep(Node<int> *head, int k) {
    Node<int> *before_s, *before_e, *after_s, *after_e;
    before_s = nullptr;
    before_e = nullptr;
    after_e = nullptr;
    after_s = nullptr;

    while (head != nullptr) {
        Node<int> *next = head->next;
        head->next = nullptr;
        if (head->data < k) {
            //adaugam la inceput
            if (before_s == nullptr) {
                before_s = head;
                before_e = head;
            } else {
                before_e->next = head;
                before_e = head;
            }
        } else {
            //adaugam la sfarsit
            if (after_s == nullptr) {
                after_s = head;
                after_e = head;
            } else {
                after_e->next = head;
                after_e = head;
            }
        }
        head = next;
    }

    //daca nu am nimic in prima lista, poate am in a 2a
    if (before_s == nullptr)
        return after_s;

    //unim listele
    before_e->next = after_s;
    return before_s;
}

int main() {
    
    int nr, x, k;
    LinkedList <int> list;
    std::cin >> k >> nr;
    for (int i = 0; i < nr; i++) {
        std::cin >> x;
        list.addNode(i, x);
    }
    Node<int> *p1;
    p1 = rep(list.getHead(), k);

    while(p1 != nullptr) {
        std::cout << p1->data << " ";
        p1 = p1->next;
    }
    std::cout << std::endl;
    
    return 0;
}