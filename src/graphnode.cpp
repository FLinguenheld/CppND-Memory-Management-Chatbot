#include "graphnode.h"
#include "graphedge.h"

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode() {
  //// NOTE: STUDENT CODE : Remove it
  ////

  // delete _chatBot;

  ////
  //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) { _parentEdges.emplace_back(edge); }

void GraphNode::AddEdgeToChildNode(GraphEdge *edge) { _childEdges.emplace_back(edge); }

//// TODO: STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot) {
  _chatBot = chatbot;
  _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(_chatBot);
  _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// TODO: STUDENT CODE
  ////

  return _childEdges[index].get();

  ////
  //// EOF STUDENT CODE
}
