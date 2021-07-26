#include <iostream>
#include "/home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h"

Node<int> *add(LinkedList<int> &nr1, LinkedList<int> &nr2) {
    int rest = 0, sum = 0;
    Node<int> *c1, *c2;
    c1 = nr1.getHead();
    c2 = nr2.getHead();
    // cream rezultatul drept o insiruire de noduri
    Node<int> *curr = nullptr; // ultimul nod adaugat
    Node<int> *first = nullptr; // primul nod din lista
    // cat timp putem aduna cifra cu cifra
    while (c1 != nullptr && c2 != nullptr) {
        // facem suma
        sum = c1->data + c2->data;
        // vedem daca avem rest de adunat
        if (rest) {
            sum += 1;
            rest = 0;
        }
        // mergem la urmatoarele cifre
        c1 = c1->next;
        c2 = c2->next;
        // vedem daca retinem rest
        if (sum / 10 != 0) {
            sum %= 10;
            rest = 1;
        }
        // pun suma intr un nod
        Node<int> *d = new Node<int> (sum);
        // verific daca e primul nod din lista
        if (curr != nullptr) {
            curr->next = d;
            curr = d;
        } else {
            curr = d;
        }
        if (first == nullptr)
            first = d;
    }
    // acelasi algoritm pana termin cifrele numerelor
    while (c1 != nullptr) {
        sum = c1->data;
        if (rest) {
            sum += 1;
            rest = 0;
        }
        c1 = c1->next;
        if (sum / 10 != 0) {
            sum %= 10;
            rest = 1;
        }
        Node<int> *d = new Node<int> (sum);
        if (curr != nullptr) {
            curr->next = d;
            curr = d;
        } else {
            curr = d;
        }
        if (first == nullptr)
            first = d;
    }
    while (c2 != nullptr) {
        sum = c2->data;
        if (rest) {
            sum += 1;
            rest = 0;
        }
        c2 = c2->next;
        if (sum / 10 != 0) {
            sum %= 10;
            rest = 1;
        }
        Node<int> *d = new Node<int> (sum);
        if (curr != nullptr) {
            curr->next = d;
            curr = d;
        } else {
            curr = d;
        }
        if (first == nullptr)
            first = d;
    }
    if (rest) {
        Node<int> *d = new Node<int> (1);
        curr->next = d;
    }
    return first;
}

int main() {
    
    int nrr1, x, nrr2;
    LinkedList <int> nr1;
    LinkedList <int> nr2;
    // citim numerele (sunt scrise invers)
    std::cin >> nrr1 >> nrr2;
    for (int i = 0; i < nrr1; i++) {
        std::cin >> x;
        nr1.addNode(i, x);
    }
    for (int i = 0; i < nrr2; i++) {
        std::cin >> x;
        nr2.addNode(i, x);
    }
    Node<int> *p1, *p2;
    p1 = add(nr1, nr2);
    p2 = p1;
    // afisam rezultatul
    while(p1 != nullptr) {
        std::cout << p1->data << " ";
        p1 = p1->next;
    }
    std::cout << std::endl;
    // eliberam memoria
    if (p2 != nullptr)
        p1 = p2->next;
    else
        p1 = nullptr;

    while (p1 != nullptr) {
        delete p2;
        p2 = p1;
        p1 = p1->next;
    }
    delete p2;
    
    return 0;
}