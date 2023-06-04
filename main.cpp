#include <iostream>
#include "clist.h"

int main() {
    CList list;

    list.insertEnd(10);
    list.insertEnd(30);
    list.insertEnd(20);
    list.insertEnd(50);

    std::cout << "Original list: ";
    list.show();
    std::cout << "Reversed list: ";
    list.show(true);

    list.sort();
    std::cout << "Sorted list: ";
    list.show();

    list.insertBegin(5);
    list.insertBegin(15);
    list.insertAfter(10, 25);

    std::cout << "Updated list: ";
    list.show();

    int value = list.popBegin();
    std::cout << "Popped value from the beginning: " << value << std::endl;

    value = list.popEnd();
    std::cout << "Popped value from the end: " << value << std::endl;

    list.deleteElem(20);
    std::cout << "List after deleting element 20: ";
    list.show();

    bool empty = list.isEmpty();
    std::cout << "Is the list empty? " << (empty ? "Yes" : "No") << std::endl;

    return 0;
}