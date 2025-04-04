#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <cctype>
#include <memory>
#include <time.h>

using namespace std;

// Global //
unordered_set<string> existedName;

mt19937 gen;
uniform_int_distribution<> distrib;
uniform_int_distribution<> score;

// Struct //
struct StudentData {
    int id;
    string name;
    int midterm_score;
    int final_score;

    StudentData(int i, const string& n, int m, int f)
        : id(i), name(n), midterm_score(m), final_score(f) {}
};

struct TreeNode {
    int amount;
    vector<unique_ptr<StudentData>> students;
    TreeNode* left;
    TreeNode* right;
};

// Class //
class BST {
    private:
        TreeNode* root;

        void Clear(TreeNode* node) {
            if (node) {
                Clear(node->left);
                Clear(node->right);
                delete node;
            }
        }

        void InOrder(TreeNode* node) const {
            if (!node) return;

            InOrder(node->left);

            int finalScore = node->students[0]->final_score;
            cout << "Final Score " << finalScore << ":\n";
            for (const auto& student : node->students) {
                cout << "\tID: " << student->id 
                    << ", Name: " << student->name 
                    << ", Midterm: " << student->midterm_score 
                    << ", Final: " << student->final_score << "\n";
            }

            InOrder(node->right);
        }

        void CollectTotalScores(TreeNode* node, vector<int>& totals) const {
            if (!node) return;
            
            CollectTotalScores(node->left, totals);
            
            for (const auto& student : node->students) {
                int totalScore = student->midterm_score + student->final_score;
                totals.push_back(totalScore);
            }

            CollectTotalScores(node->right, totals);
        }
    public:
        BST() : root(nullptr) {}
        ~BST() {
            Clear(root);
        }

        void Insert(unique_ptr<StudentData> student) {
            int key = student->final_score;

            if (!root) {
                root = new TreeNode();
                root->students.push_back(move(student));
                root->amount = 1;
                return;
            }

            TreeNode* current = root;

            while (true) {
                int currentKey = current->students[0]->final_score;

                if (key == currentKey) {
                    current->students.emplace_back(move(student));
                    current->amount++;
                    return;
                } else if (key < currentKey) {
                    if (!current->left) {
                        current->left = new TreeNode();
                        current->left->students.emplace_back(move(student));
                        current->left->amount = 1;
                        return;
                    }
                    current = current->left;
                } else { // key > currentKey
                    if (!current->right) {
                        current->right = new TreeNode();
                        current->right->students.push_back(move(student));
                        current->right->amount = 1;
                        return;
                    }
                    current = current->right;
                }
            }
        }

        const vector<unique_ptr<StudentData>>* Search(int finalScore) const {
            TreeNode* current = root;

            while (current) {
                int currentKey = current->students[0]->final_score;

                if (finalScore == currentKey) {
                    return &current->students;
                } else if (finalScore < currentKey) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }

            return nullptr;
        }

        void PrintInOrder() const {
            InOrder(root);
        }

        vector<int> GetTotalScore() const {
            vector<int> totals;
            CollectTotalScores(root, totals);
            return totals;
        }
};

// Function Declaration //
const string GenerateName(int length);
unique_ptr<StudentData> GenerateData(int initialCount);
void InsertionSort(vector<unique_ptr<StudentData>>& newData);
void PrintStudentData(const vector<unique_ptr<StudentData>>& newData, int printAmount);
double ComputeMean(const vector<int>& scores);
int ComputeMode(const vector<int>& scores);
void InsertionSortMedian(std::vector<int>& vec, int left, int right);
int FindMedian(std::vector<int>& vec, int left, int right);
int Partition(std::vector<int>& vec, int left, int right, int pivot);
int KthSmallest(std::vector<int>& vec, int left, int right, int k);
double ComputeMedian(std::vector<int>& scores);

// Main //
int main() {
    // Initialize random seed data //
    auto now = chrono::high_resolution_clock::now();
    auto duration = now.time_since_epoch();
    unsigned int seed_value = static_cast<unsigned int>(duration.count());

    gen.seed(seed_value);
    distrib = uniform_int_distribution<>('A', 'Z');
    score = uniform_int_distribution<>(35, 50);
    /////////////////////////////////

    int amountToGenerate = 25;
    vector<unique_ptr<StudentData>> newData;

    for (int i = 1; i <= amountToGenerate; i++) { // Generate Data
        newData.emplace_back(GenerateData(i));
    }

    // Sort (???)
    InsertionSort(newData);

    // Create BST
    BST bst;

    // Insert data into BST
    for (auto& student : newData) {
        bst.Insert(move(student));
    }

    // Get set of total score
    vector<int> total_score = bst.GetTotalScore();

    // Process data
    double mean = ComputeMean(total_score);
    int mode = ComputeMode(total_score);
    double median = ComputeMedian(total_score);

    // Print all processed data
    cout << "Score: [ ";
    for (int i = 0; i < total_score.size(); i++) { // Print all score data
        cout << total_score[i] << " ";
    }
    cout << "]" << endl;

    cout << "Mean = " << mean << endl;
    cout << "Mean = " << mode << endl;
    cout << "Median = " << median << endl;
    
    return 0;
}

