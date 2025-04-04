#include <iostream>
#include "../../lib/linkedlist.h"

using namespace std;

int main() {
    int n = 5;
    LinkedList<int> myList;
    myList.SetFenceToHead();

    while (true) {
        int input;
        std::cout << "Input: ";
        std::cin >> input;

        if (input <= -1) {
            break;
        }

        if (!myList.GetHead()) {
            myList.Append(input);
            continue;
        }

        Node<int>* current = myList.GetHead();
        bool inserted = false;

        if (input > current->GetData()) {
            myList.Prepend(input);
            inserted = true;
        } else {
            while (current->GetNext()) {
                if (input > current->GetNext()->GetData()) {
                    myList.SetFenceToHead();
                    while(myList.GetFence()!=current){
                        myList.MoveFenceForward();
                    }
                    myList.InsertAfterFence(input);
                    inserted = true;
                    break;
                }
                current = current->GetNext();
            }
            if (!inserted) {
                myList.Append(input);
            }
        }
    }

    if (myList.GetLength() > n) {
        myList.SetFenceToTail();
        myList.RemoveAtFence();
    }

    cout << endl;
    cout << "Sorted list: ";
    myList.PrintList();

    cout << "Length: " << myList.GetLength() << endl;

    return 0;
}