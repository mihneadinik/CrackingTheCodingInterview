#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

template <typename T>
struct Node {

    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {

    private:
        Node<T> *head;
        int numElements;

    public:
        // Basic constructor
        LinkedList() {
            head = nullptr;
            numElements = 0;
        }

        // Better constructor (if we already have a set of nodes, but not a list)
        LinkedList(Node<T> *head) {
            this->head = head;
            while (head != nullptr) {
                numElements++;
                head = head->next;
            }
        }

        // Destructor
        ~LinkedList() {
            if (numElements) {
                Node<T> *curr, *prev;
                curr = this->head->next;
                prev = this->head;
                while (curr != nullptr) {
                    delete prev;
                    prev = curr;
                    curr = curr->next;
                }
                delete prev;
                numElements = 0;
                this->head = nullptr;
            }
        }

        // Add a node on nth position
        void addNode(int pos, T data) {
            if (pos < 0)
                return;
            if (pos > this->numElements)
                pos = this->numElements;
            if (pos == 0) {
                Node<T> *new_node = new Node<T>(data);
                new_node->next = this->head;
                this->head = new_node;
            } else {
                Node<T> *curr = this->head;
                int cnt = 1;
                while (cnt < pos) {
                    cnt++;
                    curr = curr->next;
                }
                Node<T> *new_node = new Node<T>(data);
                new_node->next = curr->next;
                curr->next = new_node;
            }
            this->numElements++;
        }

        // Remove the node on nth position
        void remNode(int pos) {
            if (pos < 0 || this->numElements == 0)
                return;
            if (pos > this->numElements)
                pos = this->numElements;
            if (pos == 0) {
                Node<T> *curr = this->head->next;
                delete this->head;
                this->head = curr;
            } else {
                Node<T> *curr = this->head;
                int cnt = 0;
                while (cnt < pos - 1) {
                    cnt++;
                    curr = curr->next;
                }
                Node<T> *out = curr->next;
                curr->next = out->next;
                delete out;
            }
            this->numElements--;
        }

        // Check if there are elements
        bool is_empty() {
            if (this->numElements == 0)
                return true;
            else
                return false;
        }

        // Get the size
        int size() {
            return this->numElements;
        }

        // Getters
        Node<T> *getHead() {
            return this->head;
        }

        Node<T> *getTail() {
            if (this->numElements <= 1)
                return this->head;
            Node<T> *curr = this->head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            return curr;
        }

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, LinkedList<U>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, LinkedList<T>& list) {
    Node<T> *it = list.getHead();

    if (list.size() > 0) {
        os << "[ ";
        while (it->next != nullptr) {
            os << it->data << " -> ";
            it = it->next;
        }

        os << it->data;
        os << " ]";
    } else {
        os << "[]";
    }

    return os;
}

#endif // __LINKEDLIST_H__
