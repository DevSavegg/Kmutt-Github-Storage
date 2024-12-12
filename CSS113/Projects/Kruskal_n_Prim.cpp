/* ##################################################################### */
/* # _  __               _         _    ___     ____       _           # */
/* #| |/ /_ __ _   _ ___| | ____ _| |  ( _ )   |  _ \ _ __(_)_ __ ___  # */
/* #| ' /| '__| | | / __| |/ / _` | |  / _ \/\ | |_) | '__| | '_ ` _ \ # */
/* #| . \| |  | |_| \__ \   < (_| | | | (_>  < |  __/| |  | | | | | | |# */
/* #|_|\_\_|   \__,_|___/_|\_\__,_|_|  \___/\/ |_|   |_|  |_|_| |_| |_|# */
/* ##################################################################### */

#include <iostream>
#include <cstdlib>
#include <climits>
#include <queue>
#include <tuple>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>

using namespace std;



/* ###################################################################### */
/* # _____                   ____        __ _       _ _   _             # */
/* #|_   _|   _ _ __   ___  |  _ \  ___ / _(_)_ __ (_) |_(_) ___  _ __  # */
/* #  | || | | | '_ \ / _ \ | | | |/ _ \ |_| | '_ \| | __| |/ _ \| '_ \ # */
/* #  | || |_| | |_) |  __/ | |_| |  __/  _| | | | | | |_| | (_) | | | |# */
/* #  |_| \__, | .__/ \___| |____/ \___|_| |_|_| |_|_|\__|_|\___/|_| |_|# */
/* #      |___/|_|                                                      # */
/* ###################################################################### */

typedef pair<int, float> iPairs;
typedef tuple<int, int, float> prim_edge;



/* ############################################################################### */
/* #  ____ _                 ____            _                 _   _             # */
/* # / ___| | __ _ ___ ___  |  _ \  ___  ___| | __ _ _ __ __ _| |_(_) ___  _ __  # */
/* #| |   | |/ _` / __/ __| | | | |/ _ \/ __| |/ _` | '__/ _` | __| |/ _ \| '_ \ # */
/* #| |___| | (_| \__ \__ \ | |_| |  __/ (__| | (_| | | | (_| | |_| | (_) | | | |# */
/* # \____|_|\__,_|___/___/ |____/ \___|\___|_|\__,_|_|  \__,_|\__|_|\___/|_| |_|# */
/* ############################################################################### */

class Node {
public:
    // Properties //
    int id; // Node ID
    string nodeLabel; // Label/Name
    vector<iPairs> edges; // All connected nodes <Destination (ID), weight>
    bool visited = false; // For Prim's Algorithm

    // Constructor //
    Node(int id, string label = "") : id(id), nodeLabel(label) {}

    bool operator==(const Node& otherNode) const {
        return this->id == otherNode.id;
    }

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

    bool isDirected();
    bool hasCycle(); // Using Union-Find Data Structure to detect the cycle in the graph
    
    int getSize();
    void displayGraph() const;

    const Node& getNode(int id);
    const unordered_map<int, Node>& getNodes();
};



/* ##################################################################### */
/* # ____  _        _   _       __     __         _       _     _      # */
/* #/ ___|| |_ __ _| |_(_) ___  \ \   / /_ _ _ __(_) __ _| |__ | | ___ # */
/* #\___ \| __/ _` | __| |/ __|  \ \ / / _` | '__| |/ _` | '_ \| |/ _ \# */
/* # ___) | || (_| | |_| | (__    \ V / (_| | |  | | (_| | |_) | |  __/# */
/* #|____/ \__\__,_|\__|_|\___|    \_/ \__,_|_|  |_|\__,_|_.__/|_|\___|# */
/* ##################################################################### */

static Node NULL_NODE(-1, "NULL");



/* ################################################################## */
/* # __  __       _         _____                 _   _             # */
/* #|  \/  | __ _(_)_ __   |  ___|   _ _ __   ___| |_(_) ___  _ __  # */
/* #| |\/| |/ _` | | '_ \  | |_ | | | | '_ \ / __| __| |/ _ \| '_ \ # */
/* #| |  | | (_| | | | | | |  _|| |_| | | | | (__| |_| | (_) | | | |# */
/* #|_|  |_|\__,_|_|_| |_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|# */
/* ################################################################## */

