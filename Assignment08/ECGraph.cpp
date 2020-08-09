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
		if ((*k)->GetId() == pNode->GetId()) return;
	}
	edgeList.push_back(pNode);
}

int ECGraphNode::GetId() const
{
	//Your code goes here
	return nodeId;
}

bool ECGraphNode::IsLocked() const {
	return locked;
}

void ECGraphNode::ClearEdges() {
	edgeList.clear();
}

vector<const ECGraphNode *> ECGraphNode::GetEdgeList() const
{
	//Your code goes here
	return edgeList;
}

void ECGraphNode::RemoveEdge(const ECGraphNode *pNode) {
	for (auto k = edgeList.begin(); k != edgeList.end(); k++) {
		if ((*k)->GetId() == pNode->GetId()) {
			edgeList.erase(k);
			break;
		}
	}
}


void ECGraphNode::Lock(const bool &status) {
	locked = status;
}

bool ECGraphNode::operator== (const ECGraphNode &n2) const {
	if (nodeId == n2.nodeId) return true;
	else return false;
}

bool ECGraphNode::operator!= (const ECGraphNode &n2) const {
	if (nodeId != n2.nodeId) return true;
	else return false;
}

bool ECGraphNode::operator< (const ECGraphNode &n2) const {
	if (nodeId < n2.nodeId) return true;
	else return false;
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
bool ECGraph::AddNode( ECGraphNode *pNode )
{
	//Your code goes here
	//Remember that nodes are distinct. 
	//You cannot add a node with ID nid if a node with nid already exists in a graph
	for (auto k = nodeList.begin(); k != nodeList.end(); k++) {
		if ((*k)->GetId() == pNode->GetId()) return true;
	}

	if (!(pNode->IsLocked())) {
		nodeList.insert(pNode);
		pNode->Lock(true);
		return true;
	} else return false;
}

void ECGraph::AddEdge( ECGraphNode *pNode1, const ECGraphNode *pNode2 )
{
	//Your code goes here
	//Remember to account for adding an edge node which does not yet exist in the graph (should be supported)

	bool pNode1_added = AddNode(pNode1);
	ECGraphNode *pNode2_cp = const_cast<ECGraphNode *>(pNode2);
	bool pNode2_added = AddNode(pNode2_cp);

	if (pNode1_added && pNode2_added) pNode1->SetEdge(pNode2);
}

// basic graph access functions
int ECGraph::GetNumofNodes() const
{
	//Your code goes here
	return ((int) nodeList.size());
}

int ECGraph::GetNumofEdges() const
{
	//Your code goes here
	int total_edges = 0;
	vector<int> all_node_ids = GetAllNodeIds();
	for (int node_id: all_node_ids) total_edges += GetNodeById(node_id)->GetEdgeList().size();

	return total_edges;
}

ECGraphNode* ECGraph::GetNodeById(const int nid) const
{
	//Your code goes here
	for (auto k = nodeList.begin(); k != nodeList.end(); k++) {
		if ((*k)->GetId() == nid) return (*k);
	}
}

vector<int> ECGraph::GetAllNodeIds() const
{
	//Your code goes here
	vector<int> all_node_ids;
	for (auto k = nodeList.begin(); k != nodeList.end(); k++) all_node_ids.push_back((*k)->GetId());
	return all_node_ids;
}

void ECGraph::Unlink(ECGraphNode* pNode)
{
	//Remove node from graph and relink edges

	// Gather pNode's edges
	vector <const ECGraphNode*> edges = pNode->GetEdgeList();
	nodeList.erase(pNode);
	pNode->Lock(false);
	pNode->ClearEdges();

	// For each node in the graph
	for (ECGraphNode* node : nodeList) {
		// Check if node has edge to pNode
		for (auto edge_node : node->GetEdgeList()) {
			if (edge_node->GetId() == pNode->GetId()) {
				node->RemoveEdge(pNode);
				// Node in graph has pNode as an edge
				// Add edges to node in graph
				for (auto edge : edges) {
					AddEdge(node, edge);
				}
			}
		}
	}
}

void ECGraph::DFS(const ECGraphNode *pNodeStart, std::vector<int> &listNodesInDFS, std::vector<int> &loopTrack)
{
	//Perform depth first search on graph

	// use sort with node_lte_compare lambda function to get sorted edges
	listNodesInDFS.push_back(pNodeStart->GetId());
	loopTrack.push_back(pNodeStart->GetId());

	vector <const ECGraphNode *> edges_to_explore = pNodeStart->GetEdgeList();

	if (edges_to_explore.empty()) return;
	else sort(edges_to_explore.begin(), edges_to_explore.end(), node_lte_compare);
	
	for (const ECGraphNode *node : edges_to_explore) {
		if (find(loopTrack.begin(), loopTrack.end(), node->GetId()) != loopTrack.end()) continue;
		vector<int> currLoopTrack = loopTrack;
		DFS(node, listNodesInDFS, currLoopTrack);
	}
	return;
}


bool node_lte_compare (const ECGraphNode* n1, const ECGraphNode* n2) {
	return n1->GetId() < n2->GetId();
}

