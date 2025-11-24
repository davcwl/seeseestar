#include "edge.h"
#include <cmath>
#include <sstream>

//Contructor implementations
Edge::Edge()
    //Default constructor, Edges will by default be two nullprts with a weight of INF.
    : nodes{nullptr, nullptr}, weight(INFINITY) {}

Edge::Edge(Node* nodeA, Node* nodeB)
    /*Standard constructor. Edges will store two node pointers in a std::array<Node*, 2>.
     Weight is automatically calculated as the Euclidean Distance between these two Nodes.*/
    : nodes{nodeA, nodeB}, weight(getEuclideanDistance(nodeA, nodeB)) {
    if (!isValidEdge()) {
        throw std::invalid_argument("Edge cannot connect a node to itself.");
    }
}

Edge::Edge(Node* nodeA, Node* nodeB, double weight)
    /*Standard constructor but with specific weight. Edges will store two node pointers in a std::array<Node*, 2>.
     Weight is a double type value.*/
    : nodes{nodeA, nodeB}, weight(weight) {
    if (!isValidEdge()) {
        throw std::invalid_argument("Edge cannot connect a node to itself.");
    }
}

//Setter implementations
void Edge::setNodes(Node* nodeA, Node* nodeB) {

    if (!nodeA || !nodeB || nodeA == nodeB) {
        throw std::invalid_argument("Edge cannot connect a node to itself.");
    }

    this->nodes[0] = nodeA;
    this->nodes[1] = nodeB;
}

void Edge::setWeight(double weight) {
    this->weight = weight;
}

//Getter implementations
const std::array<Node*, 2>& Edge::getNodes() const {
    return this->nodes;
}

double Edge::getWeight() const {
    return this->weight;
}

//Methods
double Edge::getEuclideanDistance(Node* nodeA, Node* nodeB) {
    double dx = nodeA->getLatitude() - nodeB->getLatitude();
    double dy = nodeA->getLongitude() - nodeB->getLongitude();
    return std::sqrt(dx*dx + dy*dy);
}

//Helper implementations
std::string Edge::toString() const {
    std::ostringstream oss;
    oss << "Edge(";
    oss << "nodeA=";

    if (nodes[0]) oss << nodes[0]->getName();
    else oss << "null";

    oss << ", nodeB=";

    if (nodes[1]) oss << nodes[1]->getName();
    else oss << "null";

    oss << ", w=" << weight << ")";

    return oss.str();
}
Node* Edge::getOtherNode(Node* node) const {
    if (node == nodes[0]) return nodes[1];
    else if (node == nodes[1]) return nodes[0];
    else return nullptr;
}

bool Edge::isValidEdge() const {
    return nodes[0] && nodes[1] && nodes[0] != nodes[1];
}
