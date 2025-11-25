#include "graph.h"
#include <algorithm>

//Constructor implementations
Graph::Graph()
    : nodes{}, edges{}, startingNode(nullptr), goalNode(nullptr) {}

Graph::Graph(std::vector<Node*> nodes, std::vector<Edge*> edges, Node* startingNode, Node* goalNode)
    : nodes(nodes), edges(edges), startingNode(startingNode), goalNode(goalNode) {}

//Getter implementations
const std::vector<Node*> Graph::getNodes() const {
    return this->nodes;
}
const std::vector<Edge*> Graph::getEdges() const {
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
    Node* A = edge->getNodes()[0];
    Node* B = edge->getNodes()[1];

    for (Edge* edgeInGraph : this->edges) {
        Node* graphNodeA = edgeInGraph->getNodes()[0];
        Node* graphNodeB = edgeInGraph->getNodes()[1];

        bool sameOrder = (A == graphNodeA && B == graphNodeB);
        bool reverseOrder = (A == graphNodeB && B == graphNodeA);

        if (sameOrder || reverseOrder) {
            throw std::invalid_argument("Graph already contains the given edge.");
        }
    }

    this->edges.push_back(edge);
}
void Graph::removeNode(Node* node) {

}
void Graph::removeEdge(Edge* edge) {

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

}

//Helper implementations
std::string Graph::toString() const {

}



