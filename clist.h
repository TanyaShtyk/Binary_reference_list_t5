#ifndef CLIST_H
#define CLIST_H

#include <iostream>

class CList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };
 
    Node* head;
    Node* tail;

public:
    CList();
    CList(const CList& other); // Copy constructor
    ~CList();

    CList& operator=(const CList& other); // Assignment operator

    void insertBegin(int value);
    void insertEnd(int value);
    bool insertAfter(int afterValue, int value);
    int popBegin();
    int popEnd();
    bool deleteElem(int value);
    bool isEmpty() const;
    void sort();
    void show(bool reverse = false) const;

private:
    Node* findNode(int value) const;
    void swapNodes(Node* node1, Node* node2);
};

#endif
