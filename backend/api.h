#pragma once
#include "graph.h"


#ifdef _WIN32
#define API __declspec(dllexport)
#else
#define API
#endif

extern "C" {

API Graph* CreateGraph();
API void DestroyGraph(Graph* graph);

API void Graph_AddNode(Graph* graph, int id, const char* name, double latitude, double longitude);
API void Graph_AddEdge(Graph* graph, int nodeA_ID, int nodeB_ID);

API void Graph_SetStart(Graph* graph, int nodeID);
API void Graph_SetGoal(Graph* graph, int nodeID);

API int Node_GetID(Node* node);
API double Node_GetLatitude(Node* node);
API double Node_GetLongitude(Node* node);
API const char* Node_GetName(Node* node);

API Node** Graph_CalculateShortestPath(Graph* graph, int* outLength);
}
