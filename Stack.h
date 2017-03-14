//Sanil Hattangadi, 3/14/17
//Stack methhods and variables
#include "Node.h"

using namespace std;

class Stack{
 public:
  //methods 
  Stack();//constructor
  Node* pop();//takes top node, looks at, and removes
  Node* peek();//looks at top node
  void push(Node* newNode);//takes top node and pushes it
  ~Stack();//deconstructor
 private:
  //variables
  Node* head;
};
