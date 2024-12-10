#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

/// Type Definition ///
typedef pair<int, float> iPairs;

/// Class Declaration ///
class Node {
public:
    // Properties //
    int id; // Node ID
    string nodeLabel; // Label/Name
    vector<iPairs> edges; // All connected nodes <Destination (ID), weight>

    // Constructor //
    Node(int id, string label = "") : id(id), nodeLabel(label) {}

    // Method //
    void addEdge(int destination, float weight);
    void removeEdge(int destination);
    const vector<iPairs>& getEdges() const;
};

class UnionFind {
private:
    // Properties //
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
public:
    // Method //
    void addNode(int node);
    int find(int node);
    void unionSets(int u, int v);
};

class Graph {
private:
    // Properties //
    unordered_map<int, Node> nodes;
    bool directed; // To declare if the graph is directed or not.
public:
    // Constructor //
    Graph(bool directed = false) : directed(directed) {}

    // Method //
    void addNode(int id, const string& label);
    void removeNode(int id);

    void addEdge(int sourceID, int destinationID, float weight);
    void removeEdge(int sourceID, int destinationID);

    bool hasCycle(); // Using Union-Find Data Structure to detect the cycle in the graph
    void displayGraph() const;

    int getSize();
};

/// Main Function ///

int main() {
    int startIndex;
    int directed;

    cout << "Directed Graph? (1 = true, 0 = false)" << endl;
    cout << "Input : ";
    cin >> directed;

    if (cin.fail() || (directed != 1 && directed != 0)) {
        cout << "Bad input, abort." << endl;
        return EXIT_FAILURE;
    }

    Graph g(directed == 1 ? true : false);

    cout << "+-----------------------------+" << endl;
    cout << "|          Add Nodes          |" << endl;
    cout << "+-----------------------------+\n" << endl;

    cout << "Input Starting Node Index : ";
    cin >> startIndex;

    cout << endl;
    cout << "Add node label process, stop by input '*'" << endl;
    cout << endl;

    for (int i = startIndex;; i++) {
        string label;

        cout << "------------------------------" << endl;
        cout << "Node {" << i << "} label : ";
        cin >> label;

        if (label == "*") {
            break;
        }
        g.addNode(i, label);
    }

    cout << endl;
    cout << "+-----------------------------+" << endl;
    cout << "|          Add Edges          |" << endl;
    cout << "+-----------------------------+\n" << endl;

    cout << "Input edge structure by the following order : source(int) destination(int) weight(float)" << endl;
    cout << "*** Input 'source' below your node starting index to stop input process.\n" << endl;

    for (int i = 0;; i++) {
        int source, destination;
        float weight;

        cout << "------------------------------" << endl;
        cout << "Input : ";
        cin >> source >> destination >> weight;

        if (source < startIndex) {
            break;
        }

        g.addEdge(source, destination, weight);
        
        cout << "Added edge " << source << " <-> " << destination << " [weight: " << weight << "]" << endl;
    }
    cout << "\n\n\n";

    g.displayGraph();

    if (g.hasCycle()) {
        cout << "Graph has a cycle." << endl;
    } else {
        cout << "Graph does not have a cycle." << endl;
    }

    return EXIT_SUCCESS;
}

/// Method Definition ///

//------------------- Node -------------------//
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

const vector<iPairs>& Node::getEdges() const {
    return edges;
}

//------------------- UnionFind -------------------//
void UnionFind::addNode(int node) {
    if (parent.find(node) == parent.end()) {
        parent[node] = node;
        rank[node] = 0;
    }
}

int UnionFind::find(int node) {
    if (parent.find(node) == parent.end()) {
        return -1;
    }

    if (parent[node] != node) {
        parent[node] = find(parent[node]); // Path Compression
    }

    return parent[node];
}

void UnionFind::unionSets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

//------------------- Graph -------------------//
void Graph::addNode(int id, const string& label = "") {
    if (nodes.find(id) == nodes.end()) {
        nodes.emplace(id, Node(id, label));
    }
}

void Graph::removeNode(int id) {
    nodes.erase(id);
    for (auto& [id, node] : nodes) {
        node.removeEdge(id);
    }
}

void Graph::addEdge(int sourceID, int destinationID, float weight) {
    nodes.at(sourceID).addEdge(destinationID, weight);
    if (!directed) {
        nodes.at(destinationID).addEdge(sourceID, weight); // If the graph is undirected, add the edge pointer back from destination to source
    }
}

void Graph::removeEdge(int sourceID, int destinationID) {
    if (nodes.find(sourceID) != nodes.end()) {
        nodes.at(sourceID).removeEdge(destinationID);
    }
    if (!directed && nodes.find(destinationID) != nodes.end()) {
        nodes.at(destinationID).removeEdge(sourceID);
    }
}

bool Graph::hasCycle() {
    UnionFind uf;

    // Initialize Union-Find Data Structure
    for (const auto& [id, _] : nodes) {
        uf.addNode(id);
    }

    // Loop over all possible edges
    for (const auto& [id, node] : nodes) {
        for (const auto& [neighbor, _] : node.getEdges()) {
            if (!directed && id > neighbor) { // Prevent any further issues with Undirected Graph
                continue;
            }
            
            int root_u = uf.find(id);
            int root_v = uf.find(neighbor);

            if (root_u == root_v) {
                return true; // Cycle detected
            } else {
                uf.unionSets(id, neighbor); // Union the two sets
            }
        }
    }

    return false; // No cycle detected
}

void Graph::displayGraph() const {
    for (const auto& [id, node] : nodes) {
        std::cout << "Node " << id << " (" << node.nodeLabel << "):\n";
        for (const auto& [dest, weight] : node.getEdges()) {
            std::cout << "  " << id << " --(" << weight << ")--> " << dest << "\n";
        }
        std::cout << "-----------------------------------\n";
    }
}

int Graph::getSize() {
    return nodes.size();
}