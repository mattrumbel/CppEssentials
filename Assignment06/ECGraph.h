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

//*****************************************************************
// graph node class

class ECGraphNode
{
public:
    ECGraphNode(int nid);       							// nid: a distinct id for each node
    ~ECGraphNode();											// destructor
    int GetId() const;         								// return the node id    
	void SetEdge(const ECGraphNode *pNode);					// set an edge by passing a node to serve as destination of edge
	std::vector<const ECGraphNode *> GetEdgeList() const;	// return a vector of pointers to all destination nodes    
private:
	int nodeId;												// unique numerical id 
	std::vector<const ECGraphNode *> edgeList;				// vector of nodes representing destinations connected by edge

};


//*****************************************************************
// graph class
// assume the graph is directed

class ECGraph
{
public:
    ECGraph();
    ~ECGraph();                                 	// make sure clean up property

    // basic graph editing functions
    void AddNode( ECGraphNode *pNode );         							// add a node
    void AddEdge( ECGraphNode *pNode1, const ECGraphNode *pNode2 );         // add an edge

    // basic graph access functions
    int GetNumofNodes() const;                  	// return total number of nodes in graph
    int GetNumofEdges() const;   					// return total number of edges in graph
	ECGraphNode* GetNodeById(const int nid) const;	// return node object which has ID nid
	std::vector<int> GetAllNodeIds() const;			// return a vector<int> of all node ids present in graph (no duplicates)

private:
    // private methods go here
	
	// private data members go here
    int total_edges = 0;
    std::vector<const ECGraphNode *> nodeList;
};


#endif /* ECGraph_h */
