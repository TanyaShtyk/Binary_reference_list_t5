#include "clist.h"

CList::CList() : head(nullptr), tail(nullptr) {}

CList::CList(const CList& other) : head(nullptr), tail(nullptr) {
    Node* current = other.head;
    while (current != nullptr) {
        insertEnd(current->data);
        current = current->next;
    }
}

CList::~CList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

CList& CList::operator=(const CList& other) {
    if (this != &other) {
        // Clear existing list
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;

        // Copy elements from other list
        current = other.head;
        while (current != nullptr) {
            insertEnd(current->data);
            current = current->next;
        }
    }
    return *this;
}

void CList::insertBegin(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void CList::insertEnd(int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

bool CList::insertAfter(int afterValue, int value) {
    Node* afterNode = findNode(afterValue);
    if (afterNode == nullptr) {
        return false;
    }
    Node* newNode = new Node(value);
    newNode->prev = afterNode;
    newNode->next = afterNode->next;
    if (afterNode->next != nullptr) {
        afterNode->next->prev = newNode;
    } else {
        tail = newNode;
    }
    afterNode->next = newNode;
    return true;
}

int CList::popBegin() {
    if (head == nullptr) {
        return -1; // Or throw an exception indicating an empty list
    }
    Node* firstNode = head;
    int value = firstNode->data;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete firstNode;
    return value;
}

int CList::popEnd() {
    if (tail == nullptr) {
        return -1; // Or throw an exception indicating an empty list
    }
    Node* lastNode = tail;
    int value = lastNode->data;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete lastNode;
    return value;
}

bool CList::deleteElem(int value) {
    Node* nodeToDelete = findNode(value);
    if (nodeToDelete == nullptr) {
        return false;
    }
    if (nodeToDelete == head) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
    } else if (nodeToDelete == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;
    }
    delete nodeToDelete;
    return true;
}

bool CList::isEmpty() const {
    return head == nullptr;
}

void CList::sort() {
    if (head == nullptr || head == tail) {
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        Node* minNode = current;
        Node* nextNode = current->next;
        while (nextNode != nullptr) {
            if (nextNode->data < minNode->data) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }
        if (minNode != current) {
            swapNodes(current, minNode);
        }
        current = current->next;
    }
}

void CList::show(bool reverse) const {
    if (reverse) {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
    } else {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
    std::cout << std::endl;
}

CList::Node* CList::findNode(int value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void CList::swapNodes(Node* node1, Node* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}