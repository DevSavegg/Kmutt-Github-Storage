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

// Function Declaration //
const string GenerateName(int length);
unique_ptr<StudentData> GenerateData(int initialCount);
void insertionSort(vector<unique_ptr<StudentData>>& newData);
void printStudentData(const vector<unique_ptr<StudentData>>& newData, int printAmount);

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

    int amountToGenerate = 20;
    vector<unique_ptr<StudentData>> newData;

    for (int i = 1; i <= amountToGenerate; i++) {
        newData.emplace_back(GenerateData(i));
    }

    // Insertion Sort
    insertionSort(newData);
    // ไส้กรอก

    printStudentData(newData, 20); // Print 20 student info

    for (int i = 21; i <= 25; i++) {
        newData.emplace_back(GenerateData(i));
    }

    // Insertion Sort
    insertionSort(newData);
    // ไส้กรอก

    printStudentData(newData, 25); // Print 25 student info

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

void insertionSort(vector<unique_ptr<StudentData>>& newData) {
    int n = newData.size();
    for (int i = 1; i < n; ++i) {
        unique_ptr<StudentData> current_student_ptr = move(newData[i]);
        int j = i - 1;

        while (j >= 0 && newData[j]->midterm_score > current_student_ptr->midterm_score) {
            newData[j + 1] = move(newData[j]);
            j = j - 1;
        }

        newData[j + 1] = move(current_student_ptr);
    }
}

void printStudentData(const vector<unique_ptr<StudentData>>& newData, int printAmount) {
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