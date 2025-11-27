#include "graph.h"
#include <algorithm>
#include <stdexcept>
#include <queue>
#include <unordered_map>
#include <cmath>

//Constructor implementations
Graph::Graph()
    : nodes{}, edges{}, startingNode(nullptr), goalNode(nullptr) {}

Graph::Graph(std::vector<Node*> nodes, std::vector<Edge*> edges, Node* startingNode, Node* goalNode)
    : nodes(nodes), edges(edges), startingNode(startingNode), goalNode(goalNode) {}

//Deconstructor implementation
Graph::~Graph() {
    for (Edge* edge : this->edges) {
        delete edge;
    }
    for (Node* node : this->nodes) {
        delete node;
    }
}

//Getter implementations
const std::vector<Node*>& Graph::getNodes() const {
    return this->nodes;
}
const std::vector<Edge*>& Graph::getEdges() const {
    return this->edges;
}
Node* Graph::getStartingNode() const {
    return this->startingNode;
}
Node* Graph::getGoalNode() const {
    return this->goalNode;
}

//Setter implementations
void Graph::setNodes(std::vector<Node*> nodes) {
    this->nodes = nodes;
}
void Graph::setEdges(std::vector<Edge*> edges) {
    this->edges = edges;
}
void Graph::setStartingNode(Node* node) {
    this->startingNode = node;
}
void Graph::setGoalNode(Node* node) {
    this->goalNode = node;
}

//Method implementations
void Graph::addNode(Node* node) {
    auto it = std::find(this->nodes.begin(), this->nodes.end(), node);
    if (it != this->nodes.end()) {
        throw std::invalid_argument("Graph can't contain duplicate nodes.");
    } else {
        this->nodes.push_back(node);
    }
}
void Graph::addEdge(Edge* edge) {
    Node* nodeA = edge->getNodes()[0];
    Node* nodeB = edge->getNodes()[1];

    for (Edge* edgeInGraph : this->edges) {
        Node* graphNodeA = edgeInGraph->getNodes()[0];
        Node* graphNodeB = edgeInGraph->getNodes()[1];

        bool sameOrder = (nodeA == graphNodeA && nodeB == graphNodeB);
        bool reverseOrder = (nodeA == graphNodeB && nodeB == graphNodeA);

        if (sameOrder || reverseOrder) {
            throw std::invalid_argument("Graph already contains the given edge.");
        }
    }

    this->edges.push_back(edge);
}

std::vector<Edge*> Graph::getConnectedEdges(Node* node) const {
    std::vector<Edge*> connectedEdges;

    for (Edge* edge : this->edges) {
        Node* nodeA = edge->getNodes()[0];
        Node* nodeB = edge->getNodes()[1];

        if (nodeA == node || nodeB == node) {
            connectedEdges.push_back(edge);
        }
    }

    return connectedEdges;
}

void Graph::removeNode(Node* node) {
    if (!node) return;

    //Remove all edges connected
    std::vector<Edge*> connected = getConnectedEdges(node);
    for (Edge* edge : connected) {
        removeEdge(edge);
    }

    //Remove from this->nodes
    auto it = std::find(this->nodes.begin(), this->nodes.end(), node);
    if (it != this->nodes.end()) {
        this->nodes.erase(it);
    }

    if (startingNode == node) startingNode = nullptr;
    if (goalNode == node)     goalNode = nullptr;

    delete node;
}
void Graph::removeEdge(Edge* edge) {
    if (!edge) return;

    auto it = std::find(this->edges.begin(), this->edges.end(), edge);
    if (it != this->edges.end()) {
        this->edges.erase(it);
        delete edge;
    }
}
Node* Graph::findNodeById(int id) const {
    for (Node* node : this->nodes) {
        if (node->getId() == id) {
            return node;
        }
    }
    return nullptr;
}
Edge* Graph::findEdge(Node* nodeA, Node* nodeB) const {
    for (Edge* edge : this->edges) {
        auto nodes = edge->getNodes();
        if ((nodes[0] == nodeA && nodes[1] == nodeB) ||
            (nodes[0] == nodeB && nodes[1] == nodeA)) {
            return edge;
        }
    }
    return nullptr;
}
double Graph::heuristic(Node* node) const {
    if (!this->goalNode) return 0.0;
    return Edge::getEuclideanDistance(node, this->goalNode);
}

std::vector<Node*> Graph::calculateShortestPath() const {
    //If there is no start or goal
    if (!startingNode || !goalNode) {
        return {};
    }

    //Frontier elements
    using FrontierItem = std::pair<double, Node*>;
    //Priority queue comparison lambda
    auto comparator = [](const FrontierItem& a, const FrontierItem& b) {
        return a.first > b.first;
    };
    //Priority queue
    std::priority_queue<FrontierItem, std::vector<FrontierItem>, decltype(comparator)> frontier(comparator);

    //Cost to reach "node" from startingNode
    std::unordered_map<Node*, double> gScore;

    //fScore of a node is the total estimated cost (g + h). Where g is the total weight and h is the heuristic.
    std::unordered_map<Node*, double> fScore;

    //currently best known path
    std::unordered_map<Node*, Node*> cameFrom;

    //Initialize maps
    for (Node* node : this->nodes) {
        gScore[node] = INFINITY;
        fScore[node] = INFINITY;
        cameFrom[node] = nullptr;
    }

    gScore[startingNode] = 0.0;
    fScore[startingNode] = heuristic(startingNode);

    //Start search
    frontier.push({fScore[startingNode], startingNode});

    while (!frontier.empty()) {
        Node* currentNode = frontier.top().second;
        frontier.pop();

        // Reached goal
        if (currentNode == goalNode) {
            break;
        }

        for (auto& [neighbour, weight] : getNeighbours(currentNode)) {

            double tentative_g = gScore[currentNode] + weight;

            if (tentative_g < gScore[neighbour]) {
                cameFrom[neighbour] = currentNode;
                gScore[neighbour] = tentative_g;
                fScore[neighbour] = tentative_g + heuristic(neighbour);

                frontier.push({fScore[neighbour], neighbour});
            }
        }
    }

    //If there is no path
    if (cameFrom[goalNode] == nullptr && startingNode != goalNode) {
        return {}; // no path
    }

    //Reconstruct path
    std::vector<Node*> shortestPath;
    Node* curr = goalNode;

    while (curr) {
        shortestPath.push_back(curr);
        if (curr == startingNode) break;
        curr = cameFrom[curr];
    }

    std::reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}

std::vector<std::pair<Node*, double>> Graph::getNeighbours(Node* node) const {
    std::vector<std::pair<Node*, double>> neighbours;

    for (Edge* edge : getConnectedEdges(node)) {
        Node* nodeA = edge->getNodes()[0];
        Node* nodeB = edge->getNodes()[1];

        if (nodeA == node) {
            neighbours.emplace_back(nodeB, edge->getWeight());
        }
        else if (nodeB == node) {
            neighbours.emplace_back(nodeA, edge->getWeight());
        }
    }

    return neighbours;
}

//Helper implementations
std::string Graph::toString() const {
    return "";
}



