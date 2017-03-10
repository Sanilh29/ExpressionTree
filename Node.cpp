//Sanil Hattangadi, creates all the methods and returns variables for nodes
#include <cstring>
#include "Node.h"
using namespace std;

Node::Node(int input){//constructor
  datai = input;//set the int data as input
  next = NULL;
  type = 1;
}

Node::Node(char input){//char constructor
  datac = input;//sets the char data to input
  next = NULL;
  type = 2;
}

Node::~Node(){//deconstrctor by setting next to null
  next = NULL;
}

void Node::setNext(Node* newnode){//sets the next node
  next = newnode;
}

Node* Node::getNext(){//get the next node
  return next;
}

char Node::getDatac(){
  return datac;
}

int Node::getDatai(){
  return datai;
}

int Node::getType(){
  return type;
}
