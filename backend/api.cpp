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

    API int Node_GetID(Node* node) {
        return node->getId();
    }

    API double Node_GetLatitude(Node* node) {
        return node->getLatitude();
    }

    API double Node_GetLongitude(Node* node) {
        return node->getLongitude();
    }

    API const char* Node_GetName(Node* node) {
        return node->getName().c_str();
    }
}
