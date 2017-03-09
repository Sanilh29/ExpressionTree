#include "Node.h"

using namespace std;

class Stack{
 public:
  Stack();
  Node* pop();
  Node* peek();
  void push(Node* newNode);
  ~Stack();
 private:
  Node* head;
};
