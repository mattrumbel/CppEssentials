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

ECGraphNode::ECGraphNode(const ECGraphNode &rhs) {
	locked = rhs.IsLocked();
	nodeId = rhs.GetId();

	edgeList.clear();
	vector <int> rhs_node_ids;
	for (const ECGraphNode* node : rhs.GetEdgeList()) rhs_node_ids.push_back(node->GetId());
	for (int node_id : rhs_node_ids) edgeList.push_back(new ECGraphNode(node_id));
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

bool ECGraphNode::operator> (const ECGraphNode &n2) const {
	if (nodeId > n2.nodeId) return true;
	else return false;
}

ECGraphNode& ECGraphNode::operator=(const ECGraphNode &n2) {
	locked = n2.IsLocked();
	nodeId = n2.GetId();
	edgeList.clear();
	vector <int> n2_node_ids;
	for (const ECGraphNode* node : n2.GetEdgeList()) n2_node_ids.push_back(node->GetId());
	for (int node_id : n2_node_ids) edgeList.push_back(new ECGraphNode(node_id));


	return *this;
}



bool node_lte_compare (const ECGraphNode* n1, const ECGraphNode* n2) {
	return n1->GetId() < n2->GetId();
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
	nodeList.clear();
	
}
ECGraph::ECGraph(const ECGraph &rhs) {
	for (ECGraphNode* node : rhs.nodeList) {
		ECGraphNode* node_to_insert = new ECGraphNode(*node);
		nodeList.insert(node_to_insert);
	}
}

ECGraph& ECGraph::operator=(const ECGraph &rhs) {
	if (this == &rhs) return *this;
	else {
		for (ECGraphNode* node : rhs.nodeList) {
			ECGraphNode* node_to_insert = new ECGraphNode(*node);
			nodeList.insert(node_to_insert);
		}
		return *this;
	}
}

bool ECGraph::operator== (const ECGraph &g2) const {
	vector<int> all_my_node_ids = GetAllNodeIds();
	vector<int> all_g2_node_ids = g2.GetAllNodeIds();
	if (all_my_node_ids.size() != all_g2_node_ids.size()) {
		return false;
	}

	sort(all_my_node_ids.begin(), all_my_node_ids.end());
	sort(all_g2_node_ids.begin(), all_g2_node_ids.end());

	vector <const ECGraphNode *> my_node_edge_list;
	vector <const ECGraphNode *> g2_node_edge_list;

	for (int node_i = 0; node_i < all_my_node_ids.size(); node_i++) {
		if (all_my_node_ids[node_i] != all_g2_node_ids[node_i]) {
			return false;
		}
		// Compare edges
		my_node_edge_list = GetNodeById(all_my_node_ids[node_i])->GetEdgeList();
		g2_node_edge_list = g2.GetNodeById(all_g2_node_ids[node_i])->GetEdgeList();
		if (my_node_edge_list.size() != g2_node_edge_list.size()) {
			return false;
		}
		sort(my_node_edge_list.begin(), my_node_edge_list.end(), node_lte_compare);
		sort(g2_node_edge_list.begin(), g2_node_edge_list.end(), node_lte_compare);

		for (int edge_i = 0; edge_i < my_node_edge_list.size(); edge_i++) {
			if (my_node_edge_list[edge_i]->GetId() != g2_node_edge_list[edge_i]->GetId()) {
				return false;
			}
		}
	}
	return true;
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

ECGraphNode* ECGraph::Unlink(ECGraphNode* pNode)
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
	return pNode;
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


