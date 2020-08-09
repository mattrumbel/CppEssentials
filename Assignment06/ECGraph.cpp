//
//  ECGraph.cpp
//
//
//  Created by Neil Malik on 2/10/2020.

#include "ECGraph.h"
#include <vector>
#include <iostream>

using namespace std;


//*****************************************************************
// graph node class

    ECGraphNode::ECGraphNode(int nid)
	{
		//Constructor
		nodeId = nid;
	}
    ECGraphNode::~ECGraphNode()
	{
		//Destructor
	}
	void ECGraphNode::SetEdge(const ECGraphNode *pNode)
	{
		//Your code goes here
		//Store a pointer to pNode representing a directed edge from this node to pNode
		for (auto k = edgeList.begin(); k != edgeList.end(); k++) {
			if ((*k) == pNode) return;
		}
		edgeList.push_back(pNode);
	}
	
    int ECGraphNode::GetId() const
	{
		//Your code goes here
		return nodeId;
	}
	
	vector<const ECGraphNode *> ECGraphNode::GetEdgeList() const
	{
		//Your code goes here
		return edgeList;
	}

//*****************************************************************
// graph class
// assume the graph is directed

    ECGraph::ECGraph()
    {
		//Constructor
	}
    ECGraph::~ECGraph()
    {
		//Destructor
	}

    // basic graph editing functions
    void ECGraph::AddNode( ECGraphNode *pNode )
    {
		//Your code goes here
		//Remember that nodes are distinct. 
		//You cannot add a node with ID nid if a node with nid already exists in a graph
		for (auto k = nodeList.begin(); k != nodeList.end(); k++) {
			if ((*k)->GetId() == pNode->GetId()) return;
		}
		nodeList.push_back(pNode);
	}

    void ECGraph::AddEdge( ECGraphNode *pNode1, const ECGraphNode *pNode2 )
    {
		//Your code goes here
		//Remember to account for adding an edge node which does not yet exist in the graph (should be supported)
		AddNode(pNode1);
		
		ECGraphNode *pNode_hold = const_cast<ECGraphNode *>(pNode2);
		AddNode(pNode_hold);

		auto node1_edge_list = pNode1->GetEdgeList();
		for (auto k = node1_edge_list.begin(); k != node1_edge_list.end(); k++) {
			if (pNode2->GetId() == (*k)->GetId()) return;
		}

		pNode1->SetEdge(pNode2);
		total_edges += 1;
	}
	

    // basic graph access functions
    int ECGraph::GetNumofNodes() const
    {
		//Your code goes here
		int size = static_cast<int>(nodeList.size());
		return size;
	}

    int ECGraph::GetNumofEdges() const
    {
		//Your code goes here
		return total_edges;
	}
	
	ECGraphNode* ECGraph::GetNodeById(const int nid) const
	{
		//Your code goes here
		for (auto k = nodeList.begin(); k != nodeList.end(); k++) {
			if ((*k)->GetId() == nid)  return const_cast<ECGraphNode *>(*k);
		}
		throw "ID ERROR";
	}
	
	vector<int> ECGraph::GetAllNodeIds() const
	{
		//Your code goes here
		vector <int> all_node_ids;
		for (auto k = nodeList.begin(); k != nodeList.end(); k++)
			all_node_ids.push_back((*k)->GetId());
		
		return all_node_ids;
	}




