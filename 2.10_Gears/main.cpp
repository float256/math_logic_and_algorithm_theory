#include "Graph/Graph.h"
#include <algorithm>
#include <exception>
#include <iostream>
#include <queue>

enum class GearState
{
	Immovable,
	Clockwise,
	Anticlockwise
};

void ReadLine(std::istream& inputStream)
{
	std::string lineReminder;
	std::getline(inputStream, lineReminder);
}

template <typename T>
void EraseItem(std::vector<T>& vector, T itemForErasing)
{
	vector.erase(std::remove(vector.begin(), vector.end(), itemForErasing), vector.end());
}

void ReadGearsGraph(std::istream& inputStream, Graph<GearState>& gearsGraph)
{
	int numberOfGears, numberOfPairs;
	std::cin >> numberOfGears >> numberOfPairs;
	ReadLine(std::cin);
	for (size_t currNodeName = 1; currNodeName <= numberOfGears; ++currNodeName)
	{
		gearsGraph.AddNode(currNodeName, GearState::Immovable);
	}

	for (size_t i = 0; i < numberOfPairs; ++i)
	{
		int firstNodeNumber, secondNodeNumber;
		inputStream >> firstNodeNumber >> secondNodeNumber;

		GraphNode<GearState>& firstNode = gearsGraph.GetNode(firstNodeNumber);
		GraphNode<GearState>& secondNode = gearsGraph.GetNode(secondNodeNumber);

		firstNode.AddConnection(secondNode);
		ReadLine(std::cin);
	}
}

void StartGearsMovement(Graph<GearState>& gearsGraph, bool& isBreak)
{
	std::queue<int> consideredNodesQueue;
	isBreak = false;
	std::vector<int> unvisitedNodeNumbers = gearsGraph.GetAllNodeNumbers();

	gearsGraph.GetNode(1).NodeData = GearState::Clockwise;
	consideredNodesQueue.push(1);
	std::sort(unvisitedNodeNumbers.begin(), unvisitedNodeNumbers.end());
	while (!isBreak && !consideredNodesQueue.empty())
	{
		GraphNode<GearState> selectedNode = gearsGraph.GetNode(consideredNodesQueue.front());
		consideredNodesQueue.pop();
		EraseItem<int>(unvisitedNodeNumbers, selectedNode.NodeNumber);
		for (auto& currNodeNumber : selectedNode.GetAllConnections())
		{
			GraphNode<GearState>& currNode = gearsGraph.GetNode(currNodeNumber);
			isBreak = (selectedNode.NodeData != GearState::Immovable) && (selectedNode.NodeData == currNode.NodeData);
			if (isBreak)
			{
				break;
			}

			if (selectedNode.NodeData == GearState::Clockwise)
			{
				currNode.NodeData = GearState::Anticlockwise;
			}
			else if (selectedNode.NodeData == GearState::Anticlockwise)
			{
				currNode.NodeData = GearState::Clockwise;
			}

			if (std::binary_search(unvisitedNodeNumbers.begin(), unvisitedNodeNumbers.end(), currNode.NodeNumber))
			{
				consideredNodesQueue.push(currNode.NodeNumber);
			}
		}
	}
}

void PrintGearsGraph(std::ostream& outputStream, const Graph<GearState>& gearsGraph)
{
	std::vector<int> allNodeNumbers = gearsGraph.GetAllNodeNumbers();
	std::sort(allNodeNumbers.begin(), allNodeNumbers.end());
	for (auto currNumber : allNodeNumbers)
	{
		switch (gearsGraph.GetNodeData(currNumber))
		{
		case GearState::Clockwise:
			outputStream << "clockwise" << std::endl;
			break;
		case GearState::Anticlockwise:
			outputStream << "unclockwise" << std::endl;
			break;
		case GearState::Immovable:
			outputStream << "immovable" << std::endl;
			break;
		}
	}
}

int main(int, char**)
{
	Graph<GearState> gearsGraph(false);
	try
	{
		bool isBreak = false;
		ReadGearsGraph(std::cin, gearsGraph);
		StartGearsMovement(gearsGraph, isBreak);
		if (isBreak)
		{
			std::cout << "break";
		}
		else
		{
			PrintGearsGraph(std::cout, gearsGraph);
		}
		return 0;
	}
	catch (std::exception& exception)
	{
		std::cout << "ERROR: " << exception.what() << std::endl;
		return 1;
	}
}
