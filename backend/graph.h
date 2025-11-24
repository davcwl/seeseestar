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

    Node* startingNode;
    Node* goalNode;

public:

    //Getters
    const std::vector<Node*> getNodes() const;
    const std::vector<Edge*> getEdges() const;
    Node* getStartingNode() const;
    Node* getGoalNode() const;
    //Setters
    void setNodes(std::vector<Node*> nodes);
    void setEdges(std::vector<Edge*> edges);
    void setStartingNode(Node* node);
    void setGoalNode(Node* node);

    //Methods
    void addNode(Node* node);
    void addEdge(Edge* edge);
    void removeNode(Node* node);
    void removeEdge(Edge* edge);
    Node* findNodeById(int id) const;
    Edge* findEdge(Node* nodeA, Node* nodeB) const;

    //Helpers
    std::string toString() const;


    double getDistance(Node* nodeA, Node* nodeB) const;

    std::vector<Node*> shortestPath(Node* start, Node* end) const;

    Graph();
    Graph(std::vector<Node*> nodes, std::vector<Edge*> edges, Node* startingNode = nullptr, Node* goalNode = nullptr);
};

#endif // GRAPH_H
