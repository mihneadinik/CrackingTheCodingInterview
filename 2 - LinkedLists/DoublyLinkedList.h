/**
 * LabSD 3
 * DoublyLinkedList.h
 * Purpose: Skeleton code for the doubly linked list.
 *
 * @author Gabriel Bercaru
 */

#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

#include <assert.h>

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int numElements;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        numElements = 0;
    }

    // Another constructor
    DoublyLinkedList(Node<T> *head) {
        this->head = head;
        while (head != nullptr) {
            numElements++;
            head = head->next;
        }
    }

    // Destructor
    ~DoublyLinkedList() {
        // TODO: delete previously allocated stuff (if any)
    }

    /**
     * Adds a new node at the end of the list.
     *
     * @param data Data to be added at the end of the list.
     */
    void addLast(T data) {
        // TODO: TASK 1
    }

    /**
     * Adds a new node at the beginning of the list.
     *
     * @param data Data to be added at the beginning of the list.
     */
    void addFirst(T data) {
        // TODO: TASK 1
    }

    /**
     * Removes the last node of the list.
     *
     * @return Value stored in the last node of the list.
     */
    T removeLast() {
        // TODO: TASK 1
        return 0;
    }

    /**
     * Removes the first node of the list.
     *
     * @return Value stored in the first node of the list.
     */
    T removeFirst() {
        // TODO: TASK 1
        return 0;
    }

    /**
     * Check if the list contains any elements.
     *
     * @return True if the list contains no elements, False otherwise.
     */
    bool isEmpty() {
        // TODO: TASK 1
        return true;
    }

    /**
     * Get the number of nodes in the list.
     *
     * @return The number of nodes stored in the list.
     */
    int size() {
        // TODO: TASK 1
        return 0;
    }

    // Getters & Setters
    Node<T> *getHead() {
        return head;
    }

    Node<T> *getTail() {
        return tail;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os,
            DoublyLinkedList<U>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T>& list) {
    Node<T> *it = list.getHead();

    if (list.size() > 0) {
        os << "[ ";
        while (it->next != nullptr) {
            os << it->data << " <-> ";
            it = it->next;
        }

        os << it->data;
        os << " ]";
    } else {
        os << "[]";
    }

    return os;
}

#endif // __DOUBLYLINKEDLIST_H__
