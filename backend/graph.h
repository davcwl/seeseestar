#ifndef GRAPH_H
#define GRAPH_H

#include "SeeSeeStar_global.h"
#include <vector>
#include "node.h"
#include "edge.h"

class SEESEESTAR_EXPORT Graph
{
private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;

public:

    void addNode(Node* node);
    void addEdge(Edge* edge);

    void removeNode(Node* node);
    void removeEdge(Edge* edge);

    Node* findNodeById(int id) const;

    std::string toString() const;
    Edge* findEdge(Node* nodeA, Node* nodeB) const;

    double getDistance(Node* nodeA, Node* nodeB) const;

    std::vector<Node*> shortestPath(Node* start, Node* end) const;

    Graph();
};

#endif // GRAPH_H
