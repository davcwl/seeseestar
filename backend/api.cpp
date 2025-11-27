#include "api.h"
#include "graph.h"

extern "C" {

API Graph* CreateGraph() {
    return new Graph();
}

API void DestroyGraph(Graph* graph) {
    delete graph;
}

API void Graph_AddNode(Graph* graph, int id, const char* name, double latitude, double longitude) {
    graph->addNode(new Node(id, name, latitude, longitude));
}

API void Graph_AddEdge(Graph* graph, int nodeA_ID, int nodeB_ID) {
    Node* nodeA = graph->findNodeById(nodeA_ID);
    Node* nodeB = graph->findNodeById(nodeB_ID);
    graph->addEdge(new Edge(nodeA, nodeB));
}

API void Graph_SetStart(Graph* graph, int nodeID) {
    graph->setStartingNode(graph->findNodeById(nodeID));
}

API void Graph_SetGoal(Graph* graph, int nodeID) {
    graph->setGoalNode(graph->findNodeById(nodeID));
}

//Gets nodes of shortest path, then makes a C style array copy.
API Node** Graph_CalculateShortestPath(Graph* graph, int* outLength) {

    auto nodesShortestPath = graph->calculateShortestPath();
    *outLength = nodesShortestPath.size();

    Node** result = new Node*[nodesShortestPath.size()];

    for (int i = 0; i < nodesShortestPath.size(); ++i)
        result[i] = nodesShortestPath[i];

    return result;
}
}
