#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include "../../lib/linkedlist.h"

using namespace std;

int main() {
    int n = 5;
    LinkedList<pair<int, string>> myList;
    myList.SetFenceToHead();

    while (true) {
        int a;
        string name;
        cout << "Input: ";
        cin >> a;
        cin.ignore();

        if (a <= -1) {
            break;
        }

        cout << "Name: ";
        getline(cin, name);

        pair<int, string> input(a, name);

        if (!myList.GetHead()) {
            myList.Append(input);
            continue;
        }

        Node<pair<int, string>>* current = myList.GetHead();
        bool inserted = false;

        if (input.first > current->GetData().first) {
            myList.Prepend(input);
            inserted = true;
        } else {
            while (current->GetNext()) {
                if (input.first > current->GetNext()->GetData().first) {
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
        while (myList.GetLength() > n) {
            myList.SetFenceToTail();
            myList.RemoveAtFence();
        }
    }

    cout << endl;
    cout << "Sorted list: " << endl;
    
    myList.SetFenceToHead();
    
    
    for (int i = 0; i < myList.GetLength(); i++)
    {
        Node<pair<int, string>>* current = myList.GetFence();

        cout << "-----------------------" << endl;
        cout << "Score: " << current->GetData().first << endl;
        cout << "Name:  " << current->GetData().second << endl;
        
        myList.MoveFenceForward();
    }
    cout << "-----------------------" << endl;

    cout << "Length: " << myList.GetLength() << endl;

    return 0;
}