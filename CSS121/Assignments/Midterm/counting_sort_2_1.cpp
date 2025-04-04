#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Global //

// Struct //
struct Transaction {
    int id;
    int itemCount;
    vector<int> items;

    Transaction(int id, int itemCount, const vector<int>& items) 
        : id(id), itemCount(itemCount), items(items) {}
};

// Function Declaration //
int ItemToIndex(char C);
char IndexToItem(int index);
vector<Transaction> ReadTransactions();
void PrintTransaction(const Transaction &trans);
map<char, vector<int>> BuildItemToTransaction(const vector<Transaction> &transactions);
void ProcessItemPairs(const map<char, vector<int>> &itemMap);

// Main //
int main() {
    vector<Transaction> transactions = ReadTransactions();

    cout << "--------------------" << endl;

    // for (auto tran : transactions) {
    //     PrintTransaction(tran);
    // }

    // cout << "--------------------" << endl;

    map<char, vector<int>> itemMap = BuildItemToTransaction(transactions);

    // cout << "=== Item to Transaction Mapping ===" << endl;
    // for (auto &pair : itemMap) {
    //     char item = pair.first;
    //     const vector<int> &txIDs = pair.second;

    //     cout << "Item " << item << " appears in Transactions : [";
    //     for (size_t i = 0; i < txIDs.size(); i++) {
    //         cout << txIDs[i];
    //         if (i < txIDs.size() - 1) cout << ", ";
    //     }
    //     cout << "]\n";
    // }

    cout << "--------------------" << endl;
    ProcessItemPairs(itemMap);

    return 0;
}

// Function Decoration //
int ItemToIndex(char C) {
    return C - 'A';
}

char IndexToItem(int index) {
    return 'A' + index;
}

vector<Transaction> ReadTransactions() {
    int N;
    cout << "Enter the number of transactions: ";
    cin >> N;
    
    vector<Transaction> transactions;
    for (int i = 0; i < N; i++) {
        int id, count;
        cin >> id >> count;
        
        vector<int> items;
        //cout << "Enter items for transaction " << id << " (e.g., A B C): ";
        for (int j = 0; j < count; j++) {
            char c;
            cin >> c;
            items.push_back(ItemToIndex(c));
        }
        transactions.emplace_back(id, count, items);
    }
    return transactions;
}

void PrintTransaction(const Transaction &trans) {
    cout << "Transaction ID: " << trans.id << "\n";
    cout << "Items: ";
    for (size_t i = 0; i < trans.items.size(); i++) {
        cout << IndexToItem(trans.items[i]);
        if (i < trans.items.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

map<char, vector<int>> BuildItemToTransaction(const vector<Transaction> &transactions) {
    map<char, vector<int>> itemToTransaction;

    for (const auto &trans : transactions) {
        for (char item : trans.items) {
            itemToTransaction[IndexToItem(item)].push_back(trans.id);
        }
    }

    return itemToTransaction;
}

// Gathering items: O(N)
// Sorting: O(N log N)
// Pair processing: O(N^2 log N + N M)

// N: Number of unique items (keys in itemMap)
// M: Total size of all transaction lists (sum of lengths of all vectors)
void ProcessItemPairs(const map<char, vector<int>> &itemMap) {
    vector<char> items;
    items.reserve(itemMap.size());
    for (const auto &kv : itemMap) {
        items.push_back(kv.first);
    }
    
    sort(items.begin(), items.end());
    
    for (size_t i = 0; i < items.size(); ++i) {
        for (size_t j = i + 1; j < items.size(); ++j) {
            char item1 = items[i];
            char item2 = items[j];
            
            const vector<int> &list1 = itemMap.at(item1);
            const vector<int> &list2 = itemMap.at(item2);

            size_t idx1 = 0, idx2 = 0;
            int commonCount = 0;
            while (idx1 < list1.size() && idx2 < list2.size()) {
                if (list1[idx1] == list2[idx2]) {
                    ++commonCount;
                    ++idx1;
                    ++idx2;
                }
                else if (list1[idx1] < list2[idx2]) {
                    ++idx1;
                }
                else {
                    ++idx2;
                }
            }
            
            if (commonCount >= 4) {
                cout << "(" << item1 << ", " << item2 << ") -> " 
                     << commonCount << " transactions\n";
            }
        }
    }
}