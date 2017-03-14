//Sanil Hattangadi, 3/141/7
//stack methods and creates methods with algorithms
#include <cstring>
#include "Stack.h"

using namespace std;

Stack::Stack(){//constructor that sets head to null
  head = NULL;
}

Stack::~Stack(){//deconstructor
  Node* nextNode = head;//sets the nextnode to head
  while (head != NULL){//head is not null
    nextNode = head->getNext();
    delete head;//delete head
    head = nextNode;//next node = head
  }
}

Node* Stack::peek(){//looks at top node in stack and returns it
  return head;
}

void Stack::push(Node* newnode){//puts a node onto the stack
  newnode->setNext(head);//set head to be next after newnode
  head = newnode;//moce head
}

Node* Stack::pop(){////remove top node from a stack
  Node* popNode = head;
  head = popNode->getNext();
  return popNode;
}
