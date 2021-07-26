#include <iostream>
#include "/home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h"

void adder(Node<int> *c1, Node<int> *c2, int &carry, LinkedList<int> &nr) {
    // la finalul numarului oprim apelurile recursive si incepem sa adunam cifrele
    if (c1 == nullptr) {
        carry = 0;
        return;
    }
    // mergem pana la finalul numarului
    adder(c1->next, c2->next, carry, nr);
    // facem suma
    int sum = carry + c1->data + c2->data;
    // verificam daca depasim ordinul
    if (sum >= 10) {
        carry = 1;
        sum %= 10;
    } else {
        carry = 0;
    }
    // construim rezultatul de la sfarsit spre inceput
    nr.addNode(0, sum);
}

void add(LinkedList<int> &nr1, LinkedList<int> &nr2, LinkedList<int> &nr) {
    Node<int> *c1, *c2;
    // verificam daca trb sa punem 0 in fata
    int sz1 = nr1.size(), sz2 = nr2.size();
    if (sz1 != sz2) {
        if (sz1 < sz2) {
            for ( int i = 0; i < sz2 - sz1; i++)
                nr1.addNode(0, 0);
        } else {
            for ( int i = 0; i < sz1 - sz2; i++)
                nr2.addNode(0, 0);
        }
    }
    c1 = nr1.getHead();
    c2 = nr2.getHead();
    int carry = 0;
    adder(c1, c2, carry, nr);
    if (carry)
        nr.addNode(0, 1);
}

int main() {
    
    // citim numerele (scrise normal)
    int nrr1, x, nrr2;
    LinkedList <int> nr1;
    LinkedList <int> nr2;
    std::cin >> nrr1 >> nrr2;
    for (int i = 0; i < nrr1; i++) {
        std::cin >> x;
        nr1.addNode(i, x);
    }
    for (int i = 0; i < nrr2; i++) {
        std::cin >> x;
        nr2.addNode(i, x);
    }
    LinkedList <int> p1;
    add(nr1, nr2, p1);
    std::cout<<p1;
    
    return 0;
}