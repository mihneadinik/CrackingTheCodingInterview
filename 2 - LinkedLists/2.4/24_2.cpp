#include <iostream>
#include "/home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h"

Node<int> *rep(Node<int> *node, int k) {
    Node<int> *head, *tail;
    head = node;
    tail = node;
    while (node != nullptr) {
        Node<int> *next = node->next;
        if (node->data >= k) {
            tail->next = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
        node = next;
    }
    tail->next = nullptr;
    return head;
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