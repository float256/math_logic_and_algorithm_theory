#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include <functional>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

template <typename NodeDataType>
class Graph
{
private:
	std::unordered_map<int, GraphNode<NodeDataType>> AllGraphNodes;
	bool IsDeleteAllNodesAfterGraphDeleting = false;

public:
	bool IsAlreadyAdded(int nodeNumber)
	{
		if (this->AllGraphNodes.find(nodeNumber) != this->AllGraphNodes.end())
		{
			return true;
		}
		return false;
	}

	void AddNode(int nodeNumber, NodeDataType nodeData)
	{
		if (this->IsAlreadyAdded(nodeNumber))
		{
			throw std::invalid_argument("The node with selected number has already been added.");
		}
		GraphNode<NodeDataType> newNode;
		newNode.NodeData = nodeData;
		newNode.NodeNumber = nodeNumber;
		this->AllGraphNodes.insert({ nodeNumber, newNode });
	}

	void RemoveNode(int nodeNumber)
	{
		if (this->IsAlreadyAdded(nodeNumber))
		{
			auto position = this->AllGraphNodes.find(nodeNumber);
			if (position != this->AllGraphNodes.end())
			{
				this->AllGraphNodes.erase(position);
			}
		}
	}

	GraphNode<NodeDataType>& GetNode(int nodeNumber)
	{
		if (this->IsAlreadyAdded(nodeNumber))
		{
			return this->AllGraphNodes.at(nodeNumber);
		}
		else
		{
			throw std::invalid_argument("Node with selected name doesn't exist.");
		}
	}

	std::vector<int> GetAllNodeNumbers()
	{
		std::vector<int> allNodeNames;
		for (std::pair<std::string, GraphNode<NodeDataType>> &element : this->AllGraphNodes)
		{
			allNodeNames.push_back(element.first);
		}
		return allNodeNames;
	}

	~Graph()
	{
		if (this->IsDeleteAllNodesAfterGraphDeleting)
		{
			this->AllGraphNodes.clear();
		}
	}

	Graph(bool isDeleteAllNodesAfterGraphDeleting = false)
	{
		this->IsDeleteAllNodesAfterGraphDeleting = isDeleteAllNodesAfterGraphDeleting;
	}
};

#endif