int main() {

    //-------------- Graph Setup --------------//

    int startIndex;
    int startNodeID;
    int directed;

    cout << "Directed Graph? (1 = true, 0 = false)" << endl;
    cout << "Input : ";
    cin >> directed;

    if (cin.fail() || (directed != 1 && directed != 0)) {
        cout << "Bad input, abort." << endl;
        return EXIT_FAILURE;
    }

    Graph g(directed == 1 ? true : false);

    //-------------- Node/Edge Input --------------//

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

    cout << endl;
    cout << "Input Starting Node ID for algorithm (Prim's and Kruskal's) : ";
    cin >> startNodeID;

    cout << endl << endl << endl;

    //-------------- Prim's Algorithm --------------//

    Graph prim_mst(true);

    unordered_set<int> visited;

    // Priority Queue need a custom function to sort all weights since iPairs structure is <destination, weight>
    priority_queue<prim_edge, vector<prim_edge>, function<bool(const prim_edge&, const prim_edge&)>> minHeap
    (
        [](const prim_edge& a, const prim_edge& b) {
            float weightA = get<2>(a), weightB = get<2>(b);
            int destA = get<1>(a), destB = get<1>(b);
            return (weightA == weightB) ? (destA > destB) : (weightA > weightB);
        }
    );

    float totalCost = 0.0;

    cout << "+-----------------------------+" << endl;
    cout << "|      Prim's Algorithm       |" << endl;
    cout << "+-----------------------------+\n" << endl;

    Node startNode = g.getNode(startNodeID);

    if (startNode == NULL_NODE) {
        cout << "Node {" << startNodeID << "} not found, abort." << endl;
        return 1;
    }

    prim_mst.addNode(startNode.id, startNode.nodeLabel);
    visited.insert(startNodeID);

    for (const auto& edge : startNode.getEdges()) {
        minHeap.push({startNodeID, edge.first, edge.second}); // <Source, Destination, Weight>
    }

    // Loop until all edges is evaluated
    while (!minHeap.empty()) {
        auto [source, dest, weight] = minHeap.top();
        minHeap.pop();

        // If node is visited, skip
        if (visited.count(dest)) {
            continue;
        }

        // Insert current node to visited list
        visited.insert(dest);

        // Get the current node object; 
        const Node& currentNode = g.getNode(dest);
        prim_mst.addNode(currentNode.id, currentNode.nodeLabel);

        prim_mst.addEdge(source, dest, weight);

        totalCost += weight;

        for (const auto& edge : currentNode.getEdges()) {
            if (!visited.count(edge.first)) { // Prevent cycle
                minHeap.push({currentNode.id, edge.first, edge.second});
            }
        }
    }

    // Represent Prim's Algorithm Minimum Spanning Tree
    prim_mst.displayGraph();

    cout << "------------------------------" << endl;
    cout << "Total Weight : " << totalCost;
    cout << endl << endl << endl;

    //-------------- Kruskal's Algorithm --------------//

    Graph kruskal_mst(true);
    int n = 0;
    float kruskal_cost = 0.0;

    priority_queue<prim_edge, vector<prim_edge>, function<bool(const prim_edge&, const prim_edge&)>> sortedEdges
    (
        [](const prim_edge& a, const prim_edge& b) {
            return get<2>(a) > get<2>(b);
        }
    );

    cout << "+-----------------------------+" << endl;
    cout << "|    Kruskal's Algorithm      |" << endl;
    cout << "+-----------------------------+\n" << endl;

    for (auto [id, node] : g.getNodes()) {
        for (auto edge : node.getEdges()) {
            sortedEdges.push({id, edge.first, edge.second});
            n++;
        }
        kruskal_mst.addNode(node.id, node.nodeLabel);
    }

    for (int i = 0; i < n; i++) {
        auto [source, dest, weight] = sortedEdges.top();
        sortedEdges.pop();

        kruskal_mst.addEdge(source, dest, weight);

        if (kruskal_mst.hasCycle()) {
            kruskal_mst.removeEdge(source, dest);
        } else {
            kruskal_cost += weight;
        }
    }

    kruskal_mst.displayGraph();

    cout << "------------------------------" << endl;
    cout << "Total Weight : " << kruskal_cost;
    cout << endl << endl << endl;

    return EXIT_SUCCESS;
}



/* ################################################################################## */
/* # __  __      _   _               _   ____        __ _       _ _   _             # */
/* #|  \/  | ___| |_| |__   ___   __| | |  _ \  ___ / _(_)_ __ (_) |_(_) ___  _ __  # */
/* #| |\/| |/ _ \ __| '_ \ / _ \ / _` | | | | |/ _ \ |_| | '_ \| | __| |/ _ \| '_ \ # */
/* #| |  | |  __/ |_| | | | (_) | (_| | | |_| |  __/  _| | | | | | |_| | (_) | | | |# */
/* #|_|  |_|\___|\__|_| |_|\___/ \__,_| |____/ \___|_| |_|_| |_|_|\__|_|\___/|_| |_|# */
/* ################################################################################## */

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

bool Graph::isDirected() {
    return directed;
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

const Node& Graph::getNode(int id) {
    if (nodes.find(id) != nodes.end()) {
        return nodes.at(id);
    }

    return NULL_NODE;
}

const unordered_map<int, Node>& Graph::getNodes() {
    return nodes;
}