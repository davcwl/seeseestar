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
    for (Edge* edgeInGraph : this->edges) {
        for (Node* node : edge->getNodes()) {

        }
    }

}
void Graph::removeNode(Node* node) {

}
void Graph::removeEdge(Edge* edge) {

}
Node* Graph::findNodeById(int id) const {

}
Edge* Graph::findEdge(Node* nodeA, Node* nodeB) const {

}
double Graph::getDistance(Node* nodeA, Node* nodeB) const {

}

std::vector<Node*> Graph::shortestPath(Node* start, Node* end) const {

}

//Helper implementations
std::string Graph::toString() const {

}



