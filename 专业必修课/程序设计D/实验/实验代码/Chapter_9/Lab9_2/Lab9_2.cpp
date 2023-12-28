#include "LinkedList.h"
#include <iostream>

int main() {
    LinkedList<int> A;
    LinkedList<int> B;

    for (int i = 1; i <= 5; ++i) {
        A.insertRear(i);
    }

 
    for (int i = 6; i <= 10; ++i) {
        B.insertRear(i);
    }

  
    B.reset();
    while (!B.endOfList()) {
        A.insertRear(B.data());
        B.next();
    }

    std::cout << "List A after appending elements of list B:" << std::endl;
    A.reset(); // Reset cursor to the beginning of list A
    while (!A.endOfList()) {
        std::cout << A.data() << " ";
        A.next();
    }
    std::cout << std::endl;

    return 0;
}
