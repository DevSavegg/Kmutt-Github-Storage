#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
    private:
        T data;
        Node<T>* prev;
        Node<T>* next;
    public:
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}

        // Getters
        T GetData() const { return data; }
        Node<T>* GetPrev() const { return prev; }
        Node<T>* GetNext() const { return next; }

        // Setters
        void SetData(T value) { data = value; }
        void SetPrev(Node<T>* node) { prev = node; }
        void SetNext(Node<T>* node) { next = node; }
};

#endif