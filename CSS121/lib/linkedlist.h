#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* fence;
    int count;

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr), fence(nullptr), count(0) {}

    // Destructor
    ~LinkedList() {
        Node<T>* current = head;
        while (current)
        {
            Node<T>* next = current->GetNext();
            delete current;
            current = next;
        }
    }

    // Getters
    Node<T>* GetHead() const { return head; }
    Node<T>* GetTail() const { return tail; }
    Node<T>* GetFence() const { return fence; }

    // Method to get the length of the list
    int GetLength() const {
        return count;
    }

    // Add node at tail
    void Append(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->SetNext(newNode);
            newNode->SetPrev(tail);
            tail = newNode;
        }

        if (!fence) {
            fence = head;
        }
        count++;
    }

    // Add node at head
    void Prepend(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            head = tail = newNode;
        } else {
            head->SetPrev(newNode);
            newNode->SetNext(head);
            head = newNode;
        }

        if (!fence) {
            fence = head;
        }
        count++;
    }

    // Fence methods
    void SetFenceToHead() { // Reset fence to head
        fence = head;
    }
    void SetFenceToTail() { // Set fence to tail
        fence = tail;
    }
    void MoveFenceForward() { // Move fence forward in the list
        if (fence && fence->GetNext()) {
            fence = fence->GetNext();
        }
    }
    void MoveFenceBackward() { // Move fence backward in the list
        if (fence && fence->GetPrev()) {
            fence = fence->GetPrev();
        }
    }
    void InsertBeforeFence(T value) { // Insert element in front of fence
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            head = tail = fence = newNode;
        } else if (!fence) {
            newNode->SetNext(head);
            head->SetPrev(newNode);
            head = newNode;
            fence = newNode;
        } else {
            Node<T>* before = fence->GetPrev();

            newNode->SetNext(fence);
            newNode->SetPrev(before);
            fence->SetPrev(newNode);

            if (before) {
                before->SetNext(newNode);
            } else {
                head = newNode;
            }

            fence = newNode;
        }
        count++;
    }
    void InsertAfterFence(T value) { // Insert element after fence
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            head = tail = fence = newNode;
        } else if (!fence) {
            newNode->SetNext(head);
            head->SetPrev(newNode);
            head = fence = newNode;
        } else {
            Node<T>* after = fence->GetNext();

            fence->SetNext(newNode);
            newNode->SetPrev(fence);
            newNode->SetNext(after);

            if (after) {
                after->SetPrev(newNode);
            } else {
                tail = newNode;
            }

            fence = newNode;
        }
        count++;
    }
    void RemoveAfterFence() { // Remove element after fence
        if (!fence) {
            return;
        }

        Node<T>* target = fence->GetNext();

        if (!target) {
            return;
        }

        Node<T>* after = target->GetNext();
        fence->SetNext(after);

        if (after) {
            after->SetPrev(fence);
        } else {
            tail = fence;
        }

        delete target;
        count--;
    }
    void RemoveAtFence() { // Remove element at fence
        if (!fence) {
            return;
        }

        if (fence == head) {
            head = head->GetNext();

            if (head) {
                head->SetPrev(nullptr);
            } else {
                tail = nullptr;
            }

            delete fence;
            fence = head;
        } else if (fence == tail) {
            tail = tail->GetPrev();

            if (tail) {
                tail->SetNext(nullptr);
            } else {
                head = nullptr;
            }

            delete fence;
            fence = tail;
        } else {
            Node<T>* prevNode = fence->GetPrev();
            Node<T>* nextNode = fence->GetNext();
            prevNode->SetNext(nextNode);
            nextNode->SetPrev(prevNode);

            delete fence;
            fence = nextNode;
        }
        count--;
    }

    void PrintList() { // Print all the element this list contain
        Node<T>* current = head;

        while (current) {
            if (current->GetNext()) {
                std::cout << current->GetData() << " -> ";
            } else {
                std::cout << current->GetData() << std::endl;
            }

            current = current->GetNext();
        }
    }
};

#endif