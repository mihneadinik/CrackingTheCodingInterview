#include <iostream>
#include "/home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h"

Node<int> *rev(Node<int> *node) {
    Node<int> *head = nullptr;
    while (node != nullptr) {
        Node<int> *nou = new Node<int>(node->data);
        nou->next = head;
        head = nou;
        node = node->next;
    }
    return head;
}

int main() {
    
    int x, nr;
    LinkedList<int> ls;
    std::cin >> nr;
    for (int i = 0; i < nr; i++) {
        std::cin >> x;
        ls.addNode(i, x);
    }
    Node<int> *head_r = rev(ls.getHead());
    Node<int> *head = ls.getHead();
    int ok = 1;
    while (head != nullptr && head_r != nullptr) {
        if (head->data != head_r->data) {
            ok = 0;
            break;
        }
        head = head->next;
        head_r = head_r->next;
    }
    if (ok)
        std::cout << "da\n";
    else
        std::cout << "nu\n";
    
    return 0;
}