// Function Decoration //
const string GenerateName(int length) {
    string name = "";
    name.reserve(length);  // Fixed character length (length)

    for (int i = 0; i < length; i++) {
        name += static_cast<char>(distrib(gen));
    }

    if (existedName.count(name)) {
        return GenerateName(length);
    } else {
        existedName.insert(name);
        return name;
    }
}

unique_ptr<StudentData> GenerateData(int initialCount) {
    int id = 10000 + initialCount;
    int midterm_score = score(gen);
    int final_score = score(gen);

    string name = GenerateName(4); // Fixed name length : 4

    auto newStudent = make_unique<StudentData>(id, name, midterm_score, final_score);

    return newStudent;
}

void InsertionSort(vector<unique_ptr<StudentData>>& newData) {
    int n = newData.size();
    for (int i = 1; i < n; ++i) {
        unique_ptr<StudentData> current_student_ptr = move(newData[i]);
        int j = i - 1;

        while (j >= 0 && newData[j]->final_score > current_student_ptr->final_score) {
            newData[j + 1] = move(newData[j]);
            j = j - 1;
        }

        newData[j + 1] = move(current_student_ptr);
    }
}

void PrintStudentData(const vector<unique_ptr<StudentData>>& newData, int printAmount) {
    cout << "ID     NAME    MIDTERM   FINAL" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < printAmount && i < newData.size(); ++i) {
        const auto& current = *newData[i];
        cout << setw(5) << left << current.id << "    "
                  << setw(8) << left << current.name << "    "
                  << setw(8) << left << current.midterm_score << "     "
                  << setw(5) << left << current.final_score << endl;
    }
}

double ComputeMean(const vector<int>& scores) {
    int sum = 0;
    for (int score : scores) {
        sum += score;
    }

    return static_cast<double>(sum) / scores.size();
}

int ComputeMode(const vector<int>& scores) {
    if (scores.empty()) return -1;
    
    // Determine the range
    int minVal = *min_element(scores.begin(), scores.end());
    int maxVal = *max_element(scores.begin(), scores.end());
    int range = maxVal - minVal + 1;
    
    vector<int> frequency(range, 0);
    for (int score : scores) {
        frequency[score - minVal]++;
    }
    
    int mode = minVal;
    int maxCount = frequency[0];
    for (int i = 1; i < range; i++) {
        if (frequency[i] > maxCount) {
            maxCount = frequency[i];
            mode = i + minVal;
        }
    }
    return mode;
}

void InsertionSortMedian(std::vector<int>& vec, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

int FindMedian(std::vector<int>& vec, int left, int right) {
    InsertionSortMedian(vec, left, right);
    return vec[left + (right - left) / 2];
}

int Partition(std::vector<int>& vec, int left, int right, int pivot) {
    for (int i = left; i < right; i++) {
        if (vec[i] == pivot) {
            std::swap(vec[i], vec[right]);
            break;
        }
    }
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (vec[i] < pivot) {
            std::swap(vec[storeIndex], vec[i]);
            storeIndex++;
        }
    }
    std::swap(vec[storeIndex], vec[right]);
    return storeIndex;
}

int KthSmallest(std::vector<int>& vec, int left, int right, int k) {
    if (left == right) return vec[left];

    int n = right - left + 1;
    std::vector<int> medians;
    for (int i = 0; i < n / 5; i++) {
        int groupLeft = left + i * 5;
        int groupRight = groupLeft + 4;
        medians.push_back(FindMedian(vec, groupLeft, groupRight));
    }
    
    if (n % 5 != 0) {
        int groupLeft = left + (n / 5) * 5;
        int groupRight = right;
        medians.push_back(FindMedian(vec, groupLeft, groupRight));
    }

    int pivot;
    if (medians.size() == 1)
        pivot = medians[0];
    else {
        pivot = KthSmallest(medians, 0, medians.size() - 1, medians.size() / 2);
    }

    int pivotIndex = Partition(vec, left, right, pivot);
    int num = pivotIndex - left + 1;

    if (k == num)
        return vec[pivotIndex];
    else if (k < num)
        return KthSmallest(vec, left, pivotIndex - 1, k);
    else
        return KthSmallest(vec, pivotIndex + 1, right, k - num);
}

double ComputeMedian(std::vector<int>& scores) {
    int n = scores.size();
    if (n % 2 == 1) {
        // Odd size: find the middle element
        return KthSmallest(scores, 0, n - 1, n / 2 + 1);
    } else {
        // Even size: average the two middle elements
        int leftMid = KthSmallest(scores, 0, n - 1, n / 2);
        int rightMid = KthSmallest(scores, 0, n - 1, n / 2 + 1);
        return (leftMid + rightMid) / 2.0;
    }
}