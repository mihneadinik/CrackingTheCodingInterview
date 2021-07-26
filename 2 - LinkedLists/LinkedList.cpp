#include <iostream>
#include "LinkedList.h"

int main() {
    
    LinkedList<int> list;
    list.addNode(0, 1);
    list.addNode(1, 2);
    list.addNode(2, 3);
    list.addNode(3, 4);
    list.remNode(1);

    // Node<int> *curr = list.getHead();
    // while (curr != nullptr) {
    //     std::cout << curr->data << " ";
    //     curr = curr->next;
    // }
    std::cout<<list;

    return 0;
}