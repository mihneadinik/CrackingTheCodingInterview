#include <iostream>
#include "/home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h"

Node<int> *kth(Node<int> *head, int k, int& i) {
    // daca am terminat nodurile
    if (head == nullptr)
        return nullptr;
    Node<int> *nd = kth(head->next, k, i);
    i++;
    // daca am gasit nodul cautat in urma apelurilor recursive
    if (i == k)
        return head;
    // incheiam apelul curent
    return nd;
}

int main() {

    int nr, x, k;
    LinkedList <int> list;
    std::cin >> k >> nr;
    for (int i = 0; i < nr; i++) {
        std::cin >> x;
        list.addNode(i, x);
    }
    int i = 0;
    Node<int> *nod = kth(list.getHead(), k, i);
    if (nod != nullptr)
        std::cout << nod->data << std::endl;
    else
        std::cout << "NULL" << std::endl;

    return 0;
}