#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// Type Definition ///
typedef pair<int, float> iPairs;

/// Class Declaration ///
class Node {
public:
    int id; // Node ID
    string nodeLabel; // Label/Name
    vector<iPairs> edges; // All connected nodes <Destination (ID), weight>

    Node(int id, string label = "") : id(id), nodeLabel(label) {}

    void addEdge(int destination, float weight);
    void removeEdge(int destination);
};

/// Method Decoration ///

void Node::addEdge(int destination, float weight) {
    edges.emplace_back(destination, weight);
}

void Node::removeEdge(int destination) {
    edges.erase(
        remove_if(
            edges.begin(), edges.end(), // Vector Range
            [destination](const iPairs edge) {
                return edge.first == destination; // Remove edge with the given destination
            }
        ),
        edges.end() // Remove anything beyond above end that returned by remove_if()
    );
}