#include <iostream>

using namespace std;

template <typename T>
class Node {
    private:
        T data;

        Node* prev;
        Node* next;
    public:
        // Constructor
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}

        // Getters
        T GetData() const {return data;}
        Node* GetPrev() const {return prev;}
        Node* GetNext() const {return next;}

        // Setters
        void SetData(T value) {data = value;}
        void SetPrev(Node* node) {prev = node;}
        void SetNext(Node* node) {next = node;}
};

template <typename T>
class DoublyLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* fence;
    public:
        // Constructor
        DoublyLinkedList(): head(nullptr), tail(nullptr), fence(nullptr) {}

        // Destructor
        ~DoublyLinkedList() {
            Node<T>* current = head;
            while (current) {
                Node<T>* nextNode = current->GetNext();
                delete current;
                current = nextNode;
            }
        }

        // Getters
        Node<T>* GetHead() const {return head;}
        Node<T>* GetTail() const {return tail;}
        Node<T>* GetFence() const {return fence;}

        // Insert Methods
        void Append(T value) { // At end
            Node<T>* newNode = new Node<T>(value);

            if (!head) {
                head = tail = fence = newNode;
            } else {
                tail->SetNext(newNode);
                newNode->SetPrev(tail);
                tail = newNode;
            }
        }
        void Prepend(T value) { // At beginning
            Node<T>* newNode = new Node<T>(value);

            if (!head) {
                head = fence = tail = newNode;
            } else {
                newNode->SetNext(head);
                head->SetPrev(newNode);
                head = newNode;
            }
        }

        // Fence Methods
        void MoveToStart() {
            fence = head;
        }
        void MoveToEnd() {
            fence = tail;
        }
        void Next() {
            if (fence && fence->GetNext()) {
                fence = fence->GetNext();
            }
        }
        void Prev() {
            if (fence && fence->GetPrev()) {
                fence = fence->GetPrev();
            }
        }
        // Merge two sorted sublists using fence
        void merge(Node<T>* left, Node<T>* right) {
            cout << "Merging sublists:" << endl;
            cout << "Left sublist: ";
            Node<T>* temp = left;
            while (temp && temp != right) {
                cout << temp->GetData() << " ";
                temp = temp->GetNext();
            }
            cout << endl << "Right sublist: ";
            temp = right;
            while (temp) {
                cout << temp->GetData() << " ";
                temp = temp->GetNext();
            }
            cout << endl;

            DoublyLinkedList<T> result;
            
            while (left && right) {
                if (left->GetData() <= right->GetData()) {
                    result.Append(left->GetData());
                    left = left->GetNext();
                } else {
                    result.Append(right->GetData());
                    right = right->GetNext();
                }
            }

            // Add remaining elements
            while (left) {
                result.Append(left->GetData());
                left = left->GetNext();
            }
            while (right) {
                result.Append(right->GetData());
                right = right->GetNext();
            }

            // Copy result back to this list
            Node<T>* current = head;
            Node<T>* resultCurrent = result.GetHead();
            while (resultCurrent) {
                current->SetData(resultCurrent->GetData());
                current = current->GetNext();
                resultCurrent = resultCurrent->GetNext();
            }
        }

        // Get length of list from start to end
        int getLength() {
            int length = 0;
            Node<T>* current = head;
            while (current) {
                length++;
                current = current->GetNext();
            }
            return length;
        }

        // Main merge sort function
        void mergeSortHelper(int length) {
            cout << "\nMergeSortHelper called with length: " << length << endl;
            cout << "Current list: ";
            PrintList();
            
            if (length <= 1) {
                cout << "Length <= 1, returning" << endl;
                return;
            }

            int mid = length / 2;
            cout << "Mid point: " << mid << endl;
            
            // Split list into two halves
            MoveToStart();
            for (int i = 0; i < mid - 1; i++) {
                Next();
            }
            
            Node<T>* rightStart = fence->GetNext();
            int leftLength = mid;
            int rightLength = length - mid;

            cout << "Splitting into:" << endl;
            cout << "Left length: " << leftLength << ", Right length: " << rightLength << endl;

            // Recursively sort both halves
            cout << "\nSorting left half..." << endl;
            mergeSortHelper(leftLength);
            cout << "\nSorting right half..." << endl;
            mergeSortHelper(rightLength);

            cout << "\nMerging halves..." << endl;
            merge(head, rightStart);
        }

        // Public interface for merge sort
        void MergeSort() {
            if (!head || !head->GetNext()) return;
            mergeSortHelper(getLength());
            MoveToStart(); // Reset fence to start
        }


        void PrintList() {
            Node<T>* current = head;
            while (current) {
                cout << current->GetData() << " ";
                current = current->GetNext();
            }
            cout << endl;
        }
};

int main() {
    DoublyLinkedList<int> list;
    list.Append(7);
    list.Append(3);
    list.Append(9);
    list.Append(1);
    list.Append(5);
    list.Append(2);
    list.Append(8);
    list.Append(4);
    list.Append(10);
    list.Append(6);
    list.PrintList();

    list.MergeSort();
    list.PrintList();
}