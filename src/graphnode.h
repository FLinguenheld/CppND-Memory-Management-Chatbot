#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include "chatbot.h"
#include <memory>
#include <string>
#include <vector>

// forward declarations
class GraphEdge;

class GraphNode {
private:
  //// NOTE: STUDENT CODE
  ////

  // data handles (owned)
  std::vector<std::unique_ptr<GraphEdge>> _childEdges; // edges to subsequent nodes

  // data handles (not owned)
  std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes
  ChatBot _chatBot;                      // Change ptr to a local var

  // proprietary members
  int _id;
  std::vector<std::string> _answers;

public:
  // constructor / destructor
  GraphNode(int id);
  ~GraphNode();

  // getter / setter
  int GetID() { return _id; }
  int GetNumberOfChildEdges() { return _childEdges.size(); }
  GraphEdge *GetChildEdgeAtIndex(int index);
  std::vector<std::string> GetAnswers() { return _answers; }
  int GetNumberOfParents() { return _parentEdges.size(); }

  // proprietary functions
  void AddToken(std::string token); // add answers to list
  void AddEdgeToParentNode(GraphEdge *edge);
  void AddEdgeToChildNode(std::unique_ptr<GraphEdge> &edge);

  //// NOTE: STUDENT CODE
  ////

  void MoveChatbotHere(ChatBot &chatbot);
  void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */
