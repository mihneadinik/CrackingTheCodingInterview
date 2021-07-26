#include <iostream>
#include <stack>
#include "/home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h"

bool rev(LinkedList<int> &ls) {
    Node<int> *first = ls.getHead();
    Node<int> *second = ls.getHead();

    std::stack<int> st;
    // mergem cu un pointer din 1 in 1 si cu altul din 2 in 2 pana se termina elementele
    while (second != nullptr && second->next != nullptr) {
        st.push(first->data);

        first = first->next;
        second = second->next->next;
    }
    // daca avem nr impar de elemente
    if (second != nullptr)
        first = first->next;
    // verificam daca elementele din prima jum sunt aceleasi cu elementele din a 2a jum
    while (first != nullptr) {
        if (first->data != st.top())
            return false;
        st.pop();
        first = first->next;
    }
    return true;
}

int main() {
    
    int x, nr;
    LinkedList<int> ls;
    std::cin >> nr;
    for (int i = 0; i < nr; i++) {
        std::cin >> x;
        ls.addNode(i, x);
    }

    if (rev(ls))
        std::cout<<"da\n";
    else
        std::cout<<"nu\n";
    
    return 0;
}