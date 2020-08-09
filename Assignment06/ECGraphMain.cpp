#include <iostream>
#include "ECGraph.h"

using namespace std;

int main(void) {

    ECGraphNode *testNodeA = new ECGraphNode(22145);
    ECGraphNode *testNodeB = new ECGraphNode(3174);
    ECGraphNode *testNodeC = new ECGraphNode(3345);
    ECGraphNode *testNodeD = new ECGraphNode(7162);
    
    ECGraph* graph = new ECGraph();
    graph->AddEdge(testNodeA, testNodeB);
    graph->AddEdge(testNodeA, testNodeB);
    graph->AddEdge(testNodeA, testNodeC);
    graph->AddEdge(testNodeC, testNodeD);
    
    cout << "Number of Nodes: " << graph->GetNumofNodes() << endl;;
    cout << "Number of Edges: " << graph->GetNumofEdges() << endl;


    return 0;
}