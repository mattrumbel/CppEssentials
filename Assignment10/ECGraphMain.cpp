#include <iostream>
#include "ECGraph.h"

using namespace std;

int main(void) {

    ECGraphNode *testNodeA = new ECGraphNode(22145);
    ECGraphNode *testNodeB = new ECGraphNode(3174);
    ECGraphNode *testNodeC = new ECGraphNode(1227);
    ECGraphNode *testNodeD = new ECGraphNode(4162);

    ECGraph* graph = new ECGraph();
    graph->AddEdge(testNodeA, testNodeB);
    graph->AddEdge(testNodeA, testNodeC);

    // cout << testNodeD->IsLocked() << " != " << 1 << endl;
    //  EXPECT_NE(testNodeD->IsLocked(), 1);
    
    *testNodeD = *testNodeA;
    // cout << testNodeD->IsLocked() << " = " << 1 << endl;
    // EXPECT_EQ(testNodeD->IsLocked(), 1);

    // cout << testNodeD->IsLocked() << " == " << testNodeA->IsLocked() << endl;
    //EXPECT_EQ(testNodeD->IsLocked(), testNodeA->IsLocked());
    
    vector<const ECGraphNode*> edgesA = testNodeA->GetEdgeList();
    vector<const ECGraphNode*> edgesD = testNodeD->GetEdgeList();
    // cout << edgesD.size() << " expect that " << 2 << endl;
    // EXPECT_THAT(edgesD.size(), 2);
    for(int i = 0; i < edgesA.size(); ++i)
        {
        // EXPECT_EQ(edgesA[i]->GetId(), edgesD[i]->GetId());
        cout << edgesA[i]->GetId() << " == " << edgesD[i]->GetId() << endl;
        cout << &(*edgesA[i]) << " != " << &(*edgesD[i]) << endl;
        // EXPECT_NE(&(*edgesA[i]), &(*edgesD[i]));
        }
    delete graph;
    delete testNodeD;

    return 0;
}