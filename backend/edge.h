#ifndef EDGE_H
#define EDGE_H

#include "node.h"
#include <array>
#include <string>

class Edge
{
private:
    std::array<Node*, 2> nodes;
    double weight;
public:
    //Getters
    const std::array<Node*, 2>& getNodes() const;
    double getWeight() const;

    //Setters
    void setNodes(Node* nodeA, Node* nodeB);
    void setWeight(double weight);

    //Methods
    static double getEuclideanDistance(Node* nodeA, Node* nodeB);

    //Helpers
    std::string toString() const;
    Node* getOtherNode(Node* node) const;
    bool isValidEdge() const;

    //Contructors
    Edge();
    Edge(Node* nodeA, Node* nodeB);
    Edge(Node* nodeA, Node* nodeB, double weight);
};

#endif // EDGE_H
