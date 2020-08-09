//
//  ECGraph.h
//  
//
//  Created by Neil Malik 2/10/2020.
//
//

#ifndef ECGraph_h
#define ECGraph_h

#include <vector>
#include <set>

//*****************************************************************
// graph node class

class ECGraphNode
{
public:
    ECGraphNode(int nid);       							// nid: a distinct id for each node
    ~ECGraphNode();											// destructor
	ECGraphNode(const ECGraphNode &rhs);
	
	bool operator== (const ECGraphNode &n2) const;
	bool operator!= (const ECGraphNode &n2) const;
	bool operator< (const ECGraphNode &n2) const;
	bool operator> (const ECGraphNode &n2) const;
	ECGraphNode& operator= (const ECGraphNode &n2);

	void RemoveEdge(const ECGraphNode *pNode);
	
    int GetId() const;         								// return the node id 
	bool IsLocked() const;									// return if node is owned or not
	void ClearEdges();
	void Lock(const bool &status);
	void SetEdge(const ECGraphNode *pNode);					// set an edge by passing a node to serve as destination of edge
	std::vector<const ECGraphNode *> GetEdgeList() const;	// return a vector of pointers to all destination nodes    
private:
	bool locked;
	int nodeId;												// unique numerical id 
	std::vector<const ECGraphNode *> edgeList;				// vector of nodes representing destinations connected by edge

};

bool node_lte_compare (const ECGraphNode *n1, const ECGraphNode *n2);


//*****************************************************************
// graph class
// assume the graph is directed
class ECGraph
{
public:
    ECGraph();
    ~ECGraph();                                 	// make sure clean up property

	ECGraph(const ECGraph &rhs);
	ECGraph& operator= (const ECGraph &rhs);
	bool operator== (const ECGraph &g2) const;

    // basic graph editing functions
    bool AddNode( ECGraphNode *pNode );         							// add a node
    void AddEdge( ECGraphNode *pNode1, const ECGraphNode *pNode2 );         // add an edge
	ECGraphNode* Unlink(ECGraphNode* pNode);

    // basic graph access functions
    int GetNumofNodes() const;                  	// return total number of nodes in graph
    int GetNumofEdges() const;   					// return total number of edges in graph
	ECGraphNode* GetNodeById(const int nid) const;	// return node object which has ID nid
	std::vector<int> GetAllNodeIds() const;			// return a vector<int> of all node ids present in graph (no duplicates)
	
	void DFS(const ECGraphNode *pNodeStart, std::vector<int> &listNodesInDFS, std::vector<int> &loopTrack);


private:
    // private methods go here
	
	// private data members go here
	std::set<ECGraphNode*> nodeList;

};


#endif /* ECGraph_h */
