#include <iostream>
#include "ECGraph.h"

using namespace std;

int main(void) {

    cout << "Initializing Nodes" << endl;
    ECGraphNode *testNodeA = new ECGraphNode(0);
    ECGraphNode *testNodeB = new ECGraphNode(1);
    ECGraphNode *testNodeC = new ECGraphNode(3);
    ECGraphNode *testNodeD = new ECGraphNode(2);

    ECGraphNode *testNodeE = new ECGraphNode(10);
    ECGraphNode *testNodeF = new ECGraphNode(11);

    cout << "\nCreating Graph" << endl;
    ECGraph* graph = new ECGraph();
    
    cout << "\nAdding Edges" << endl;
    graph->AddEdge(testNodeA, testNodeB);
    graph->AddEdge(testNodeA, testNodeC);
    graph->AddEdge(testNodeA, testNodeD);

    graph->AddEdge(testNodeB, testNodeE);
    graph->AddEdge(testNodeE, testNodeF);
    graph->AddEdge(testNodeE, testNodeC);
    graph->AddEdge(testNodeC, testNodeD);
    graph->AddEdge(testNodeD, testNodeF);
    graph->AddEdge(testNodeF, testNodeA);


    cout << "\nPerforming DFS" << endl;
    vector<int> visited_nodes;
    vector<int> loop_tracker;
    const ECGraphNode *testNodeA_const = const_cast<ECGraphNode *>(testNodeA);
    graph->DFS(testNodeA_const, visited_nodes, loop_tracker);
    for (auto node : visited_nodes) cout << node << endl;

    return 0;
}