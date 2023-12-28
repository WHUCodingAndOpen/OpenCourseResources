// LinkedList.h
#include "Node.h"
#include <stdexcept>

template<typename T>
class LinkedList {
public:
    LinkedList() : front(nullptr), rear(nullptr), prevPtr(nullptr), currPtr(nullptr), size(0), position(-1) {}

    LinkedList(const LinkedList<T> &L) : front(nullptr), rear(nullptr), prevPtr(nullptr), currPtr(nullptr), size(0), position(-1) {
        copy(L);
    }

    ~LinkedList() {
        clear();
    }

    LinkedList<T> &operator=(const LinkedList<T> &L) {
        if (this != &L) {
            clear();
            copy(L);
        }
        return *this;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void reset(int pos = 0) {
        if (pos < 0 || pos > size) {
            throw std::out_of_range("Position out of range");
        }
        position = pos;
        prevPtr = nullptr;
        currPtr = front;
        for (int i = 0; i < pos; ++i) {
            prevPtr = currPtr;
            currPtr = currPtr->nextNode();
        }
    }

    void next() {
        if (currPtr) {
            prevPtr = currPtr;
            currPtr = currPtr->nextNode();
            ++position;
        }
    }

    bool endOfList() const {
        return currPtr == nullptr;
    }

    int currentPosition() const {
        return position;
    }

    void insertFront(const T &item) {
        Node<T> *newNode = new Node<T>(item, front);
        if (isEmpty()) {
            rear = newNode;
        }
        front = newNode;
        ++size;
        reset();
    }

    void insertRear(const T &item) {
        Node<T> *newNode = new Node<T>(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->insertAfter(newNode);
            rear = newNode;
        }
        ++size;
    }

    void insertAt(const T &item) {
        if (position == 0) {
            insertFront(item);
        } else {
            Node<T> *newNode = new Node<T>(item, currPtr);
            prevPtr->insertAfter(newNode);
            currPtr = newNode;
            ++size;
        }
    }

    void insertAfter(const T &item) {
        if (endOfList()) {
            insertRear(item);
        } else {
            Node<T> *newNode = new Node<T>(item, currPtr->nextNode());
            currPtr->insertAfter(newNode);
            if (currPtr == rear) {
                rear = newNode;
            }
            ++size;
        }
    }

    T deleteFront() {
        if (isEmpty()) {
            throw std::out_of_range("Empty list");
        }
        Node<T> *oldFront = front;
        T data = front->data;
        front = front->nextNode();
        delete oldFront;
        if (front == nullptr) {
            rear = nullptr;
        }
        --size;
        reset();
        return data;
    }

    void deleteCurrent() {
        if (currPtr == nullptr) {
            throw std::out_of_range("No current node");
        }
        if (currPtr == front) {
            deleteFront();
        } else {
            prevPtr->deleteAfter();
            Node<T> *tempPtr = currPtr;
            currPtr = currPtr->nextNode();
            delete tempPtr;
            if (currPtr == nullptr) {
                rear = prevPtr;
            }
            --size;
        }
    }

    T &data() {
        if (currPtr == nullptr) {
            throw std::out_of_range("No current node");
        }
        return currPtr->data;
    }

    const T &data() const {
        if (currPtr == nullptr) {
            throw std::out_of_range("No current node");
        }
        return currPtr->data;
    }

    void clear() {
        while (!isEmpty()) {
            deleteFront();
        }
    }

private:
    Node<T> *front, *rear;
    Node<T> *prevPtr, *currPtr;
    int size;
    int position;

    void copy(const LinkedList<T> &L) {
        Node<T> *ptr = L.front;
        while (ptr != nullptr) {
            insertRear(ptr->data);
            ptr = ptr->nextNode();
        }
    }
};