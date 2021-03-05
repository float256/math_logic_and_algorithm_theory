//
// Created by user on 05.03.2021.
//

#ifndef GEARS_GRAPHNODE_H
#define GEARS_GRAPHNODE_H

#include <unordered_map>
#include <vector>

template <typename NodeDataType>
class GraphNode
{
private:
	std::unordered_map<int, std::reference_wrapper<GraphNode<NodeDataType>>> _nodeConnections;

public:
	NodeDataType NodeData = NodeDataType();
	int NodeNumber;

	bool IsConnected(const GraphNode<NodeDataType>& graphNode)
	{
		auto position = this->_nodeConnections.find(graphNode.NodeNumber);
		if (position != this->_nodeConnections.end())
		{
			return true;
		}
		return false;
	}

	void AddConnection(GraphNode<NodeDataType>& graphNode)
	{
		if (!this->IsConnected(graphNode))
		{
			this->_nodeConnections.insert({ graphNode.NodeNumber, graphNode });
			graphNode.AddConnection(*this);
		}
	}

	std::vector<int> GetAllConnections()
	{
		std::vector<int> allConnections;
		for (std::pair<std::string, GraphNode<NodeDataType>>& element : this->_nodeConnections)
		{
			allConnections.push_back(element.first);
		}
		return allConnections;
	}

	void RemoveConnection(GraphNode<NodeDataType>& graphNode)
	{
		auto position = this->_nodeConnections.find(graphNode.NodeNumber);
		if (position != this->_nodeConnections.end())
		{
			this->_nodeConnections.erase(position->first());
		}
	}
};

#endif //GEARS_GRAPHNODE_H
