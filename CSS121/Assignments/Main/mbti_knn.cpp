#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    vector<double> coords;
    string label;

    Point(const vector<double>& coords, const string& label)
        : coords(coords), label(label) {}
};

struct KDNode {
    Point point;
    KDNode* left;
    KDNode* right;
    int axis;

    KDNode(const Point& pt, int axis)
        : point(pt), left(nullptr), right(nullptr), axis(axis) {}
};

