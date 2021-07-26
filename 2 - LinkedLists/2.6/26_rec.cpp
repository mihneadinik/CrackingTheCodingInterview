#include <iostream>
#include "/home/mihnea_dnk/Desktop/cracking/2 - LinkedLists/LinkedList.h"

Node<int> *rev(Node<int> *node, int length) {
    if (length == 0)
        return node;
    // daca avem nr impar de elem, nu l returnam pe cel din mijloc
    if (length == 1)
        return node->next;
    // apelurile recursive pe urcare, iar pe revenire curr va reprezenta elem din a 2a jum
    Node<int> *curr = rev(node->next, length - 2);
    // daca am primit null din apel anterior, returnez tot null
    if (curr == nullptr)
        return nullptr;
    // verific daca elem din prima jumate este acelasi cu corespondentul sau
    if (curr->data != node->data)
        return nullptr;
    // daca am ajuns pe ultimul element si totul este ok, returnam curr ca sa fie diferit de null, altfel returnam nextul
    if (curr->next != nullptr)
        return curr->next;
    else
        return curr;
}

int main() {
    
    int x, nr;
    LinkedList<int> ls;
    std::cin >> nr;
    for (int i = 0; i < nr; i++) {
        std::cin >> x;
        ls.addNode(i, x);
    }
    Node<int> *nod = rev(ls.getHead(), ls.size());
    if (nod != nullptr)
        std::cout<<"da\n";
    else
        std::cout<<"nu\n";
    
    
    return 0;
}